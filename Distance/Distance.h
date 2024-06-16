#ifndef DISTANCE_H
#define DISTANCE_H

#include <vector>
#include <cmath>
#include <iostream>
#define p (double)2

using namespace std;

class Distance {
public:
    // abstract function to calculate the distance
    virtual double CalculateDistance(vector<double> unclassified, vector<double> classified) = 0;

    // virtual destructor to ensure correct destruction of derived objects
    virtual ~Distance() = default;
};

class CanberraDistance : public Distance {
    /**
    * the function calculates the Canberra distance of 2 vectors.
    * @param unclassified - the first vector.
    * @param classified - the second vector.
    * @return double representing the distance.
    */
    double CalculateDistance(vector<double> unclassified, vector<double> classified) override;
};

class ChebyshevDistance : public Distance {
    /**
    * the function calculates the chebyshev distance of 2 vectors.
    * @param unclassified - the first vector.
    * @param classified - the second vector.
    * @return double representing the distance.
    */
    double CalculateDistance(vector<double> unclassified, vector<double> classified) override;
};

class EuclideanDistance : public Distance {
    /**
     * the function calculates the euclidean distance of 2 vectors.
     * @param unclassified - the first vector.
     * @param classified - the second vector.
     * @return double representing the distance.
     */
    double CalculateDistance(vector<double> unclassified, vector<double> classified) override;
};

class ManhattenDistance : public Distance {
    /**
    * the function calculates the manhatten distance of 2 vectors.
    * @param unclassified - the first vector.
    * @param classified - the second vector.
    * @return double representing the distance.
    */
    double CalculateDistance(vector<double> unclassified, vector<double> classified) override;
};

class MinkowskiDistance : public Distance {
    /**
    * the function calculates the minkowski distance of 2 vectors.
    * @param unclassified - the first vector.
    * @param classified - the second vector.
    * @return double representing the distance.
    */
    double CalculateDistance(vector<double> unclassified, vector<double> classified) override;
};


#endif
