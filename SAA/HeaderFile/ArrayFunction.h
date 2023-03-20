//ArrayFunction.h
#ifndef ARRAYFUNCTION_H
#define ARRAYFUNCTION_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class ArrayFunction {

    protected:
        int max_value = 0;
        int n = 0;
        vector<int> a;
    public:

// CONSTRUCTORS ----------------------------------------------------
        ArrayFunction() {}
        ArrayFunction(vector<int> a, int n) {
            this -> a = a;
            this -> n = n;
            max_value = max();
        }
        ArrayFunction(int n) : n(n), a(n) {
            max_value = max();
        }

// GETTER - SETTER METHODS -----------------------------------------

        void setArray() {
            cin >> n;
            vector<int> a(n);
            for (int i = 0; i < n; i++)
                cin >> a[i];
            this -> a = a;
            max_value = max();
        }

        void getArray() {
            for (int i = 0; i < n; i++) {
                cout << a[i] << ' ';
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
        void createRamdomizeArray() {
            srand(time(NULL));
            for (int i = 0; i < n; i++) {
                a[i] = rand() % n + 1;
            }
            max_value = max();
        }

        void createShuffledArray() {
            for (int i = 0; i < n; i++) {
                a[i] = i+1;
            }
            random_shuffle(a.begin(),a.end());
            max_value = n;
        }
};

#endif