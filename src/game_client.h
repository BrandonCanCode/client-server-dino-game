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
#include <ncurses.h>

void RunTCPClient();
int PopIncomingQueue(char *input);
int PopOutgoingQueue(char *value);
void PushIncomingQueue(char value);
void PushOutgoingQueue(char value);

extern WINDOW *main_wnd;