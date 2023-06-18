// InPlaceMergeSort.h
#ifndef INPLACEMERGESORT_H
#define INPLACEMERGESORT_H
#include "Draw.h"

class InPlaceMergeSort : public Draw {
    public:
// CONSTRUCTORS ----------------------------------------------------
        using Draw::Draw;

// OTHER METHODS ---------------------------------------------------

        string getName() {
            return "In-Place Merge Sort";
        }
        
        void Sort(int start, int end) {
            int pivot = (start + end)/2;
            if (start < pivot) Sort(start,pivot);
            if (end > pivot +1 ) Sort(pivot+1,end);
            merge(start,pivot,end);
        }

        void SortAndDraw(int start, int end) {
            int pivot = (start + end)/2;
                                                                        count_compare += 2;
            if (start < pivot) SortAndDraw(start,pivot);
            if (end > pivot +1) SortAndDraw(pivot+1,end);
            mergeAndDraw(start,pivot,end);      
        }  

    private:

        void merge(int start, int pivot, int end) {
            // merge using in-place merge
            int i = start, j = pivot +1, k = 0;
            while (i <= pivot and j <= end) {
                // if a[i] < a[j] then do nothing
                if (a[i] < a[j]) {
                    i++;
                }
                else {
                    // shift a[i] to a[j] and shift a[i+1] to a[j+1] and so on
                    int temp = a[j];
                    for (int k = j-1; k >= i; k--) {
                        a[k+1] = a[k];
                    }
                    a[i] = temp;
                    i++;
                    j++;
                    pivot++;
                }
            }
            
            
        }

        void mergeAndDraw(int start, int pivot, int end) {
            // merge using in-place merge
            int i = start, j = pivot +1, k = 0;
            while (i <= pivot and j <= end) {
                if (a[i] < a[j]) {
                    i++;
                }
                else {
                    int temp = a[j];
                    for (int k = j-1; k >= i; k--) {
                        a[k+1] = a[k];
                    }
                    a[i] = temp;
                    i++;
                    j++;
                    pivot++;
                }
                toDraw(end-start+1,start,end);
            }
        }

};

#endif