#include "DefaultIO.h"

string SocketIO::read() {
    char buffer[4096];
    memset(buffer, 0, sizeof(buffer));
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(this->socketID, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        return "";
    } else if (read_bytes < 0) {
        perror("connection failed");
        close(this->socketID);
    }
    return buffer;
}

void SocketIO::write(string str) {
    char buffer[4096];
    memset(buffer, 0, sizeof(buffer));
    str.copy(buffer, sizeof(buffer));
    int sent_bytes = send(this->socketID, buffer, sizeof(buffer), 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
        close(this->socketID);
    }
}
