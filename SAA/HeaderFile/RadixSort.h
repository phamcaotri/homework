// RadixSort.h
#ifndef RADIXSORT_H
#define RADIXSORT_H
#include "Draw.h"

class RadixSort : public Draw {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------
        using Draw::Draw; //inherit constructor

// OTHER METHODS ---------------------------------------------------
        string getName() {
            return "Radix Sort";
        }
        
        void Sort() {
            vector<vector<int>> b(10,vector<int> (max_value));
            int max_radix = size(to_string(max_value));
            for (int radix = 1; radix < pow(10,max_radix); radix *= 10) {
                vector<int> c(10,0);
                for (int i = 0; i < n; i++) {
                    b[(a[i]/(radix))%10][c[(a[i]/(radix))%10]] = a[i];
                    c[(a[i]/(radix))%10] ++;
                }
                int k = 0;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < c[i]; j++ ) {
                        a[k] = b[i][j];
                        k++;
                    }
                }
            }
        }
        void SortAndDraw() {
            vector<vector<int>> b(10,vector<int> (max_value));
            int max_radix = size(to_string(max_value));
            for (int radix = 1; radix < pow(10,max_radix); radix *= 10) {
                vector<int> c(10,0);
                for (int i = 0; i < n; i++) {
                    b[(a[i]/(radix))%10][c[(a[i]/(radix))%10]] = a[i];
                    c[(a[i]/(radix))%10] ++;
                                                                    toDraw(i,-1,-1);
                }
                int k = 0;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < c[i]; j++ ) {
                        a[k] = b[i][j];
                        k++;
                                                                    toDraw(i,-1,-1);
                    }
                }
            }
        }
};

#endif