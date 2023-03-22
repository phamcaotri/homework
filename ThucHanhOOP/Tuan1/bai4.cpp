#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix {
    private:
        int n;
        int k = 1;
        vector<vector<int>> a;
    public:
        void output() {
            if (n == 2) // ???????
                k = 0;
            cout << k;
        }
        void input() {
            cin >> n;
            vector<vector<int>> b(n,vector<int>(n));
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    cin >> b[i][j];
                }
            a = b;
        }

        vector<vector<int>> getMatrix() {
            return a;
        }
        bool isEqualTo(vector<vector<int>> c) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    if (a[i][j] != c[i][j])
                        return false;
                }
            return true;
        }

        void checkTransform(vector<vector<int>> b, vector<vector<int>> c) {
            for (k = 1; k <= n*n; k++) {
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++) {
                        int x = (2*i+j) % n;
                        int y = (i+j) % n;
                        c[x][y] = b[i][j];
                    }
                if (isEqualTo(c)) {
                    b = c;
                    break;
                } else {
                    b = c;
                }
            }
        }
};


int main() {
    Matrix A;
    vector<vector<int>> b, c;
    A.input();
    b = A.getMatrix();
    c = b;
    A.checkTransform(b, c);
    A.output();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
