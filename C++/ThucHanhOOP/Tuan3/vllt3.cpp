#include <complex>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#define complex complex<double>
#define loop_ij(row,col) for (int i = 0; i < row; i++) for (int j = 0; j < col; j++)
#define loop_xy(row,col) for (int x = 0; x < row; x++) for (int y = 0; y < col; y++)
#define loop_i(row) for (int i = 0; i < row; i++)
#define loop_j(col) for (int j = 0; j < col; j++)
#define loop_k(col) for (int k = 0; k < col; k++)

using namespace std;


// bra is row vector, ket is column vector
class Matrix {
    private:
        vector<vector<complex>> a;
        // 1: scalar, 2: vector, 3: operator
        string type;
        bool bra; // 1: bra, 0: ket
        int row = 0;
        int col = 0;

    public:
        Matrix(int n = 0) {
            row = col = n;
            a.resize(n);
            loop_i(n) {
                a[i].resize(n);
            }
        }
        Matrix(int row, int col) {
            this->row = row;
            this->col = col;
            a.resize(row);
            loop_i(row) {
                a[i].resize(col);
            }
        }
        string getType() {
            return type;
        }

        void resize(int n) {
            row = col = n;
            a.resize(n);
            loop_i(n) {
                a[i].resize(n);
            }
        }
        void resize(int row, int col) {
            this->row = row;
            this->col = col;
            a.resize(row);
            loop_i(row) {
                a[i].resize(col);
            }
        }
        void operatorInput() {
            loop_ij(row,col) {
                double x, y;
                cin >> x >> y;
                a[i][j] = complex(x, y);
            }
            type = "operator";
        }
        void vectorInput() { // bra
            loop_i(col) {
                double x, y;
                cin >> x >> y;
                a[0][i] = complex(x, y);
            }
            type = "vector";
            bra = true;
        }
        void vectorInput2() { // ket
            loop_j(row) {
                double x, y;
                cin >> x >> y;
                a[j][0] = complex(x, y);
            }
            type = "vector";
            bra = false;
        }
        void scalarInput() {
            double x, y;
            cin >> x >> y;
            a[0][0] = complex(x, y);
            type = "scalar";
        }
        void output() {
            loop_i(row) {
                loop_j(col) {
                    cout << a[i][j].real() << " " << a[i][j].imag() << " ";
                }
                cout << endl;
            }
        }
        complex& operator() (int i, int j) {
            return a[i][j];
        }
        friend Matrix operator+(Matrix a, Matrix b) {
            Matrix c(a.row, a.col);
            loop_ij(c.row,c.col) {
                c(i,j) = a(i,j) + b(i,j);
            }
            return c;
        }
        Matrix operator!() {
            Matrix c(col, row);
            loop_ij(c.row,c.col) {
                c(i,j) = a[j][i];
            }
            bra = !bra;
            c.type = type;
            return c;
        }
        friend string multication_product(Matrix a, Matrix b) {
            if (a.type == "scalar") {
                return b.type;
            }
            else if (b.type == "scalar") {
                return a.type;
            }
            else if (a.type == "operator") {
                return b.type;
            }
            else if (b.type == "operator") {
                return a.type;
            }
            else if (a.type == "vector" and b.type == "vector") {
                if (a.bra and !b.bra) {
                    return "scalar"; // inner product
                }
                else if (!a.bra and b.bra) {
                    return "operator"; // outer product
                }
                else if (a.bra and b.bra) {
                    return "tensor operator"; // tensor product
                }
                else {
                    return "tensor operator"; // tensor product
                }
            } else {
                return "operator";
            }

        }
        friend Matrix operator*(Matrix a, Matrix b) {
            string type = multication_product(a, b);
            // if scalar, do bra*ket
            if (type == "scalar") {
                Matrix c(1);
                c(0, 0) = 0;
                loop_i(a.col) {
                    c(0, 0) += a(0, i) * b(i, 0);
                }
                c.type = "scalar";
                return c;
            } else if (type == "vector" or type == "operator") {
                if (a.col != b.row) {
                    return b*a; // noted
                }
                Matrix c(a.row, b.col);
                loop_ij(c.row,c.col) {
                    c(i,j) = 0;
                    loop_k(a.col) {
                        c(i,j) += a(i,k) * b(k,j);
                    }
                }
                c.type = type;
                if (type == "vector") {
                    if (a.bra) {
                        c.bra = true;
                    } else {
                        c.bra = false;
                    }
                }
                return c;
            } else {
                Matrix c(a.row*b.row, a.col*b.col);
                loop_ij(a.row,a.col) {
                    loop_xy(b.row,b.col) {
                        c(i*b.row+x, j*b.col+y) = a(i,j) * b(x,y);
                    }
                }
                c.type = "operator";
                return c;
            }
        }


};


