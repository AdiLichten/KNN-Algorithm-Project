#include "Command.h"


void AlgorithmSettings::execute() {
    try {
        bool validK = true;
        int k;
        string receive, validDist, token, send;
        KNN *knn = KNN::getInstance();
        this->dio->write("The current KNN parameters are: K = " + to_string(knn->getK()) + ", distance metric = " +
                         knn->getDistance());
        receive = this->dio->read();
        if (receive.empty()) {
            this->dio->write("continue");
            return;
        }
        stringstream stream(receive);
        getline(stream, token, ' '); // Separates the line
        for (int i = 0; i < token.length(); i++){
            if (!isdigit(token[i])){
                validK = false;
                send = "invalid value for K";
            }
        }
        if (validK){
            k = atoi(token.c_str());
        }
        getline(stream, token, '\n');
        validDist = knn->setDistance(token);
        if (validDist != "valid") {
            if (!validK) {
                send += " " +validDist;
                this->dio->write(send);
                return;
            }
            this->dio->write(validDist);
            return;
        }
        knn->setK(k);
        this->dio->write("continue");
    }
    catch (exception e) {
        this->dio->write("invalid input");
    }
}

string AlgorithmSettings::getDescription() {
    return this->description;
}
