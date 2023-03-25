//InsertionSort2.h
#ifndef INSERTIONSORT2_H // include guard
#define INSERTIONSORT2_H
#include "Draw.h"
class InsertionSort2 : public Draw {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------
        using Draw::Draw;

// OTHER METHODS ---------------------------------------------------

        void Sort() {
            for (int i = 1; i < n ; i++) {
                int j = i-1;
                int x = a[i];
                for (; j >= 0 and x < a[j]; j--) {
                    a[j+1] = a[j];
                }
                a[j+1] = x;
            }


        }


        void SortAndDraw() {
                                                        count_compare ++;
            for (int i = 1; i < n ; i++) {                   
                int j = i-1;
                int x = a[i];
                                                        count_access_array ++;
                                                        toDraw(i,j,-1);
                                                        count_compare += 2;
                for (; j >= 0 and x < a[j]; j--) {
                                                        toDraw(i,j,-1);
                                                        count_compare +=2;
                        a[j+1] = a[j];
                                                        toDraw(i,j,-1);
                }
                a[j+1] = x;
                                                        toDraw(i,j,-1);
                }                                               
        }

};

#endif
