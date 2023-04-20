#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class SoPhuc {
    private:
        float thuc, ao;
    public:
        SoPhuc(float thuc = 0, float ao = 0) {
            this -> thuc = thuc;
            this -> ao = ao;
        }
        void input(float thuc, float ao) {
            this -> thuc = thuc;
            this -> ao = ao;
        }
        void input() {
            cin >> thuc >> ao;
        }
};

class Matrix {
    private:
        vector<vector<SoPhuc>> matrix;
};

int main() {
    return 0;
}
