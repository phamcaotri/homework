// SortList.h
#ifndef SORTLIST_H
#define SORTLIST_H
#include "SortIndex.h"
#include "ArrayFunction.h"
class SortList {
private:
    vector<void*> algorithms;
public:
    void addAlgorithm(void* algorithm) {
        algorithms.push_back(algorithm);
    }
    void runAllAlgorithms(int n) {
        for (auto algorithm : algorithms) {
            algorithm->setN(n);
            algorithm->createTestArray();
            algorithm->measureTime();
            algorithm->isSorted();
        }
    }
};

#endif