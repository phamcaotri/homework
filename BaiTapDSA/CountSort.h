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
            return "Count Sort";
        }
        
        void Sort() {
            vector<unsigned char> b(max_value, 0);
            for (int i = 0; i < n; i++) {
                b[a[i]-1] ++;
            }
            int j = 0;
            for (int i = 0; i < max_value; i++) {
                while (b[i] > 0) {
                    a[j] = i;
                    b[i] --;
                    j++;
                }
            }
        }

};


#endif