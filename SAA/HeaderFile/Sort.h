// Sort.h
#ifndef SORT_H
#define SORT_H
#include <iostream>

class Sort {
    protected:
        int count_compare = 0;
        int count_swap = 0;

    public:
        int getNumberOfCompare() {
            return count_compare;
        }
        int getNumberOfSwap() {
            return count_swap;
        }
};

#endif