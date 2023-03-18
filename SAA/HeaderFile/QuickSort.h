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
                    swap(a[i], a[j]);
                    i ++; 
                    j --;
                }
                
            }
            if (left < j) Sort(a ,left,j);
            if (right > i) Sort(a,i,right);
        }

        void SortAndDraw(int a[], int n ,int left, int right) {
            int pivot = (left+right)/2;
            int mid = a[pivot];
            int i = left, j = right;
            count_compare += 3; // 3 while compare 1 last time when it exit
            toDraw(a,n,pivot,i,j);
            while (i <= j) {
                count_compare ++;
                while (a[i] < mid) {
                    i ++;
                    count_compare ++;
                    toDraw(a,n,pivot,i,j);
                    
                }

                while (a[j] > mid) {
                    j --;  
                    count_compare ++;
                    toDraw(a,n,pivot,i,j);
                    
                }
                count_compare ++;
                if (i <= j) {
                    count_swap ++;
                    swap(a[i], a[j]);
                    toDraw(a,n,pivot,i,j);
                    i ++; j --;
                }
                
            }
            count_compare += 2;
            if (left < j) SortAndDraw(a,n ,left,j);
            if (right > i) SortAndDraw(a,n ,i,right);
        }
        void SortAndDraw2(int a[], int n ,int left, int right) {
            srand(time(NULL));
            int pivot = rand() % (right-left+1)+1;
            
            int mid = a[pivot];
            int i = left, j = right;
            count_compare += 3; // 3 while compare 1 last time when it exit
            toDraw(a,n,pivot,i,j);
            while (i <= j) {
                count_compare ++;
                while (a[i] < mid) {
                    i ++;
                    count_compare ++;
                    toDraw(a,n,pivot,i,j);
                    
                }

                while (a[j] > mid) {
                    j --;  
                    count_compare ++;
                    toDraw(a,n,pivot,i,j);
                    
                }
                count_compare ++;
                if (i <= j) {
                    count_swap ++;
                    swap(a[i], a[j]);
                    toDraw(a,n,pivot,i,j);
                    i ++; j --;
                }
                
            }
            count_compare += 2;
            if (left < j) SortAndDraw(a,n ,left,j);
            if (right > i) SortAndDraw(a,n ,i,right);
        }
};

#endif

