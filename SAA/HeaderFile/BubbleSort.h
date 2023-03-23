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
            bool swapped = true;
            for (int i = 1; i < n and swapped ; i++) {
                swapped = false;
                for (int j = 0; j < n-i ; j++)
                    if (a[j] > a[j+1]) {
                        swap(a[j],a[j+1]);
                        swapped = true;
                    }

            }


        }

        void SortAndDraw() {
            bool swapped = true;                        
                                                        count_compare ++; //exit loop
            for (int i = 0; i < n-1 and swapped; i++) {
                swapped = false;
                                                        count_compare += 2; //exit loop + inside loop
                for (int j = 0; j < n-i-1; j++) {
                    
                                                        count_compare += 2; // inside loop + compare
                                                        toDraw(n-i,i,j);
                    if (a[j] > a[j+1]) {
                                                        count_swap ++;
                        swap(a[j],a[j+1]);
                        swapped = true;
                                                        toDraw(n-i,i,j);
                    }
                }
            }


                        
        }
};

#endif
