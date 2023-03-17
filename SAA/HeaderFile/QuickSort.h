//QuickSort.h
#ifndef QUICKSORT_H // include guard
#define QUICKSORT_H
#include "Draw.h"
class QuickSort : public Draw {
    private:

    public:

        void Sort(int a[],int left, int right) {
            int pivot = a[(left+right)/2];
            int i = left, j = right;
            while (i <= j) {
                while (a[i] < pivot) {
                    i ++;
                }

                while (a[j] > pivot) {
                    j --;  
                }

                if (i <= j) {
                    std::swap(a[i], a[j]);
                    i ++; 
                    j --;
                }
                
            }
            if (left < j) Sort(a ,left,j);
            if (right > i) Sort(a,i,right);
        }

        void SortAndDraw(int a[], int n ,int left, int right) {
            int mid = a[(left+right)/2];
            int i = left, j = right;
            toDraw(a,n,(left+right)/2,i,j);
            while (i <= j) {
                count_compare ++;
                while (a[i] < mid) {
                    i ++;
                    count_compare ++;
                    toDraw(a,n,(left+right)/2,i,j);
                    
                }

                while (a[j] > mid) {
                    j --;  
                    count_compare ++;
                    toDraw(a,n,(left+right)/2,i,j);
                    
                }

                if (i <= j) {
                    count_compare ++;
                    count_swap ++;
                    swap(a[i], a[j]);
                    toDraw(a,n,(left+right)/2,i,j);

                    
                    i ++; j --;
                }
                
            }
            if (left < j) SortAndDraw(a,n ,left,j);
            if (right > i) SortAndDraw(a,n ,i,right);
        }
};

#endif

