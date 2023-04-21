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
        void output() {
            cout << thuc << " + " << ao << "i";
        }

        SoPhuc conj() {
            SoPhuc c;
            c.thuc = thuc;
            c.ao = -ao;
            return c;
        }
        float Thuc() {
            return thuc;
        }
        float Ao() {
            return ao;
        }

        friend SoPhuc operator+(SoPhuc a, SoPhuc b) {
            SoPhuc c;
            c.thuc = a.thuc + b.thuc;
            c.ao = a.ao + b.ao;
            return c;
        }
        friend SoPhuc operator-(SoPhuc a, SoPhuc b) {
            SoPhuc c;
            c.thuc = a.thuc - b.thuc;
            c.ao = a.ao - b.ao;
            return c;
        }
        friend SoPhuc operator-(SoPhuc a) {
            SoPhuc c;
            c.thuc = -a.thuc;
            c.ao = -a.ao;
            return c;
        }
        friend SoPhuc operator*(SoPhuc a, SoPhuc b) {
            SoPhuc c;
            c.thuc = a.thuc * b.thuc - a.ao * b.ao;
            c.ao = -(a.thuc * b.ao + a.ao * b.thuc);
    
            return c;
        }
};

class Matrix {
    private:
        vector<vector<SoPhuc>> matrix;
        int row, col;
    public:
        Matrix() {
            row = col = 0;
        }
        Matrix(int row, int col) {
            this -> row = row;
            this -> col = col;
            resize(row, col);
        }

        void resize(int row, int col) {
            this -> row = row;
            this -> col = col;
            matrix.resize(row);
            for (int i = 0; i < row; i++) {
                matrix[i].resize(col);
            }
        }
        void input() {
            cin >> row >> col;
            resize(row, col);
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    matrix[i][j].input();
                }
            }
        }

        void vectorInput() {
            row = 1;
            cin >> col;
            resize(row, col);
            for (int j = 0; j < col; j++) {
                matrix[0][j].input();
            }
        }

        void output() {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    matrix[i][j].output();
                    cout << " ";
                }
                cout << endl;
            }
        }

        Matrix transpose() {
            Matrix c(col, row);
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    c.matrix[j][i] = matrix[i][j];
                }
            }
            return c;
        }

        friend Matrix operator+(Matrix a, Matrix b) {
            Matrix c(a.row, a.col);
            for (int i = 0; i < a.row; i++) {
                for (int j = 0; j < a.col; j++) {
                    c.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
                }
            }
            return c;
        }
        friend Matrix operator-(Matrix a, Matrix b) {
            Matrix c(a.row, a.col);
            for (int i = 0; i < a.row; i++) {
                for (int j = 0; j < a.col; j++) {
                    c.matrix[i][j] = a.matrix[i][j] - b.matrix[i][j];
                }
            }
            return c;
        }
        friend Matrix operator*(Matrix a, Matrix b) {
            Matrix c(a.row, b.col);
            for (int i = 0; i < a.row; i++) {
                for (int j = 0; j < b.col; j++) {
                    c.matrix[i][j] = SoPhuc(0, 0);
                    for (int k = 0; k < a.col; k++) {
                        c.matrix[i][j] = c.matrix[i][j] + a.matrix[i][k] * b.matrix[k][j];
                    }
                }
            }
            return c;
        }

        friend Matrix operator*(Matrix a, SoPhuc b) {
            Matrix c(a.row, a.col);
            for (int i = 0; i < a.row; i++) {
                for (int j = 0; j < a.col; j++) {
                    c.matrix[i][j] = a.matrix[i][j] * b;
                }
            }
            return c;
        }

        SoPhuc det() {
            SoPhuc d(0, 0);
            if (row == 1) {
                return matrix[0][0];
            }
            if (row == 2) {
                return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
            }
            for (int i = 0; i < row; i++) {
                Matrix c(row - 1, col - 1);
                for (int j = 1; j < row; j++) {
                    for (int k = 0; k < col; k++) {
                        if (k < i) {
                            c.matrix[j - 1][k] = matrix[j][k];
                        }
                        if (k > i) {
                            c.matrix[j - 1][k - 1] = matrix[j][k];
                        }
                    }
                }
                SoPhuc e = matrix[0][i] * c.det();
                if (i % 2 == 0) {
                    d = d + e;
                } else {
                    d = d - e;
                }
            }
            return d;
        }

        Matrix conjunction() {
            Matrix c(row, col);
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    c.matrix[i][j] = matrix[i][j].conj();
                }
            }
            return c;
        }

        Matrix conjunction_transpose() {
            Matrix c = conjunction();
            return c.transpose();
        }




};

int main() {
    Matrix a, b;
    a.input();
    auto d = a.transpose();
    auto e = a.det();

    d.output();
    e.output();
    return 0;
}
