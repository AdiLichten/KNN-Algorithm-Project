#include "KNN.h"

using namespace std;

bool KNN::IsDouble(const string &s) {
    double num;
    return ((istringstream(s) >> num >> ws).eof());
}

vector<double> KNN::VectorScanner(const string &line) {
    vector<double> v;
    string token;
    try {
        stringstream s(line);
        while (getline(s, token, ',')) { // Separates the line
            if (!IsDouble(token)) {
                v.clear();
                return v;
            }
            v.push_back(stod(token));
            token.clear();
        }
        return v;
    }
    catch (exception exception) {
        v.clear();
        return v;
    }
}

string KNN::setDistance(const string &strategy) {
    if (strategy == "AUC") {
        this->distance = new EuclideanDistance();
        this->distanceStr = strategy;
        return "valid";
    }
    if (strategy == "MAN") {
        this->distance = new ManhattenDistance;
        this->distanceStr = strategy;
        return "valid";
    }
    if (strategy == "CHB") {
        this->distance = new ChebyshevDistance;
        this->distanceStr = strategy;
        return "valid";
    }
    if (strategy == "CAN") {
        this->distance = new CanberraDistance;
        this->distanceStr = strategy;
        return "valid";
    }
    if (strategy == "MIN") {
        this->distance = new MinkowskiDistance;
        this->distanceStr = strategy;
        return "valid";
    }
    return "invalid value for metric";
}

string KNN::MappingNeighbors(const map<pair<double, vector<double>>, string> &ClassifiedNeighbors) {
    map<string, int> nameCount; // Create a map to count the number of occurrences of each name
    for (const auto &element: ClassifiedNeighbors) { // Iterate over the elements of the map
        ++nameCount[element.second]; // Increment the count for the current name
    }
    int maxCount = 0;
    string MostCommon;
    for (const auto &element: nameCount) {// Iterate over the elements of the map
        const auto &name = element.first;
        const auto &count = element.second;
        if (count > maxCount) {
            maxCount = count; // Find the name with the maximum count
            MostCommon = name;
        }
    }
    return MostCommon;
}

map<pair<double, vector<double>>, string> KNN::KNNAlgorithm(const vector<double> &unclassified) {
    string line, token;
    fstream s("train.csv");
    map<pair<double, vector<double>>, string> ClassifiedNeighbors;
    try {
        int KNeighbors = this->k; // Setting the number of neighbors.
        if (!KNeighbors) { // Invalid input
            return ClassifiedNeighbors;
        }
        if (!this->distance) {// Invalid input
            return ClassifiedNeighbors;
        }
        if (!s.is_open()) {
            cout << "Error opening file" << endl;
            exit(1);
        }
        while (getline(s, line)) { // Iterates over the lines
            stringstream stream(line);
            vector<string> TokensVector;
            while (getline(stream, token, ',')) { // Separates each line
                TokensVector.push_back(token); // Adding the strings to a vector
            }
            vector<double> classified;
            for (int i = 0; i < TokensVector.size() - 1; i++) { // Iterates only the vector values
                if (!IsDouble(TokensVector.at(i))) {
                    ClassifiedNeighbors.clear();
                    return ClassifiedNeighbors;
                }
                classified.push_back(stod(TokensVector.at(i))); // Changes the string to double.
            }
            if (classified.size() != unclassified.size()) { // Makes sure the vectors are the same length.
                ClassifiedNeighbors.clear();
                return ClassifiedNeighbors;
            }
            double CurrentDistance = this->distance->CalculateDistance(unclassified, classified);
            pair<double, vector<double>> key = {CurrentDistance, classified};
            // Now it inserts the pair and the name of the neighbor to the ClassifiedNeighbors map.
            // Pay attention that the map is sorted based on the first element of the pair key, which is a distance
            // value, in ascending order.
            ClassifiedNeighbors[key] = TokensVector.at(TokensVector.size() - 1);
            // If a neighbor was added, and we have found out that there are more than k neighbors in the map, we need
            // to erase the last neighbor, because he is not relevant anymore.
            if (ClassifiedNeighbors.size() > KNeighbors) { //
                ClassifiedNeighbors.erase(--ClassifiedNeighbors.end());
            }
        }
        s.close();  // Close the file
        return ClassifiedNeighbors;
    }
    catch (exception e) {
        ClassifiedNeighbors.clear();
        return ClassifiedNeighbors;
    }
}

void KNN::addClassifiedVectors() {
    try {
        string line;
        int rowNumber = 1;
        fstream classify("classify.csv"); // Creating the file for the classified vectors.
        classify.open("classify.csv", fstream::out | fstream::app);
        fstream f("test.csv");
        while (getline(f, line)) { // Iterates over the lines
            stringstream stream(line);
            vector<double> unclassified = VectorScanner(line);
            string ComNeighbor;
            if (unclassified.empty()) {
                return;
            }
            map<pair<double, vector<double>>, string> ClassifiedNeighbors;
            ClassifiedNeighbors = KNNAlgorithm(unclassified);
            if (ClassifiedNeighbors.empty()) {
                return;
            }
            ComNeighbor = MappingNeighbors(ClassifiedNeighbors); // Prints the name of the most common neighbor.
            classify << to_string((rowNumber)) + " " + ComNeighbor << endl;
            rowNumber++;
        }
        classify.close();
        f.close();
    }
    catch (exception e) {
        return;
    }
}

KNN *KNN::getInstance() {
    if (!KNNInstance) {
        KNNInstance = new KNN();
    }
    return KNNInstance;
}

KNN *KNN::KNNInstance = nullptr;

void KNN::setK(int value) {
    this->k = value;
}

int KNN::getK() {
    return this->k;
}

string KNN::getDistance() {
    return this->distanceStr;
}

