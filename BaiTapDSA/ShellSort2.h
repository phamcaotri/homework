// ShellSort2.h
#ifndef SHELLSORT2_H
#define SHELLSORT2_H
#include "Draw.h"
#include "math.h"
class ShellSort2 : public Draw {
    private:

    public:
        using Draw::Draw;

        string getName() {
            return "Shell Sort 2";
        }

        void Sort() {
            int k = n/2;
            while (k > 0) {
                for (int i = k; i < n; i++) {
                    int j = i;
                    while (j >= k and a[j] < a[j-k]) {
                        swap(a[j],a[j-k]);
                        j -= k;
                    }
                }
                k /= 2;
            }
        }

        void SortAndDraw() {
            int k = n/2;
            while (k > 0) {
                for (int i = k; i < n; i++) {
                    int j = i;
                    while (j >= k and a[j] < a[j-k]) {
                        swap(a[j],a[j-k]);
                        j -= k;
                                                                toDraw(j,j+k,-1);
                    }
                }
                k /= 2;
            }
        }
};

#endif