#include "Command.h"

void DownloadResults::execute() {
    try {
        string line = this->dio->read();
        if (line == "invalid input"){
            return;
        }
        fstream f("classify.csv");
        if (!f) {                    //checking if the files were classified
            this->dio->write("please classify the data");
        }
        while (getline(f, line)) { // Iterates over the lines and send the server
            stringstream stream(line);
            this->dio->write(line);
        }
        this->dio->write("");
        f.close();
    }
    catch (exception e) {
        this->dio->write("invalid input");
    }
}

string DownloadResults::getDescription() {
    return this->description;
}
