//ArrayFunction.h
#ifndef ARRAYFUNCTION_H
#define ARRAYFUNCTION_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// maximum number of element support
const int MAX = 2000000000;

class ArrayFunction {
    
    protected:
        int max_value = 0;
        int n = 0;
        vector<int> a;
    public:

// CONSTRUCTORS ----------------------------------------------------

        ArrayFunction(int n = 0) {
            if (n > 0 and n < MAX) {
                a.resize(n);
                this -> n = n;
            }
            max_value = max();
        }
        ArrayFunction(vector<int> a, int n) {
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
            if (n < 0 or n > 2000000000)
                return false;
            vector<int> a(n);
            for (int i = 0; i < n; i++)
                cin >> a[i];
            this -> a = a;
            max_value = max();
            return true;
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