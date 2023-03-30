//ShakeSort.h
#ifndef SHAKESORT_H // include guard
#define SHAKESORT_H
#include "SortAlgorithm.h"
class ShakeSort : public SortAlgorithm {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------


        string getName() {
            return "Shake Sort";
        }
        
        void Sort() {
            bool swapped;

            for (int i = 0; i < n/2 ; i++) {
                swapped = false;
                for (int j = i; j < n-i-1; j++) {
                    
                    if (a[j] > a[j+1]) {
                        swap(a[j],a[j+1]);
                        swapped = true;
                    }
                }


                for (int j = n-i-1 ; j > i ; j--) {
                    if (a[j] < a[j-1]) {
                        swap(a[j],a[j-1]);
                        swapped = true;
                    }
                }
                if (not swapped)
                    break;

            }


        }

};

#endif

