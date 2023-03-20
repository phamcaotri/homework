//BubbleSort.h
#ifndef BUBBLESORT_H // include guard
#define BUBBLESORT_H
#include "Draw.h"
class BubbleSort : public Draw {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------
        using Draw::Draw; //inherit constructor

// OTHER METHODS ---------------------------------------------------

        void Sort() {
            for (int i = 0; i < n-1 ; i++)
                for (int j = 0; j < n-i-1; j++)
                    if (a[j] > a[j+1])
                        swap(a[j],a[j+1]);
        }

        void SortAndDraw() {
            count_compare += 2;
            for (int i = 0; i < n-1 ; i++)
                for (int j = 0; j < n-i-1; j++) {
                    count_compare += 3;
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

