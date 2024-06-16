cmake_minimum_required(VERSION 3.17)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(server
        Distance/CanberraDistance.cpp
        Distance/ChebyshevDistance.cpp
        Distance/Distance.h
        Distance/EuclideanDistance.cpp
        KNN.cpp
        KNN.h
        Distance/ManhattenDistance.cpp
        Distance/MinkowskiDistance.cpp
        server.cpp
        server.h
        DefaultIO/StandardIO.cpp
        Command/Command.h
        DefaultIO/SocketIO.cpp Command/UploadFile.cpp CLI.cpp CLI.h CLI.h Command/AlgorithmSettings.cpp Command/ClassifyData.cpp Command/DisplayResults.cpp Command/DownloadResults.cpp Command/Exit.cpp)

add_executable(client
        client.cpp
        client.h
        DefaultIO/StandardIO.cpp
        Command/Command.h
        DefaultIO/SocketIO.cpp)
