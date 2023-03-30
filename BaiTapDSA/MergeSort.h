//MergeSort.h
#ifndef MERGESORT_H
#define MERGESORT_H
#include "SortAlgorithm.h"

class MergeSort : public SortAlgorithm {


    public:
// CONSTRUCTORS ----------------------------------------------------
        using Draw::Draw;

// OTHER METHODS ---------------------------------------------------

        string getName() {
            return "Merge Sort";
        }
        
        void Sort(int start, int end) {
            int pivot = (start + end)/2;
            if (start < pivot) Sort(start,pivot);
            if (end > pivot +1 ) Sort(pivot+1,end);
            merge(start,pivot,end);
        }


    private:

        void merge(int start, int pivot, int end) {
            vector<int> b(end-start+1);
            int i = start, j = pivot +1, k = 0;
            while (i <= pivot and j <= end) {
                if (a[i] < a[j]) {
                    b[k] = a[i];
                    k++;
                    i++;
                }
                else {
                    b[k] = a[j];
                    k++;
                    j++;

                }
            }
            for (i;i <= pivot; i++) {
                b[k] = a[i];
                k++;
            }
            for (j;j <= end; j++) {
                b[k] = a[j];
                k++;
            }

            k = 0;
            for (i = start; i <= end; i++) {
                a[i] = b[k];
                k++;
            }
                
        }

};

#endif