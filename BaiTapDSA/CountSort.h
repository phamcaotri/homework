// CountSort.h
#ifndef COUNTSORT_H
#define COUNTSORT_H

#include "SortAlgorithm.h"
class CountSort : public SortAlgorithm {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------


// OTHER METHODS ---------------------------------------------------
        string getName() {
            return "Counting Sort";
        }
        
        void Sort() {
            // if there are negative numbers, shift all numbers to positive
            if (min_value < 0) {
                for (int i = 0; i < n; i++) {
                    a[i] -= min_value;
                }
                max_value -= min_value;
            }
            vector<int> b(n);
            vector<int> c(max_value+1,0);
            for (int i = 0; i < n; i++) {
                c[a[i]]++;
            }
            for (int i = 1; i <= max_value; i++) {
                c[i] += c[i-1];
            }
            for (int i = n-1; i >= 0; i--) {
                b[c[a[i]] - 1] = a[i];
                c[a[i]]--;
            }
            a = b;
            // if there are negative numbers, shift all numbers back to negative
            if (min_value < 0) {
                for (int i = 0; i < n; i++) {
                    a[i] += min_value;
                }
            }
        }

    

};


#endif