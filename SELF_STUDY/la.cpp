#include <iostream>
#include <vector>
using namespace std;
const int MAX = 2000000000;

// a class to store a matrix using vector
class Matrix {
    private:
        int n, m;
        vector<vector<int>> a;
    public:
        // default constructor
        Matrix(int n = 1, int m = 1) {
            this -> n = n;
            this -> m = m;
            a.resize(n);
            for (int i = 0; i < n; i++)
                a[i].resize(m);
        }
        // constructor with vector
        Matrix(vector<vector<int>> a, int n = 1, int m = 1) {
            this -> n = n;
            this -> m = m;
            this -> a = a;
        }

        // setter, getter
        bool setN(int n) {
            if (n < 0 or n > MAX)
                return false;
            this -> n = n;
            return true;
        }
        bool setM(int m) {
            if (m < 0 or m > MAX)
                return false;
            this -> m = m;
            return true;
        }
        void setMatrix(vector<vector<int>> a) {
            this -> a = a;
        }
        int getN() {
            return n;
        }
        int getM() {
            return m;
        }
        vector<vector<int>> getMatrix() {
            return a;
        }

        // input n, m and a[n][m], return false if input is invalid
        bool setMatrix() {
            cin >> n >> m;
            if (n < 0 or m < 0)
                return false;
            a.resize(n);
            for (int i = 0; i < n; i++) {
                a[i].resize(m);
                for (int j = 0; j < m; j++)
                    cin >> a[i][j];
            }
            return true;
        }
        // return determinant of a matrix
        int determinant() {
            if (n != m)
                return 0;
            if (n == 1)
                return a[0][0];
            if (n == 2)
                return a[0][0] * a[1][1] - a[0][1] * a[1][0];
            int det = 0;
            for (int i = 0; i < n; i++) {
                Matrix b;
                b.setN(n - 1);
                b.setM(m - 1);
                for (int j = 1; j < n; j++) {
                    for (int k = 0; k < m; k++) {
                        if (k < i)
                            b.getMatrix()[j - 1][k] = a[j][k];
                        else if (k > i)
                            b.getMatrix()[j - 1][k - 1] = a[j][k];
                    }
                }
                det += a[0][i] * b.determinant() * (i % 2 == 0 ? 1 : -1);
            }
            return det;
        }
        // return inverse of a matrix
        Matrix inverse() {
            Matrix b;
            b.setN(n);
            b.setM(m);
            int det = determinant();
            if (det == 0)
                return b;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    Matrix c;
                    c.setN(n - 1);
                    c.setM(m - 1);
                    for (int k = 0; k < n; k++) {
                        for (int l = 0; l < m; l++) {
                            if (k < i and l < j)
                                c.getMatrix()[k][l] = a[k][l];
                            else if (k < i and l > j)
                                c.getMatrix()[k][l - 1] = a[k][l];
                            else if (k > i and l < j)
                                c.getMatrix()[k - 1][l] = a[k][l];
                            else if (k > i and l > j)
                                c.getMatrix()[k - 1][l - 1] = a[k][l];
                        }
                    }
                    b.getMatrix()[i][j] = c.determinant() * ((i + j) % 2 == 0 ? 1 : -1);
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++)
                    b.getMatrix()[i][j] /= det;
            }
            return b;
        }
};      

int main() {
    Matrix m;
    m.setMatrix();
    cout << m.determinant();
    m.inverse().setMatrix();

    return 0;
}