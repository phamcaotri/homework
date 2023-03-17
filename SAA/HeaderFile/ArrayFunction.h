//ArrayFunction.h
#ifndef ARRAYFUNCTION_H
#define ARRAYFUNCTION_H
#include <iostream>
using namespace std;


class ArrayFunction {
    protected:
        int max_value;
    public:
        int max(int a[], int n) {
            int max = a[0];
            for (int i = 1; i < n; i++) {
                if (a[i] > max) {
                    max = a[i];
                }
            }
            return max;
        }

        void input(int a[], int n) {
            for (int i = 0; i < n; i++)
                cin >> a[i];
            max_value = max(a,n);
        }

        void output(int a[], int n) {
            for (int i = 0; i < n; i++) {
                cout << a[i] << ' ';
            }
        }
};

#endif