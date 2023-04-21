#include <complex>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#define complex complex<double>
#define loop(row,col) for (int i = 0; i < row; i++) for (int j = 0; j < col; j++)
using namespace std;


// bra là vector dưới dạng hàng, ket là vector dưới dạng cột
class Matrix {
    private:
        vector<vector<complex>> a;
        // 1: scalar, 2: vector, 3: ma trận
        string type;
        bool bra; // 1: bra, 0: ket
        int row = 0;
        int col = 0;

    public:
        Matrix(int n = 0) { // khởi tạo ma trận dưới dạng operator hoặc bra
            row = col = n;
            a.resize(n);
            loop(n,0) {
                a[i].resize(n);
            }
        }
        Matrix(int row, int col) {
            this->row = row;
            this->col = col;
            a.resize(row);
            loop(row,0) {
                a[i].resize(col);
            }
        }
        void operatorInput() { // nhập ma trận dưới dạng operator
            loop(row,col) {
                double x, y;
                cin >> x >> y;
                a[i][j] = complex(x, y);
            }
            type = "operator";
        }
        void vectorInput() { // nhập vector dưới dạng bra
            loop(row, 0) {
                double x, y;
                cin >> x >> y;
                a[i][0] = complex(x, y);
            }
            type = "vector";
            bra = true;
        }
        void scalarInput() { // nhập số phức dưới dạng scalar
            double x, y;
            cin >> x >> y;
            a[0][0] = complex(x, y);
            type = "scalar";
        }
        void output() {
            loop(row,col) {
                cout << a[i][j] << " ";
            }
        }
        complex& operator() (int i, int j) {
            return a[i][j];
        }
        friend Matrix operator+(Matrix a, Matrix b) {
            Matrix c(a.row, a.col);
            loop(c.row,c.col) {
                c(i,j) = a(i,j) + b(i,j);
            }
            return c;
        }
        Matrix operator!() {
            Matrix c(col, row);
            loop(c.row,c.col) {
                c(i,j) = a[j][i];
            }
            bra = !bra;
            return c;
        }
        friend string multication_product(Matrix a, Matrix b) {
            if (a.type == "scalar") {
                return b.type;
            }
            if (b.type == "scalar") {
                return a.type;
            }
            if (a.type == "operator") {
                return b.type;
            }
            if (b.type == "operator") {
                return a.type;
            }
            if (a.type == "vector" and b.type == "vector") {
                if (a.bra and !b.bra) {
                    return "scalar"; // inner product
                }
                if (!a.bra and b.bra) {
                    return "operator"; // outer product
                }
                if (a.bra and b.bra) {
                    return "tensor operator"; // tensor product
                }
                if (!a.bra and !b.bra) {
                    return "tensor operator"; // tensor product
                }
            }

        }
        friend Matrix operator*(Matrix a, Matrix b) {
            string type = multication_product(a, b);
            // nếu là scalar thì triển khai thuật toán bra*ket
            if (type == "scalar") {
                Matrix c(1);
                c(0, 0) = 0;
                loop(a.row, a.col) {
                    c(0, 0) += a(i, 0) * b(0, i);
                }
                return c;
            }
        }


};


int main() {
    // vector<Matrix> m;
    // string s;
    // int n; cin >> n;
    // for (int i = 0; i < n; i++) {
    //     int type; cin >> type;
    //     if (type == 1) {
    //         int x, y; cin >> x >> y;
    //         Matrix a(x, y);
    //         m.push_back(a);
    //     } else if (type == 2) {
    //         int x; cin >> x;
    //         Matrix a(x);
    //         a.vectorInput();
    //         m.push_back(a);
    //     } else {
    //         int x; cin >> x;
    //         Matrix a(x);
    //         a.input();
    //         m.push_back(a);
    //     }
    // }
    // cin >> s;
    // bool flag = false;
    // Matrix temp;
    // for (int i = 0; i < s.size(), i++) {
    //     if (s[i] != '<' and s[i] != '>' and s[i] != '|') {
    //         if (m[s[i] - '0'].size() == 0) {
    //             temp = m[s[i] - '0'].Complex();
    //         }
    //         temp = m[s[i] - '0'];
    //         flag = true;
    //     }
    //     if (s[i] != '<' and s[i] != '>' and s[i] != '|' and flag) {
    //         temp = temp * m[s[i] - '0'];
    //     }

    // }
    Matrix a(2, 0);
    Matrix b(2);
    Matrix c(2);
    b.vectorInput();
    c.vectorInput();
    Matrix d = b*c;
    d.output();
    return 0;
}