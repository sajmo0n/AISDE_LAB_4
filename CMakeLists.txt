cmake_minimum_required(VERSION 3.10)
project(Kolejka)

set(CMAKE_CXX_STANDARD 11)

include_directories(src/headers)

add_executable(Kolejka
        src/headers/AbstractPriorityObject.h
        src/headers/AbstractPriorityQueue.h
        src/headers/AbstractQueue.h
        src/headers/BubbleQueue.h
        src/headers/HeapQueue.h
        src/headers/RandomGenerator.h
        src/headers/SelectionQueue.h
        src/headers/SimpleObject.h
        src/headers/SmartBubble.h
        src/headers/SmartDataTable.h
        src/headers/SmartHeap.h
        src/headers/SmartSelection.h
        src/headers/SmartQuicksort.h
        src/headers/SmartTable.h
        src/headers/SmartTournament.h
        src/headers/SmartInsertion.h
        src/headers/statistics.h
        src/headers/QuicksortQueue.h
        src/headers/TournamentQueue.h
        src/headers/InsertionQueue.h
        src/sources/main.cpp
        Makefile src/headers/Bucketsort.h src/headers/SmartBucketsort.h)