Matrix calculate( string s, Matrix a[], int begin, int end) {
    if (begin == end) {
        return a[begin];
    }
    int i = begin;
    while (i < end) {
        if (s[i] == '(') {
            int j = i+1;
            int count = 1;
            while (count != 0) {
                if (s[j] == '(') {
                    count++;
                } else if (s[j] == ')') {
                    count--;
                }
                j++;
            }
            a[i] = calculate(s, a, i+1, j-2);
            i = j-1;
        }
        i++;
    }
    i = begin;
    while (i < end) {
        if (s[i] == '*') {
            a[i-1] = a[i-1] * a[i+1];
            for (int j = i; j < end; j++) {
                a[j] = a[j+2];
            }
            end -= 2;
            i--;
        }
        i++;
    }
    i = begin;
    while (i < end) {
        if (s[i] == '+') {
            a[i-1] = a[i-1] + a[i+1];
            for (int j = i; j < end; j++) {
                a[j] = a[j+2];
            }
            end -= 2;
            i--;
        }
        i++;
    }
    return a[begin];

};

int main() {
    int n;
    cin >> n;
    Matrix a[n];
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        if (m == 1) {
            a[i].resize(1, 1);
            a[i].scalarInput();
        } else if (m == 2) {
            int k;
            cin >> k;
            a[i].resize(1, k);
            a[i].vectorInput();
        } else {
            int k;
            cin >> k;
            a[i].resize(k, k);
            a[i].operatorInput();
        }
    }
    string s;
    cin >> s;
    //string s2 = "";
    //c<b|a|b> => c*(b*a*!b)
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            s2.push_back(s.substr(i, 1));
        } else 
    }
    //cout << s2 << endl;
    //calculate(s2, a, 0, s2.size()-1).output();

    return 0;
}

// bug 1: nhân bra với scalar không được
/*
3
1 2 0
2 2 1 0 0 0
3 2 1 0 0 0 0 0 -1 0
c<b|a|b>

2 0 0 0 
0 0 0 0 
input của thầy cho ra kết quả như thế, tuy nhiên theo logic thì kết quả phải là 2 0, vì operator c nhân với vector b thì kết quả vẫn là vector b
à ko, vậy là phải tính <b|a|b> trước, sau đó nhân với c mới đúng
*/
/*
input:
n: số các toán tử đặt tên từ a đến z. các toán tử này có thể là scalar (1), vector (2), operator (3)
n dòng tiếp theo là các toán tử đó, mỗi dòng là 1 toán tử bắt đầu bằng m = 1, 2, 3 tương ứng với scalar, vector, operator
    - nếu là scalar thì chỉ cần nhập 1 số phức
    - nếu là vector thì nhập số chiều k, và k số phức
    - nếu là operator thì nhập số chiều k, và k^2 số phức
tiếp theo, nhập vào biểu thức dưới dạng string, ví dụ:
    c<a|b|a>
định dạng chuỗi này thành cách phép toán phù hợp, ví dụ:
    c*a*b*!a
*/