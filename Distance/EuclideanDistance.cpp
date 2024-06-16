#include "Distance.h"

double EuclideanDistance::CalculateDistance(vector<double> unclassified, vector<double> classified) {
    double dist = 0;
    for (int i = 0; i < unclassified.size(); i++) {
        dist += (double) pow(abs(unclassified.at(i) - classified.at(i)), 2);
    }
    return sqrt(dist);
}