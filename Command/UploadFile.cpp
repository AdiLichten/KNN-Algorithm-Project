#include "Command.h"

void UploadFile::execute() {
    try {
        this->dio->write("Please upload your local train CSV file.");
        string line = this->dio->read();
        if (line == "invalid input"){
            return;
        }
        fstream f("train.csv", fstream::out | fstream::app);
        while (!line.empty()) {
            f << line << endl;
            line.clear();
            line = this->dio->read();
        }
        f.close();
        this->dio->write("Upload complete.\nPlease upload your local test CSV file.");
        fstream t("test.csv", fstream::out | fstream::app);
        line.clear();
        line = this->dio->read();
        if (line == "invalid input"){
            return;
        }
        while (!line.empty()) {
            t << line << endl;
            line.clear();
            line = this->dio->read();
        }
        t.close();
        this->dio->write("Upload complete.");
    }
    catch (exception e) {
        this->dio->write("invalid input");
    }
}

string UploadFile::getDescription() {
    return this->description;
}