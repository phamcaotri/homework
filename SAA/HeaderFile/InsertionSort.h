//InsertionSort.h
#ifndef INSERTIONSORT_H // include guard
#define INSERTIONSORT_H
#include "Draw.h"
class InsertionSort : public Draw {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------
        using Draw::Draw;

// OTHER METHODS ---------------------------------------------------

        void Sort() {
            for (int i = 0; i < n-1 ; i++)
                for (int j = 0; j < n-i-1; j++)
                    if (a[j] > a[j+1])
                        swap(a[j],a[j+1]);
        }

        void SortAndDraw() {
            for (int i = 0; i < n-1 ; i++)
                for (int j = 0; j < n-i-1; j++) {
                    count_compare ++;
                    toDraw(n-i-1,i,j);
                    if (a[j] > a[j+1]) {
                        count_swap ++;
                        swap(a[j],a[j+1]);
                        toDraw(n-i-1,i,j);
                    }
                }

                        
        }
};

#endif

