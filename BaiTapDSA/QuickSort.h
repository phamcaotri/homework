//QuickSort.h
#ifndef QUICKSORT_H // include guard
#define QUICKSORT_H
#include "SortAlgorithm.h"

class QuickSort : public SortAlgorithm {
    public:
// CONSTRUCTORS ----------------------------------------------------


// OTHER METHODS ---------------------------------------------------
        string getName() {
            return "Quick Sort";
        }
        
        void Sort(int left, int right) {
            int pivot = (left+right)/2; // tìm trục
            int mid = a[pivot]; // giá trị trục
            int i = left, j = right; 
            while (i <= j) { // phân đoạn
                while (a[i] < mid) {
                    i ++;
                }

                while (a[j] > mid) {
                    j --;  
                }

                if (i <= j) { // đổi chỗ
                    swap(a[i], a[j]);
                    i ++; 
                    j --;
                }
            }
            if (left < j) Sort(left,j); // đệ quy
            if (right > i) Sort(i,right); // đệ quy
        }
};


#endif

