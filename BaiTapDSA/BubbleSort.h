//BubbleSort.h
#ifndef BUBBLESORT_H // include guard
#define BUBBLESORT_H
#include "SortAlgorithm.h"
class BubbleSort : public SortAlgorithm {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------


// OTHER METHODS ---------------------------------------------------
        string getName() {
            return "Bubble Sort";
        }

        void Sort() {
            bool swapped = true;
            for (int i = 1; i < n and swapped ; i++) {
                swapped = false;
                for (int j = 0; j < n-i ; j++)
                    if (a[j] > a[j+1]) { // đổi chỗ 2 phần tử nếu sai thứ tự
                        swap(a[j],a[j+1]);
                        swapped = true;
                    }

            }


        }
};

#endif
