#include "Distance.h"


double MinkowskiDistance::CalculateDistance(vector<double> unclassified, vector<double> classified) {
    double dist = 0;
    for (int i = 0; i < unclassified.size(); i++) {
        dist += (double) pow(abs(unclassified.at(i) - classified.at(i)), p);
    }
    return pow(dist, 1 / p);
}
