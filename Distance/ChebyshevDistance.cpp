#include "Distance.h"

double ChebyshevDistance::CalculateDistance(vector<double> unclassified, vector<double> classified) {
    double dist = 0;
    for (int i = 0; i < unclassified.size(); i++) {
        if (dist < (double) abs(unclassified.at(i) - classified.at(i))) {
            dist = (double) abs(unclassified.at(i) - classified.at(i));
        }
    }
    return dist;
}
