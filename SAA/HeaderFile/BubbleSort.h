//BubbleSort.h
#ifndef BUBBLESORT_H // include guard
#define BUBBLESORT_H
#include "Draw.h"
class BubbleSort : public Draw {
    private:

    public:

        void Sort(int a[], int n) {
            for (int i = 0; i < n ; i++)
                for (int j = 0; j < n-i-1; j++)
                    if (a[j] > a[j+1])
                        swap(a[j],a[j+1]);
        }

        void SortAndDraw(int a[], int n) {
            for (int i = 0; i < n ; i++)
                for (int j = 0; j < n-i-1; j++)
                    if (a[j] > a[j+1]) {
                        count_compare ++;
                        count_swap ++;
                        swap(a[j],a[j+1]);
                        toDraw(a,n,n-i-1,i,j);
                    }
                        
        }
};

#endif

