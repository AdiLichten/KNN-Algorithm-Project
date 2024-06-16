#ifndef ADVANCED_PROGRAMMING_EX3_SERVER_H
#define ADVANCED_PROGRAMMING_EX3_SERVER_H

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <thread>
#include "KNN.h"
#include "DefaultIO/DefaultIO.h"
#include "CLI.h"

/**
 * The function make sure that the user entered a valid port number.
 * @param port representing the port of the server
 * @return if the string is a valid port
 */
bool IsValidPort(const char **port);

/**
 * The function opens a new thread for each client connected
 * @param client_sock - the client socket id.
 */
void runANewClient(int client_sock);

int main(int argc, char *argv[]);

#endif