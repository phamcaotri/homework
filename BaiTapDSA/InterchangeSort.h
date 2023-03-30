// InterchangeSort.h
#ifndef INTERCHANGESORT_H
#define INTERCHANGESORT_H
#include "SortAlgorithm.h"

class InterchangeSort : public SortAlgorithm {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------


// OTHER METHODS ---------------------------------------------------

        string getName() {
            return "Interchange Sort";
        }
        
        void Sort() {
            for (int i = 0; i < n-1 ; i++)
                for (int j = i+1; j < n; j++) 
                    if (a[i] > a[j])
                        swap(a[i],a[j]);
        }

};
#endif