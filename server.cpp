#include "server.h"

using namespace std;

bool IsValidPort(const char **port) {
    int port_num = atoi(*port);
    return port_num >= 1024 and port_num <= 65535;
}

void runANewClient(int client_sock) {
    DefaultIO *socketIO;
    socketIO = new SocketIO(client_sock);
    CLI *cli = new CLI(socketIO);
    cli->start();
}


int main(int argc, char *argv[]) {

    const char *port_no = argv[1];
    if (!IsValidPort(&port_no)) {
        perror("error! invalid port");
        return 1;
    }
    const int server_port = atoi(port_no);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        return 1;
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
        return 1;
    }
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
        return 1;
    }
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    while (true) {
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }
        thread thread(runANewClient, client_sock);
        thread.detach();
    }
}