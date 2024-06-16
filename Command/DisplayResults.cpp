#include "Command.h"

void DisplayResults::execute() {
    try {
        fstream f("classify.csv");
        if (!f) {                    //checking if the files were classified
            this->dio->write("please classify the data");
        }
        string line;
        while (getline(f, line)) { // Iterates over the lines and send the server
            stringstream stream(line);
            this->dio->write(line);
        }
        this->dio->write("Done.");
        this->dio->write("");
        f.close();
    }
    catch (exception e) {
        this->dio->write("invalid input");
    }
}

string DisplayResults::getDescription() {
    return this->description;
}
