#include "Distance.h"

double ManhattenDistance::CalculateDistance(vector<double> unclassified, vector<double> classified) {
    double dist = 0;
    for (int i = 0; i < unclassified.size(); i++) {
        dist += (double) abs(unclassified.at(i) - classified.at(i));
    }
    return dist;
}
