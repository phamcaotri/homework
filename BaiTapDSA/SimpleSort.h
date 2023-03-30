//SimpleSort.h
#ifndef SIMPLESORT_H // include guard
#define SIMPLESORT_H
#include "Draw.h"
class SimpleSort : public Draw {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------
        using Draw::Draw; //inherit constructor

// OTHER METHODS ---------------------------------------------------
        string getName() {
            return "Simple Sort";
        }
        
        void Sort() {
            for (int i = 0; i < n ; i++)
                for (int j = 0; j < n; j++)
                    if (a[i] < a[j])
                        swap(a[i],a[j]);
        }

        void SortAndDraw() {
                                                            count_compare += 2;
            for (int i = 0; i < n ; i++)
                for (int j = 0; j < n; j++) {
                                                            count_compare += 3;
                                                            toDraw(i,j,-1);
                    if (a[i] < a[j]) {
                                                            count_swap ++;
                        swap(a[i],a[j]);
                                                            toDraw(i,j,-1);
                    }
                }

                        
        }
};

#endif

