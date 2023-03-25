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
        void createRamdomizeArray() {
            srand(time(NULL));
            for (int i = 0; i < n; i++) {
                a[i] = rand() % n + 1;
            }
            max_value = max();
        }

        void createShuffledArray() {
            srand(time(NULL));
            for (int i = 0; i < n; i++) {
                a[i] = i+1;
            }
            random_shuffle(a.begin(),a.end());
            max_value = n;
        }

        void createTestArray() {
            // random but only 1
            for (int i = 0; i < n; i++) {
                a[i] = i+1;
            }
            random_shuffle(a.begin(),a.end());
            max_value = n;
        }
        void createReverseArray() {
            for (int i = 0; i < n; i++) {
                a[i] = n-i;
            }
            max_value = n;
        }
        void createMoutainArray() {
            for (int i = 0; i < n/2; i++) {
                a[i] = i+1;
            }
            for (int i = n/2; i < n; i++) {
                a[i] = n-i;
            }
            max_value = max();           
        }

};

#endif