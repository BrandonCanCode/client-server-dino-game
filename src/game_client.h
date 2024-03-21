#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>

int GetServerInput(char *input);
void AddToOutgoingQueue(char value);