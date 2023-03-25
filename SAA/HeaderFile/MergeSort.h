//MergeSort.h
#ifndef MERGESORT_H
#define MERGESORT_H
#include "Draw.h"

class MergeSort : public Draw {


    public:
// CONSTRUCTORS ----------------------------------------------------
        using Draw::Draw;

// OTHER METHODS ---------------------------------------------------

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

        void mergeAndDraw(int start, int pivot, int end) {
            vector<int> b(end-start+1);
            int i = start, j = pivot +1, k = 0;
                                                                        toDraw(pivot,i,j);
                                                                        count_compare += 2;
            while (i <= pivot and j <= end) {
                                                                        count_compare += 3; //compare while and if
                                                                        count_access_array ++;
                if (a[i] < a[j]) {
                    b[k] = a[i];
                    k++;
                    i++;
                                                                        toDraw(pivot,i,j);
                }
                else {
                    b[k] = a[j];
                    k++;
                    j++;
                                                                        toDraw(pivot,i,j);

                }
            }
                                                                        count_compare += 2;
            for (i;i <= pivot; i++) {
                                                                        count_compare ++;
                                                                        count_access_array ++;
                b[k] = a[i];
                k++;
                                                                        toDraw(pivot,i,j);
            }
            for (j;j <= end; j++) {
                                                                        count_compare ++;
                                                                        count_access_array ++;
                b[k] = a[j];
                k++;
                                                                        toDraw(pivot,i,j);
            }

            k = 0;
                                                                        count_compare ++;
            for (i = start; i <= end; i++) {
                                                                        count_compare ++;
                a[i] = b[k];
                k++;
                                                                        toDraw(pivot,i,j);
            }
                
        }
};

#endif