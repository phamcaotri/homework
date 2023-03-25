// CountSort.h
#ifndef COUNTSORT_H
#define COUNTSORT_H

#include "Draw.h"
class CountSort : public Draw {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------
        using Draw::Draw; //inherit constructor

// OTHER METHODS ---------------------------------------------------

        void Sort() {
            vector<int> b(max_value, 0);
            for (int i = 0; i < n; i++) {
                b[a[i]-1] ++;
            }
            int j = 0;
            for (int i = 0; i < max_value; i++) {
                while (b[i] > 0) {
                    a[j] = i;
                    b[i] --;
                    j++;
                }
            }


        }

        void SortAndDraw() {
            vector<int> b(max_value, 0);
                                                                count_compare ++;
            for (int i = 0; i < n; i++) {
                                                                count_compare ++;
                                                                toDraw(i,-1,-1);
                                                                count_access_array ++;
                b[a[i]-1] ++;
            }
            int j = 0;
                                                                count_compare ++;
            for (int i = 0; i < max_value; i++) {
                                                                count_compare += 2;
                while (b[i] > 0) {
                                                                count_compare ++;
                    a[j] = i;
                                                                count_access_array ++;
                    b[i] --;
                    j++;
                                                                toDraw(j,-1,-1);
                }
            }


        }


};


#endif