//QuickSort.h
#ifndef QUICKSORT_H // include guard
#define QUICKSORT_H
#include "Draw.h"
class QuickSort : public Draw {
    public:
// CONSTRUCTORS ----------------------------------------------------
        using Draw::Draw; //inherit constructor

// OTHER METHODS ---------------------------------------------------
        string getName() {
            return "Quick Sort";
        }
        
        void Sort(int left, int right) {
            int pivot = (left+right)/2;
            int mid = a[pivot];
            int i = left, j = right;
            while (i <= j) {
                while (a[i] < mid) {
                    i ++;
                }

                while (a[j] > mid) {
                    j --;  
                }

                if (i <= j) {
                    swap(a[i], a[j]);
                    i ++; 
                    j --;
                }
            }
            if (left < j) Sort(left,j);
            if (right > i) Sort(i,right);
        }

        void SortAndDraw(int left, int right) {
            int pivot = (left+right)/2;
            int mid = a[pivot];
            int i = left, j = right;
                                                                    count_compare += 3; // 3 while compare 1 last time when it exit
                                                                    toDraw(pivot,i,j);
            while (i <= j) {
                                                                    count_compare ++;
                while (a[i] < mid) {
                    i ++;
                                                                    count_compare ++;
                                                                    toDraw(pivot,i,j);
                    
                }

                while (a[j] > mid) {
                    j --;  
                                                                    count_compare ++;
                                                                    toDraw(pivot,i,j);
                    
                }
                                                                    count_compare ++;
                if (i <= j) {
                                                                    count_swap ++;
                    swap(a[i], a[j]);
                                                                    toDraw(pivot,i,j);
                    i ++; j --;
                }
                
            }
                                                                    count_compare += 2;
            if (left < j) SortAndDraw(left,j);
            if (right > i) SortAndDraw(i,right);
        }

        void SortAndDraw_RandomPivot(int left, int right) {
            srand(time(NULL));
            int i = left, j = right;
            int pivot = left + rand() % (right-left);
            int mid = a[pivot];
                                                                    count_compare += 3; // 3 while compare 1 last time when it exit
                                                                    toDraw(pivot,i,j);
            while (i <= j) {
                                                                    count_compare ++;
                while (a[i] < mid) {
                    i ++;
                                                                    count_compare ++;
                                                                    toDraw(pivot,i,j);
                    
                }

                while (a[j] > mid) {
                    j --;  
                                                                    count_compare ++;
                                                                    toDraw(pivot,i,j);
                    
                }
                                                                    count_compare ++;
                if (i <= j) {
                                                                    count_swap ++;
                    swap(a[i], a[j]);
                                                                    toDraw(pivot,i,j);
                    i ++; j --;
                }
                
            }
                                                                    count_compare += 2;
            if (left < j) SortAndDraw_RandomPivot(left,j);
            if (right > i) SortAndDraw_RandomPivot(i,right);
        }
};

// ANALYZE METHODS --------------------------------------------------


#endif

