//MergeSort.h
#ifndef MERGESORT_H
#define MERGESORT_H
#include "SortAlgorithm.h"

class MergeSort : public SortAlgorithm {


    public:
// CONSTRUCTORS ----------------------------------------------------


// OTHER METHODS ---------------------------------------------------

        string getName() {
            return "Merge Sort";
        }
        
        void Sort(int start, int end) {
            int pivot = (start + end)/2; // tìm trục
            if (start < pivot) Sort(start,pivot); // sắp xếp nửa trái
            if (end > pivot +1 ) Sort(pivot+1,end); // sắp xếp nửa phải
            merge(start,pivot,end); // gộp 2 nửa lại
        }


    private:
        // hàm gộp 2 nửa lại
        void merge(int start, int pivot, int end) {
            vector<int> b(end-start+1);
            int i = start, j = pivot +1, k = 0;
            while (i <= pivot and j <= end) { // gộp 2 nửa lại
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
            for (i;i <= pivot; i++) { // nếu nửa trái còn phần tử, thì gộp vào
                b[k] = a[i];
                k++;
            }
            for (j;j <= end; j++) { // nếu nửa phải còn phần tử, thì gộp vào
                b[k] = a[j];
                k++;
            }

            k = 0;
            for (i = start; i <= end; i++) { // gán lại mảng a
                a[i] = b[k];
                k++;
            }
                
        }

};

#endif