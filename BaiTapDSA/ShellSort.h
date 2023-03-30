// ShellSort.h
#ifndef SHELLSORT_H
#define SHELLSORT_H
#include "SortAlgorithm.h"
class ShellSort : public SortAlgorithm {
    private:

    public:


        string getName() {
            return "Shell Sort";
        }

        void Sort() {
            // chia mảng thành các phần tử k giảm dần
            // sắp xếp các phần tử k đó theo insertion sort
            // lặp lại đến khi k = 1

            for (int k = n/2; k > 0; k /= 2 )
                for (int i = k; i < n; i++)
                    for (int j = i; j >= k and a[j] < a[j-k]; j -= k) {
                            swap(a[j],a[j-k]);
                }
            }

};

#endif