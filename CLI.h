#ifndef CLIh
#define CLIh

#include <string.h>
#include "Command/Command.h"

using namespace std;

class CLI {
    DefaultIO *dio;
    Command *commandsArray[6];
public:
    /**
     * Constructor
     * @param dio - type of IO for this connection - in this case it will always be socketIO
     */
    explicit CLI(DefaultIO *dio);

    /**
     * The function running in a loop till the client close the socket.
     */
    void start();

    /**
     * destructor
     */
    virtual ~CLI();
};

#endif