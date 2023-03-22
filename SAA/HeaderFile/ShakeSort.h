//ShakeSort.h
#ifndef SHAKESORT_H // include guard
#define SHAKESORT_H
#include "Draw.h"
#include "InsertionSort.h"
class ShakeSort : public Draw {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------
        using Draw::Draw; //inherit constructor

        void Sort() {
            bool swapped;

            for (int i = 0; i < n/2 ; i++) {
                swapped = false;
                for (int j = i; j < n-i-1; j++) {
                    
                    if (a[j] > a[j+1]) {
                        swap(a[j],a[j+1]);
                        swapped = true;
                    }
                }


                for (int j = n-i-1 ; j > i ; j--) {
                    if (a[j] < a[j-1]) {
                        swap(a[j],a[j-1]);
                        swapped = true;
                    }
                }
                if (not swapped)
                    break;

            }


        }

        void SortAndDraw() {
            bool swapped;
   
            count_compare += 3;
            for (int i = 0; i < n/2 ; i++) {
                count_compare ++;
                swapped = false;
                for (int j = i; j < n-i-1; j++) {
                    count_compare += 2;
                    toDraw(j,i,n-i-1);
                    if (a[j] > a[j+1]) {
                        swap(a[j],a[j+1]);
                        toDraw(j,i,n-i-1);
                        swapped = true;
                    }

                }

                for (int j = n-i-1 ; j > i ; j--) {
                    count_compare += 3;
                    toDraw(j,i,n-i-1);
                    if (a[j] < a[j-1]) {
                        swap(a[j],a[j-1]);
                        toDraw(j,i,n-i-1);
                        swapped = true;
                    }     
                }
                if (not swapped)
                    break;

            }
        }

        void SortAndDraw2() {
            count_compare += 3;
            for (int i = 0; i < n/2 ; i++) {
                count_compare ++;
                for (int j = i; j < n-i-1; j++) {
                    count_compare += 2;
                    toDraw(j,i,n-i-1);
                    if (a[j] > a[j+1]) {
                        swap(a[j],a[j+1]);
                        toDraw(j,i,n-i-1);
                    }

                }
                i++;
                for (int j = n-i-1 ; j > i ; j--) {
                    count_compare += 3;
                    toDraw(j,i,n-i-1);
                    if (a[j] < a[j-1]) {
                        swap(a[j],a[j-1]);
                        toDraw(j,i,n-i-1);
                    }     
                }
                

            }
            {
            count_compare += 2;
            for (int i = 1; i < n ; i++)
                for (int j = i; j > 0; j--) {
                    count_compare += 3;
                    toDraw(i,j,-1);
                    if (a[j] < a[j-1]) {
                        count_swap ++;
                        swap(a[j],a[j-1]);
                        toDraw(i,j,-1);
                    }
                    else break;
                }

                        
            }

 

        }

};

#endif

