#include "Command.h"

void ClassifyData::execute() {
    try {
        ifstream train;
        train.open("train.csv"); //checking that the file exists
        if (!train) {
            this->dio->write("please upload data");
            return;
        }
        ifstream test;
        test.open("test.csv"); //checking that the file exists
        if (!train) {
            this->dio->write("please upload data");
            return;
        }
        ifstream classify;
        classify.open("classify.csv");
        if (classify) {
            remove("classify.csv");
        }
        KNN *knn = KNN::getInstance();
        knn->addClassifiedVectors();
        this->dio->write("classifying data complete");
    }
    catch (exception e) {
        this->dio->write("invalid input");
    }
}

string ClassifyData::getDescription() {
    return this->description;
}
