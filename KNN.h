#ifndef KNN_H
#define KNN_H

#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <map>
#include "Distance/Distance.h"

using namespace std;

// Creating a singleton class for the KNN algorithm
class KNN {
private:
    string distanceStr = "AUC";
    int k = 5;
    Distance *distance = new EuclideanDistance;
    static KNN *KNNInstance;

    KNN() {}

    KNN(const KNN &) = delete;

    KNN &operator=(const KNN &) = delete;

public:
    static KNN *getInstance();

    string getDistance();

    void setK(int value);

    int getK();

/**
 * the function checks if the number is a double.
 * @param s - string that should represent a valid double.
 * @return true if num is a double, false otherwise.
 */
    bool IsDouble(const string &s);

/**
 * the function sets a new vector according to the input. If the input is invalid the function
 * prints an error and closes the program.
 * @return vector of doubles.
 */
    vector<double> VectorScanner(const string &line);

/**
 * The function checks which strategy we want to use and returns a pointer to the correct distance strategy.
 * @param strategy - string representing the distance strategy
 * @return - pointer to the distance strategy
 */
    string setDistance(const string &strategy);

/**
 * The function finds the most common neighbor.
 * @param ClassifiedNeighbors - a map of k neighbors
 * @return - string representing the name of the most common neighbor.
 */
    static string MappingNeighbors(const map<pair<double, vector<double>>, string> &ClassifiedNeighbors);

/**
 * The function implement the knn algorithm
 * @param unclassified - the vector that need to be classified.
 * @param argc - the array length
 * @param argv - the main arguments
 * @return - the Map of the k neighbors
 */
    map<pair<double, vector<double>>, string> KNNAlgorithm(const vector<double> &unclassified);


/**
 * The function manages the KNN algorithm
 * @param sock - the information from the user
 * @param FileName - the file of the classified vectors.
 * @return string - most common neighbor (or "invalid input")
 */
    void addClassifiedVectors();

};

#endif
