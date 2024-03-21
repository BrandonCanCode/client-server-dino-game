/* game_client.c	
 * Brandon Evans
 * 
 * Credit to Brain "Breej" Hall for creating the majority of the code. I only
 * made modification to their existing programs.
*/

#include "game_client.h"


#define PORT "3490" // the port client will be connecting to 
#define HOSTNAME "localhost"
#define MAXDATASIZE 64

std::queue<char> incoming_queue;
std::queue<char> outgoing_queue;
std::mutex i_mtx;
std::mutex o_mtx;

int sockfd;

/* Used by game.cpp
 * Test without locks to prevent any blocking
*/
int PopIncomingQueue(char *input) 
{
    //std::unique_lock<std::mutex> lock(i_mtx);
	if (!incoming_queue.empty()) 
	{
		*input = incoming_queue.front();
		incoming_queue.pop();
		//lock.unlock(); // Unlock mutex before processing data
		return 1;
	} 
	else 
	{
		//lock.unlock();
		return 0;
	}
}

void PushIncomingQueue(char value)
{
    //std::unique_lock<std::mutex> lock(i_mtx);
	incoming_queue.push(value);
	//lock.unlock();
}

void PushOutgoingQueue(char value)
{
	outgoing_queue.push(value);
}

int PopOutgoingQueue(char *value) 
{
    //std::unique_lock<std::mutex> lock(i_mtx);
	if (outgoing_queue.empty())
		return 0;
	
	*value = outgoing_queue.front();
	outgoing_queue.pop();
	//lock.unlock(); // Unlock mutex before processing data
	return 1;
}



// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) 
	{
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}
	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

void sigHandle(int sig)
{
	if (sig == SIGINT || sig == SIGKILL || sig == SIGTERM)
	{
		//Close and return
		close(sockfd);
	}
}

void RunTCPClient()
{ 
	int numbytes;
	struct addrinfo hints, *servinfo, *p;
	int rv;
	char s[INET6_ADDRSTRLEN];
	char data;
	char recv_buff[MAXDATASIZE] = {'1'};

    mvwprintw(main_wnd, 25, 0, "Starting TCP Client");

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if ((rv = getaddrinfo(HOSTNAME, PORT, &hints, &servinfo)) != 0) 
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return;
	}

	// loop through all the results and connect to the first we can
	for(p = servinfo; p != NULL; p = p->ai_next) 
	{
		if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) 
		{
			perror("client: socket");
			continue;
		}

		if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) 
		{
			perror("client: connect");
			close(sockfd);
			continue;
		}

		break;
	}

	if (p == NULL) {
		fprintf(stderr, "client: failed to connect\n");
		return;
	}

	inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr), s, sizeof s);
    mvwprintw(main_wnd, 25, 0, "Client: connecting to %s\n", s);

	freeaddrinfo(servinfo); // all done with this structure
	
	while(recv_buff[0] != 'q')
	{
		//Send Data
		//Check for data
		if(PopOutgoingQueue(&data))
		{
    		//mvwprintw(game_wnd, 1, 0, "Sending %c to server\n", data);
			if (send(sockfd, &data, 1, 0) == -1)
				perror("send");

			
			//Recv Data
			if ((numbytes = recv(sockfd, &recv_buff, MAXDATASIZE, 0)) == -1) 
			{
				perror("recv");
				exit(1);
			}
    		mvwprintw(main_wnd, 40, 0, "Client received: %c (%d)",data, numbytes);

			if (numbytes > 0)
				PushIncomingQueue(recv_buff[0]);
		}
	}

	mvwprintw(main_wnd, 25, 0, "Closing client thread!         ");
	mvwprintw(main_wnd, 25, 0, "                               ");
	return;
}



