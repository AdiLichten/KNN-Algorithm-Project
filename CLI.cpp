#include "CLI.h"


CLI::CLI(DefaultIO *dio) {
    this->dio = dio;
    // array of all the commands
    this->commandsArray[0] = new UploadFile(this->dio);
    this->commandsArray[1] = new AlgorithmSettings(this->dio);
    this->commandsArray[2] = new ClassifyData(this->dio);
    this->commandsArray[3] = new DisplayResults(this->dio);
    this->commandsArray[4] = new DownloadResults(this->dio);
    this->commandsArray[5] = new Exit(this->dio);
}

void CLI::start() {
    string userChoice = "0";
    do {
        string printMenu = "welcome to the KNN Classifier Server. Please Choose an option:\n";
        dio->write(printMenu + this->commandsArray[0]->getDescription() +
                   this->commandsArray[1]->getDescription() + this->commandsArray[2]->getDescription() +
                   this->commandsArray[3]->getDescription() + this->commandsArray[4]->getDescription() +
                   this->commandsArray[5]->getDescription());
        userChoice = this->dio->read();
        int userInputToInt = stoi(userChoice);
        if (userInputToInt >= 1 && userInputToInt <= 5) {
            this->commandsArray[userInputToInt - 1]->execute();
        }
    } while (userChoice != "8"); //while not 8 continue printing the menu and choose an option
}


CLI::~CLI() {
    for (int i = 0; i < 5; i++) {
        delete this->commandsArray[i];
    }
}