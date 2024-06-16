#ifndef EX4_COMMAND_H
#define EX4_COMMAND_H

#include <string>
#include <fstream>
#include "../DefaultIO/DefaultIO.h"
#include "../KNN.h"

using namespace std;

class Command {
protected:
    DefaultIO *dio;
    string description;
public:
    /**
     * Constructor
     * @param dio - socketIO
     * @param description - the description of the command
     */
    Command(DefaultIO *dio, string description) : dio(dio), description(description) {}

    virtual void execute() = 0;

    virtual string getDescription() = 0;

    virtual ~Command() = default;
};

class UploadFile : public Command {
public:
    explicit UploadFile(DefaultIO *dio) : Command(dio, "1. upload an unclassified csv data file\n") {};

    void execute() override;

    string getDescription() override;
};

class AlgorithmSettings : public Command {
public:
    explicit AlgorithmSettings(DefaultIO *dio) : Command(dio, "2. algorithm settings\n") {};

    void execute() override;

    string getDescription() override;
};

class ClassifyData : public Command {
public:
    explicit ClassifyData(DefaultIO *dio) : Command(dio, "3. classify data\n") {};

    void execute() override;

    string getDescription() override;
};

class DisplayResults : public Command {
public:
    explicit DisplayResults(DefaultIO *dio) : Command(dio, "4. display results\n") {};

    void execute() override;

    string getDescription() override;
};

class DownloadResults : public Command {
public:
    explicit DownloadResults(DefaultIO *dio) : Command(dio, "5. download results\n") {};

    void execute() override;

    string getDescription() override;

};

class Exit : public Command {
public:
    explicit Exit(DefaultIO *dio) : Command(dio, "8. exit\n") {};

    void execute() override;

    string getDescription() override;
};

#endif
