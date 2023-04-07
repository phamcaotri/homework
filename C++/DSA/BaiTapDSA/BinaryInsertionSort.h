//BinaryInsertionSort.h
#ifndef BINARYINSERTIONSORT_H // include guard
#define BINARYINSERTIONSORT_H
#include "SortAlgorithm.h"

class BinaryInsertionSort : public SortAlgorithm {
    private:
        int BinarySearch(int x, int start, int end) {
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

// OTHER METHODS ---------------------------------------------------

        string getName() {
            return "Binary Insertion Sort";
        }
        
        void Sort() {
            for (int i = 1; i < n ; i++) {
                int x = a[i]; 
                int k = BinarySearch(x,0,i-1); // tìm vị trí chèn
                for (int j = i-1; j >= k; j--) { // dời các phần tử sang phải
                    a[j+1] = a[j];
                }
                a[k] = x; // chèn phần tử x vào vị trí k
            }
        }
};

#endif
