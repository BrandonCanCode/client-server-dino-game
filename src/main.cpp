#include "game.h"
#include "player.h"
#include <string.h>

char *HOSTNAME;

int main(int argc, char **argv) {
	int max_score = 0;

	if (argc != 2)
	{
		printf("Invalid number of input argument %d!=2\n", argc);
		printf("Usage: ./dinosaur_game <IP4-address>\n");
		return 1;
	}
	else
	{
		int length = strlen(argv[1]);
		if (length < 9)
		{
			printf("IP address too small\n");
			return 1;
		}

		HOSTNAME = (char*)calloc(sizeof(char), length);
		strcpy(HOSTNAME, argv[1]);
	}

	while (1) {
		int init_status = init();

		if (init_status == 0) {
			if (run(max_score)) { // end game after game over
				break;
			}
		}
	}

	close();

	return 0;
}
