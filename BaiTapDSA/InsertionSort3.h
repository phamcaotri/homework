//InsertionSort3.h
#ifndef INSERTIONSORT3_H // include guard
#define INSERTIONSORT3_H
#include "Draw.h"

// dùng phương pháp shift + binarysearch
class InsertionSort3 : public Draw {
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

        int BinarySearchAndDraw(int x, int start, int end) {
            //tìm điểm nằm giữa                                     
                                                                count_compare++;
            if (end < start)
                return start;
            int mid  =  (end+start)/2;
                                                                toDraw(mid,start,end);
                                                                count_compare++;
            if (x == a[mid])
                return mid;
            else {                                              count_compare++;
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


        void SortAndDraw() {
                                                        count_compare ++;
            for (int i = 1; i < n ; i++) {                   
                int x = a[i];
                int k = BinarySearchAndDraw(x,0,i-1);
                                                        toDraw(i,-1,-1);
                                                        count_compare += 2;
                for (int j = i-1; j >= k; j--) {
                                                        toDraw(i,j,-1);
                                                        count_compare ++;
                        a[j+1] = a[j];
                                                        toDraw(i,j,-1);
                }
                a[k] = x;
                                                        toDraw(i,-1,-1);
                }                                               
        }

};

#endif
