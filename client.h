#ifndef EX3_CLIENT_H
#define EX3_CLIENT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <thread>
#include "DefaultIO/DefaultIO.h"

/**
 * The function make sure that the user entered a valid port number.
 * @param port representing the port of the server
 * @return if the string is a valid port
 */
bool IsValidPort(const char **port);

/**
 * The function make sure that the ip from the user is valid
 * @param ip_address - ip from the user
 * @return - valid or not
 */
bool IsValidIp(const char **ip_address);

/**
 * this function uploads a file to the server, line vy line.
 * @param sockIO - socket IO
 * @param stdIO - standard IO
 */
void uploadFile(DefaultIO *sockIO, DefaultIO *stdIO);

/**
 * The function prints the classified vectors, that the server sent
 * @param sockIO - socket IO
 * @param stdIO - standard IO
 */
void displayResults(DefaultIO *sockIO, DefaultIO *stdIO);

/**
 * insert the information from the temporary vector to the file
 * @param path the file path
 * @param temp the temporary vector.
 */
void insertResults(const string &path, vector<string> temp);

/**
 * The function gets the classified vectors and insert them to a temporary vector
 * @param path the file path where we will keep the classified vectors
 * @param sockIO - the socket IO
 */
void downloadResults(const string &path, DefaultIO *sockIO);

int main(int argc, char *argv[]);

#endif
