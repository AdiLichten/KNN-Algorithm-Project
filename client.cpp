#include <vector>
#include "client.h"

using namespace std;

bool IsValidPort(const char **port) {
    int port_num = atoi(*port);
    return port_num >= 1024 and port_num <= 65535;
}

bool IsValidIp(const char **ip_address) {
    struct in_addr addr;
    int result = inet_pton(AF_INET, *ip_address, &addr); // convert the string to a binary representation
    return result == 1; // return true if the conversion was successful
}

void uploadFile(DefaultIO *sockIO, DefaultIO *stdIO) {
    string receive, send, fileName, line;
    sockIO->write("1");
    receive = sockIO->read();
    stdIO->write(receive);
    fileName = stdIO->read();
    fstream f(fileName);
    if (!f.is_open()) {
        stdIO->write("invalid input");
        sockIO->write("invalid input");
        return;
    }
    while (getline(f, line)) { // Iterates over the lines and send the server
        stringstream stream(line);
        sockIO->write(line);
    }
    sockIO->write("");
    receive = sockIO->read();
    stdIO->write(receive);
    fileName.clear();
    fileName = stdIO->read();
    fstream t(fileName);
    if (!t.is_open()) {
        stdIO->write("invalid input");
        sockIO->write("invalid input");
        return;
    }
    while (getline(t, line)) { // Iterates over the lines and send the server
        stringstream stream(line);
        sockIO->write(line);
    }
    sockIO->write("");
    receive = sockIO->read();
    stdIO->write(receive);
}

void displayResults(DefaultIO *sockIO, DefaultIO *stdIO) {
    string receive, send, fileName, line;
    sockIO->write("4");
    line = sockIO->read();
    while (!line.empty()) {
        stdIO->write(line);
        line.clear();
        line = sockIO->read();
    }
}

void insertResults(const string &path, vector<string> temp) {
    fstream f(path, fstream::out | fstream::app);
    for (int i = 0; i < temp.size(); i++) {
        f << temp.at(i) << endl;
    }
    f.close();
}

void downloadResults(const string &path, DefaultIO *sockIO) {
    vector<string> temp;
    string line;
    line = sockIO->read();
    while (!line.empty()) {
        temp.push_back(line);
        line.clear();
        line = sockIO->read();
    }
    thread th(insertResults, path, temp);
    th.detach();
}

int main(int argc, char *argv[]) {
    const char *ip_address = argv[1];
    if (!IsValidIp(&ip_address)) {
        perror("error! invalid ip address");
        return 1;
    }
    const char *port_no = argv[2];
    if (!IsValidPort(&port_no)) {
        perror("error! invalid port");
        return 1;
    }
    const int port = atoi(port_no);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        return 1;
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
        return 1;
    }
    DefaultIO *sockIO = new SocketIO(sock);
    DefaultIO *stdIO = new StandardIO;
    int choice;
    do {
        string str = sockIO->read(); //prints menu
        cout << str;
        try {
            choice = stoi(stdIO->read());
        }
        catch (exception e) {
            cout << "invalid input" << endl;
            close(sock);
            return 0;
        }
        switch (choice) {
            case 1: {
                uploadFile(sockIO, stdIO);
                break;
            }
            case 2: {
                sockIO->write("2");
                str = sockIO->read();
                stdIO->write(str);
                str = stdIO->read();
                sockIO->write(str);
                str = sockIO->read();
                if (str != "continue") {
                    stdIO->write(str);
                }
                break;
            }
            case 3: {
                sockIO->write("3");
                str = sockIO->read();
                stdIO->write(str);
                break;
            }
            case 4: {
                displayResults(sockIO, stdIO);
                break;
            }
            case 5: {
                string path, line;
                sockIO->write("5");
                path = stdIO->read();
                fstream f(path, fstream::out | fstream::app);
                if (!f.is_open()) {
                    stdIO->write("invalid path");
                    sockIO->write("invalid input");
                    break;
                }
                f.close();
                sockIO->write("continue");
                downloadResults(path, sockIO);
                break;
            }
            case 8: {
                sockIO->write("8");
                close(sock);
                return 0;
            }
            default: {
                cout << "invalid input" << endl;
                break;
            }
        }
    } while (true);
}