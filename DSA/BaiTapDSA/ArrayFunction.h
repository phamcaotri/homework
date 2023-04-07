//ArrayFunction.h
/*
Chức năng của class ArrayFunction:
1. Lưu trữ mảng a và n cho từng class Sort kế thừa
2. Cung cấp các phương thức để thao tác với mảng a

*/
#ifndef ARRAYFUNCTION_H
#define ARRAYFUNCTION_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// maximum value of n
const int MAX = 2000000000;

class ArrayFunction {
    protected:

        int max_value = 0;
        int min_value = 0;
        int n = 1;
        vector<int> a;

    public:

// GETTER - SETTER METHODS -----------------------------------------

        // input n. return false if input is invalid
        bool setN(int n = 1) {
            if (n < 0 or n > MAX)
                return false;
            a.resize(n);
            this -> n = n;
            return true;
        }
        // trả về mảng a và tình trạng sắp xếp của mảng
        void getArray() {
            string buffer;
            cout << '\n';
            for (int i = 0; i < n; i++) {
                buffer += to_string(a[i]) + " ";
            }
            buffer += "\n";
            cout << buffer;
            if (isSorted()) {
                cout << "Sorted Array." << '\n';
            } else {
                cout << "Unsorted Array." << '\n';
            }
        }


// OTHER METHODS ---------------------------------------------------

        int max() {
            int max = a[0];
            for (int i = 1; i < n; i++) {
                if (a[i] > max) {
                    max = a[i];
                }
            }
            return max;
        }

        int min() {
            int min = a[0];
            for (int i = 1; i < n; i++) {
                if (a[i] < min) {
                    min = a[i];
                }
            }
            return min;
        }

        bool isSorted() {
            for (int i = 1; i < n; i++) {
                if (a[i] < a[i-1]) {
                    return false;
                }
            }
            return true;
        }

        void createShuffledArray() {
            srand(time(NULL));
            // randomize the array with n elements, each element is in range [-10000, 10000]
            for (int i = 0; i < n; i++) {
                a[i] = rand() % 20001 - 10000;
            }
            max_value = max();
            min_value = min();
        }     
};

#endif