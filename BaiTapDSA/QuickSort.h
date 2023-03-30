//QuickSort.h
#ifndef QUICKSORT_H // include guard
#define QUICKSORT_H

#include "SortAlgorithm.h"

class QuickSort : public SortAlgorithm {
    public:
// CONSTRUCTORS ----------------------------------------------------
        using Draw::Draw; //inherit constructor

// OTHER METHODS ---------------------------------------------------
        string getName() {
            return "Quick Sort";
        }
        
        void Sort(int left, int right) {
            int pivot = (left+right)/2;
            int mid = a[pivot];
            int i = left, j = right;
            while (i <= j) {
                while (a[i] < mid) {
                    i ++;
                }

                while (a[j] > mid) {
                    j --;  
                }

                if (i <= j) {
                    swap(a[i], a[j]);
                    i ++; 
                    j --;
                }
            }
            if (left < j) Sort(left,j);
            if (right > i) Sort(i,right);
        }
};


#endif

