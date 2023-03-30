//SelectionSort.h
#ifndef SELECTIONSORT_H// include guard
#define SELECTIONSORT_H
#include "SortAlgorithm.h"
class SelectionSort : public SortAlgorithm {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------


// OTHER METHODS ---------------------------------------------------
        string getName() {
            return "Selection Sort";
        }
        
        void Sort() {
            for (int i = 0; i < n - 1; i++) {
                int min = i;
                for (int j = i+1; j < n; j++) {
                    
                    if (a[min] > a[j])
                        min = j;   
                }
                swap(a[i],a[min]);

            }


        }

};

#endif

