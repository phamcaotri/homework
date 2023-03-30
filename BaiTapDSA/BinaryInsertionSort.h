//BinaryInsertionSort.h
#ifndef BINARYINSERTIONSORT_H // include guard
#define BINARYINSERTIONSORT_H
#include "SortAlgorithm.h"

// dùng phương pháp shift + binarysearch
class BinaryInsertionSort : public SortAlgorithm {
    private:
        int BinarySearch(int x, int start, int end) {
            //tìm điểm nằm giữa
            if (end < start)
                return start;
            int mid  =  (end+start)/2;

            if (x == a[mid])
                return mid;
            else {
                if (x > a[mid])
                    return BinarySearch(x,mid+1,end);
                else
                    return BinarySearch(x,start,mid-1);
            }
        }

    public:
// CONSTRUCTORS ----------------------------------------------------
        using Draw::Draw;

// OTHER METHODS ---------------------------------------------------


        string getName() {
            return "Insertion Sort with shift and binary search";
        }
        
        void Sort() {
            for (int i = 1; i < n ; i++) {
                int x = a[i];
                int k = BinarySearch(x,0,i-1);
                for (int j = i-1; j >= k; j--) {
                    a[j+1] = a[j];
                }
                a[k] = x;
            }
        }
};

#endif
