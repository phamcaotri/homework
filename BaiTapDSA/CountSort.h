// CountSort.h
#ifndef COUNTSORT_H
#define COUNTSORT_H

#include "SortAlgorithm.h"
class CountSort : public SortAlgorithm {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------


// OTHER METHODS ---------------------------------------------------
        string getName() {
            return "Counting Sort";
        }
        
        void Sort() {
            // nếu có số âm, thì chuyển tất cả các số về dương
            if (min_value < 0) {
                for (int i = 0; i < n; i++) {
                    a[i] -= min_value;
                }
                max_value -= min_value;
            }
            vector<int> b(max_value+1,0); // mảng b để lưu số lần xuất hiện của các phần tử
            for (int i = 0; i < n; i++) {
                b[a[i]]++; // đếm số lần xuất hiện của các phần tử
            }
            int j = 0;
            for (int i = 0; i < max_value+1; i++) { // in kết quả lại mảng a
                while (b[i] > 0) {
                    a[j] = i;
                    b[i] --;
                    j++;
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