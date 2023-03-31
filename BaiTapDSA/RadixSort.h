// RadixSort.h
#ifndef RADIXSORT_H
#define RADIXSORT_H
#include "SortAlgorithm.h"
#include <math.h>
class RadixSort : public SortAlgorithm {
    private:


    public:
// CONSTRUCTORS ----------------------------------------------------


// OTHER METHODS ---------------------------------------------------
        string getName() {
            return "Radix Sort";
        }
        
        // radix sort, using vector a, n, max_value, min_value from class,  sort byte by byte, and works with negative numbers
        void Sort() {
            // if there are negative numbers, shift all numbers to positive
            if (min_value < 0) {
                for (int i = 0; i < n; i++) {
                    a[i] -= min_value;
                }
                max_value -= min_value;
            }
            int max_digit = to_string(abs(max_value)).size();
            int base = 1;
            for (int i = 0; i < max_digit; i++) {
                vector<int> b(n);
                vector<int> c(10,0);
                for (int j = 0; j < n; j++) {
                    c[(a[j]/base)%10]++;
                }
                for (int j = 1; j < 10; j++) {
                    c[j] += c[j-1];
                }
                for (int j = n-1; j >= 0; j--) {
                    b[c[(a[j]/base)%10] - 1] = a[j];
                    c[(a[j]/base)%10]--;
                }
                a = b;
                base *= 10;
            }
            // if there are negative numbers, shift all numbers back to negative
            if (min_value < 0) {
                for (int i = 0; i < n; i++) {
                    a[i] += min_value;
                }
            }
        }


};

#endif