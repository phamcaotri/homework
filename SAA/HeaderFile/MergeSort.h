//MergeSort.h
#ifndef MERGESORT_H
#define MERGESORT_H
#include "Draw.h"

class MergeSort : public Draw {
    private:
        void merge(int a[], int start, int pivot, int end) {
            int *b = new int[end-start+1];
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
        void mergeAndDraw(int a[], int n, int start, int pivot, int end) {
            int *b = new int[end-start+1];
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
    public:

        void Sort(int a[], int n, int start, int end) {
            int pivot = (start + end)/2;
            if (start < pivot) Sort(a,n,start,pivot);
            if (end > pivot +1 ) Sort(a,n,pivot+1,end);
            merge(a,start,pivot,end);
            

        }

        void SortAndDraw(int a[], int n, int start, int end) {
            int pivot = (start + end)/2;
            count_compare += 2;
            if (start < pivot) SortAndDraw(a,n,start,pivot);
            if (end > pivot +1) SortAndDraw(a,n,pivot+1,end);
            mergeAndDraw(a,n,start,pivot,end); 
            

                        
        }   

};

#endif