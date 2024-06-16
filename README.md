# K-Nearest Neighbors (KNN) Algorithm Project

This project is a C++ implementation of the K-Nearest Neighbors (KNN) algorithm, one of the most common machine learning algorithms. 

## Project Overview

The KNN algorithm is used to classify new data points based on the classification of its nearest neighbors. In this project, I have created a server that communicates with multiple clients (maximum 5 clients) via sockets and threads. The server handles the client requests using a command pattern design.

The client can choose from the following options:

1. Upload an unclassified CSV data file
2. Algorithm settings
3. Classify data
4. Display results
5. Download results
6. Exit

The project also includes different distance metrics such as Euclidean, Manhattan, Chebyshev, Canberra, and Minkowski distances.
