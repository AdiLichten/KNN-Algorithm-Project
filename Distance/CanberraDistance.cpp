#include "Distance.h"

double CanberraDistance::CalculateDistance(vector<double> unclassified, vector<double> classified) {
    double dist = 0;
    for (int i = 0; i < unclassified.size(); i++) {
        if (abs(unclassified.at(i)) + abs(classified.at(i)) == 0) {
            cout << "Error! invalid input" << endl;
        }
        dist += (double) (abs(unclassified.at(i) - classified.at(i))) /
                (abs(unclassified.at(i)) + abs(classified.at(i)));
    }
    return dist;
}
