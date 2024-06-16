#include "DefaultIO.h"

string StandardIO::read() {
    string input;
    getline(cin, input);
    return input;
}

void StandardIO::write(string str) {
    cout << str << endl;
}

