// InterchangeSort.h
#ifndef INTERCHANGESORT_H
#define INTERCHANGESORT_H
#include "Draw.h"

class InterchangeSort : public Draw {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------
        using Draw::Draw; //inherit constructor

// OTHER METHODS ---------------------------------------------------


        void Sort() {
            for (int i = 0; i < n-1 ; i++)
                for (int j = i+1; j < n; j++) 
                    if (a[i] > a[j])
                        swap(a[i],a[j]);
        }

        void SortAndDraw() {
            count_swap +=2;
            for (int i = 0; i < n-1 ; i++)
                for (int j = i+1; j < n; j++) {
                    count_swap += 3;
                    if (a[i] > a[j]) {
                        swap(a[i],a[j]);
                    }
                    toDraw(i,j,-1);
                } 


        }
};
#endif