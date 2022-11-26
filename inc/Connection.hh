#ifndef CONNECTION
#define CONNECTION

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>

#include "Port.hh"

bool OpenConnection(int &rSocket);
int Send(int Sk2Server, const char *sMesg);

#endif