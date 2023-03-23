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
            for (int i = 1; i < n ; i++)
                for (int j = i; j > 0; j--)
                    if (a[j] < a[j-1])
                        swap(a[j],a[j-1]);
                    else break;
        }

        void SortAndDraw() {
            count_compare += 2;
            for (int i = 1; i < n ; i++)
                for (int j = i; j > 0; j--) {
                    count_compare += 3;
                    toDraw(i,j,-1);
                    if (a[j] < a[j-1]) {
                        count_swap ++;
                        swap(a[j],a[j-1]);
                        toDraw(i,j,-1);
                    }
                    else break;
                }

                        
        }


};

#endif

