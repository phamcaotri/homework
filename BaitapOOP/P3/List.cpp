#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class list {
    private:
        double *pointer;
        unsigned int size;
    public:
        list() {
            pointer = NULL;
            size = 0;
        }
        void push_back(double x) {
            double *temp = new double[size + 1];
            for (int i = 0; i < size; i++) {
                temp[i] = pointer[i];
            }
            temp[size] = x;
            delete[] pointer;
            pointer = temp;
            size++;
        }
        void pop_at_first(double x) {
            bool exist = false;
            for (int i = 0; i < size; i++) {
                if (pointer[i] == x) {
                    exist = true;
                    break;
                }
            }
            if (exist) {
                double *temp = new double[size - 1];
                int i = 0;
                while (pointer[i] != x) {
                    temp[i] = pointer[i];
                    i++;
                }
                for (int j = i; j < size - 1; j++) {
                    temp[j] = pointer[j + 1];
                }
                delete[] pointer;
                pointer = temp;
                size--;
            }

        }
        void pop_all(double x) {
            int count = 0;
            for (int i = 0; i < size; i++) {
                if (pointer[i] == x) {
                    count++;
                }
            }
            double *temp = new double(size - count);
            int i = 0;
            int j = 0;
            while (i < size) {
                if (pointer[i] != x) {
                    temp[j] = pointer[i];
                    j++;
                }
                i++;
            }
            delete[] pointer;
            pointer = temp;
            size -= count;
        }
        void replace_at(int x, double y) {
            if (x < size and x >= 0) {
                pointer[x] = y;
            }
        }

        void input() {
            double x;
            cin >> x;
            
        }
        void chiThi(int chiThi) {
        
            if (chiThi == 0) {
                double x;
                cin >> x;
                push_back(x);
                return ;
            }
            if (chiThi == 1) {
                double x;
                cin >> x;
                pop_at_first(x);
                return;
            }
            if (chiThi == 2) {
                double x;
                cin >> x;
                pop_all(x);
                return;
            }
            if (chiThi == 3) {
                int x;
                double y;
                cin >> x >> y;
                replace_at(x, y);
                return;
            }
            if (chiThi == -1) {
                if (size == 0) {
                    cout << "[]";
                    return;
                }
                cout << '[';
                for (int i = 0; i < size-1; i++) {
                    cout << pointer[i] << ",";
                }
                cout << pointer[size-1];
                cout << ']';
                return;
            }
        }
};

int main() {
    list a;
    int chiThi;
    do {
        cin >> chiThi;
        a.chiThi(chiThi);
    } while (chiThi != -1);
    
    return 0;
}