//InsertionSort2.h
#ifndef INSERTIONSORT2_H // include guard
#define INSERTIONSORT2_H
#include "SortAlgorithm.h"

// dùng phương pháp shift
class InsertionSort2 : public SortAlgorithm {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------


// OTHER METHODS ---------------------------------------------------
        string getName() {
            return "Insertion Sort with shift";
        }

        void Sort() {
            for (int i = 1; i < n ; i++) {
                int j = i-1;
                int x = a[i];
                for (; j >= 0 and x < a[j]; j--) {
                    a[j+1] = a[j];
                }
                a[j+1] = x;
            }


        }


};

#endif
