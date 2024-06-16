CC = g++
CFLAGS = -std=c++11

group1= server.cpp KNN.cpp CLI.cpp Command/AlgorithmSettings.cpp Command/ClassifyData.cpp \
		Command/DisplayResults.cpp Command/DownloadResults.cpp Command/Exit.cpp Command/UploadFile.cpp \
		DefaultIO/SocketIO.cpp DefaultIO/StandardIO.cpp Distance/CanberraDistance.cpp Distance/ChebyshevDistance.cpp \
		Distance/EuclideanDistance.cpp Distance/ManhattenDistance.cpp Distance/MinkowskiDistance.cpp

group2 = client.cpp KNN.cpp Command/AlgorithmSettings.cpp Command/ClassifyData.cpp Command/DisplayResults.cpp \
		 Command/DownloadResults.cpp Command/Exit.cpp Command/UploadFile.cpp DefaultIO/SocketIO.cpp \
		 DefaultIO/StandardIO.cpp Distance/CanberraDistance.cpp Distance/ChebyshevDistance.cpp \
		 Distance/EuclideanDistance.cpp Distance/ManhattenDistance.cpp Distance/MinkowskiDistance.cpp

OBJECT1 = $(group1:.cpp=.o)
OBJECT2 = $(group2:.cpp=.o)

EXECUTABLE1 = server.out
EXECUTABLE2 = client.out

all: $(EXECUTABLE1) $(EXECUTABLE2)

$(EXECUTABLE1): $(OBJECT1)
	$(CC) $(CFLAGS) $(OBJECT1) -o $(EXECUTABLE1) -pthread

$(EXECUTABLE2): $(OBJECT2)
	$(CC) $(CFLAGS) $(OBJECT2) -o $(EXECUTABLE2) -pthread

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT1) $(OBJECT2) $(EXECUTABLE1) $(EXECUTABLE2)
