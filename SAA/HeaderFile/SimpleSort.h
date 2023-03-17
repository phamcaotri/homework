//SimpleSort.h
#ifndef SIMPLESORT_H // include guard
#define SIMPLESORT_H
#include "Draw.h"
class SimpleSort : public Draw {
    private:

    public:

        void Sort(int a[], int n) {
            for (int i = 0; i < n ; i++)
                for (int j = 0; j < n; j++)
                    if (a[i] < a[j])
                        swap(a[i],a[j]);
        }

        void SortAndDraw(int a[], int n) {
            for (int i = 0; i < n ; i++)
                for (int j = 0; j < n; j++) {
                    count_compare ++;
                    toDraw(a,n,i,j,-1);
                    if (a[i] < a[j]) {
                        count_swap ++;
                        swap(a[i],a[j]);
                        toDraw(a,n,i,j,-1);
                    }
                }

                        
        }
};

#endif

