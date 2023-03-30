// RadixSort.h
#ifndef RADIXSORT_H
#define RADIXSORT_H
#include "SortAlgorithm.h"

class RadixSort : public SortAlgorithm {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------
        using Draw::Draw; //inherit constructor

// OTHER METHODS ---------------------------------------------------
        string getName() {
            return "Radix Sort";
        }
        
        void Sort() {
            vector<vector<int>> b(10,vector<int> (n));
            int num_integer = size(to_string(max_value));
            for (int radix = 1; radix < pow(10,num_integer); radix *= 10) {
                vector<int> c(10,0);
                for (int i = 0; i < n; i++) {
                    int index = (a[i]/(radix))%10;
                    b[index][c[index]] = a[i];
                    c[index] ++;
                }
                int k = 0;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < c[i]; j++ ) {
                        a[k] = b[i][j];
                        k++;
                    }
                }
            }
        }
};

#endif