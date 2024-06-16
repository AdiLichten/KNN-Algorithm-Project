#ifndef EX4_DEFAULTIO_H
#define EX4_DEFAULTIO_H

#include <string.h>
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace ::std;

class DefaultIO {
public:
    /**
     * getting the information from socket or from standard input
     * @return the string that received
     */
    virtual string read() = 0;

    /**
     * sending the information from socket or from standard input
     * @param str - the string that we sent/ write in stdIn
     */
    virtual void write(string str) = 0;

    ~DefaultIO() = default;
};

class StandardIO : public DefaultIO {
    string read() override;

    void write(string str) override;

};

class SocketIO : public DefaultIO {
private:
    int socketID;
public:
    explicit SocketIO(int socketId) : socketID(socketId) {};

    string read() override;

    void write(string str) override;
};


#endif
