// ShellSort.h
#ifndef SHELLSORT_H
#define SHELLSORT_H
#include "Draw.h"
#include "math.h"
class ShellSort : public Draw {
    private:

    public:
        using Draw::Draw;

        string getName() {
            return "Shell Sort";
        }

        void Sort() {
            // chia mảng thành các phần tử k giảm dần
            // sắp xếp các phần tử k đó theo insertion sort
            // lặp lại đến khi k = 1
            for (int k = log2(n); k >= 1; (k/2 >=1)?(k/=2):(k-=1))
                for (int i = 0; i < n-k; i+=k)
                    for (int j = i; j >= 0; j -= k) { 
                        if (a[j+k] < a[j]) {
                            swap(a[j+k],a[j]);
                        } else break;
                }
            }
        void SortAndDraw() {
            // chia mảng thành các phần tử k giảm dần
            // sắp xếp các phần tử k đó theo insertion sort
            // lặp lại đến khi k = 1
                                                                        toDraw(-1,-1,-1);  
            for (int k = log2(n); k >= 1; (k/2>=1)?(k/=2):(k-=1))
                for (int i = 0; i < n-k; i+=k)
                    for (int j = i; j >= 0; j -= k) {
                                                                        toDraw(i,j,k);   
                        if (a[j+k] < a[j]) {
                            swap(a[j+k],a[j]);
                        } else break;
                }
            }
};

#endif