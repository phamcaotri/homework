//SelectionSort.h
#ifndef SELECTIONSORT_H// include guard
#define SELECTIONSORT_H
#include "Draw.h"
class SelectionSort : public Draw {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------
        using Draw::Draw; //inherit constructor

// OTHER METHODS ---------------------------------------------------

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

        void SortAndDraw() {
                                                                count_compare += 2;
            for (int i = 0; i < n - 1; i++) {
                int min = i;
                for (int j = i+1; j < n; j++) {
                                                                count_compare += 3;
                                                                toDraw(i,j,-1);
                    if (a[min] > a[j])
                        min = j;
                        
                }
                                                                count_swap ++;
                swap(a[i],a[min]);
                                                                toDraw(i,-1,-1);
            }


        }


};

#endif

