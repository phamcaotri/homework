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
using namespace std;

// maximum value of n
const int MAX = 2000000000;

class ArrayFunction {
    protected:

        int max_value = 0;
        int n = 1;
        vector<int> a;

    public:

// CONSTRUCTORS ----------------------------------------------------

        // default constructor
        ArrayFunction(int n = 1) {
            if (n > 0 and n < MAX) {
                a.resize(n);
                this -> n = n;
            }
            max_value = max();
        }
        // constructor with vector
        ArrayFunction(vector<int> a, int n = 1) {
            if (n > 0 and n < MAX) {
                a.resize(n);
                this -> n = n;
            }
            this -> a = a;
            max_value = max();
        }


// GETTER - SETTER METHODS -----------------------------------------

        // input n and a[n], return false if input is invalid 
        bool setArray() {
            cin >> n;
            if (n < 0 or n > MAX)
                return false;
            a.resize(n);
            for (int i = 0; i < n; i++)
                cin >> a[i];
            max_value = max();
            return true;
        }
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
            cout << '\n';
            for (int i = 0; i < n; i++) {
                cout << a[i] << ' ';
            }
            cout << '\n';
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
            for (int i = 0; i < n; i++) {
                a[i] = i+1;
            }
            random_shuffle(a.begin(),a.end());
            max_value = n;
        }     
};

#endif