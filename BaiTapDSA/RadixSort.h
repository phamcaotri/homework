// RadixSort.h
#ifndef RADIXSORT_H
#define RADIXSORT_H
#include "SortAlgorithm.h"
#include <math.h>
class RadixSort : public SortAlgorithm {
    private:


    public:
// CONSTRUCTORS ----------------------------------------------------


// OTHER METHODS ---------------------------------------------------
        string getName() {
            return "Radix Sort";
        }

        void Sort() {
            // nếu có số âm, thì chuyển tất cả các số về dương
            if (min_value < 0) {
                for (int i = 0; i < n; i++) {
                    a[i] -= min_value;
                }
                max_value -= min_value;
            }
            // tính số chữ số của số lớn nhất
            int max_digit = to_string(abs(max_value)).size();
            vector<vector<int>> b(10,vector<int> (n)); // mảng b để lưu các phần tử
            for (int base = 1; base < pow(10,max_digit); base *= 10) {
                vector<int> c(10,0); // mảng c để lưu số lần xuất hiện của các phần tử
                for (int i = 0; i < n; i++) {
                    int index = (a[i]/(base))%10;
                    b[index][c[index]] = a[i]; // chèn phần tử trong mảng a vào mảng b
                    c[index] ++;
                }
                int k = 0;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < c[i]; j++ ) {
                        a[k] = b[i][j]; // chèn kết quả lại mảng a
                        k++;
                    }
                }
            }
            // nếu có số âm, thì chuyển về lại
            if (min_value < 0) {
                for (int i = 0; i < n; i++) {
                    a[i] += min_value;
                }
            }
        }


};

#endif