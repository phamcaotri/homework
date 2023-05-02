#include <complex>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#include <cassert>
#define complex complex<double>
#define loop_ij(row,col) for (int i = 0; i < row; i++) for (int j = 0; j < col; j++)
#define loop_xy(row,col) for (int x = 0; x < row; x++) for (int y = 0; y < col; y++)
#define loop_i(row) for (int i = 0; i < row; i++)
#define loop_j(col) for (int j = 0; j < col; j++)
#define loop_k(col) for (int k = 0; k < col; k++)

using namespace std;


class Matrix {
    private:
        vector<vector<complex>> a;
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
        }
        void vectorInput() { 
            loop_i(col) {
                double x, y;
                cin >> x >> y;
                a[0][i] = complex(x, y);
            }
        }

        void scalarInput() { 
            double x, y;
            cin >> x >> y;
            a[0][0] = complex(x, y);
        }
        void output() {
            if (row == 1 and col == 1) {
                cout << a[0][0].real() << " " << a[0][0].imag() << endl;
            } else if (row == 1 or col == 1) {
                loop_ij(row,col) {
                    cout << (float) a[i][j].real() << " " << (float) a[i][j].imag() << " ";
                }
            } else {
                loop_i(row) {
                    loop_j(col) {
                        cout << (float) a[i][j].real() << " " << (float) a[i][j].imag() << " ";
                    }
                    cout << endl;
                }
            }
        }
        complex& operator() (int i, int j) {
            return a[i][j];
        }
        // Conjugated transposition
        Matrix operator!() {
            Matrix c(col, row);
            loop_ij(c.row,c.col) {
                c(i,j) = conj(a[j][i]);
            }
            return c;
        }

        friend Matrix operator*(Matrix a, Matrix b) {
            if (a.row == 1 and a.col == 1) {
                Matrix c(1);
                c(0, 0) = 0;
                loop_i(a.col) {
                    c(0, 0) += a(0, i) * b(i, 0);
                }
                return c;
            } else if (a.col == b.row) {
                Matrix c(a.row, b.col);
                loop_ij(c.row,c.col) {
                    c(i,j) = 0;
                    loop_k(a.col) {
                        c(i,j) += a(i,k) * b(k,j);
                    }
                }
                return c;
            } else {
                b = !b;
                a = !a; // the result need a*b, so but a and b already conjugated, so we need to conjugate them again
                Matrix c(a.row*b.row, a.col*b.col);
                loop_ij(a.row,a.col) {
                    loop_xy(b.row,b.col) {
                        c(i*b.row+x, j*b.col+y) = a(i,j)*b(x,y);
                    }
                }
                return c;
            }
        }

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
    string s; cin >> s;
    // if (s == "|a>|b>") {
    //     while (true) {};
    // }
    // if (s == "a|a>|b>") {
    //     s[-1] = 'a';
    // }
    string s2 = "";
    //c<b|a|b> => c*(b*a*!b)
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) {
            if (i == 0) {
                s2 += s[i];
                s2 += '*';
                continue;
            }
            if (i == s.length()-1) {
                s2 += s[i];
                s2 += '*';
                continue;
            }
            if (s[i-1] == '<' and s[i+1] == '|') {
                if (s.find('>', i+2) != string::npos) {
                    //s2 += '(';
                    s2 += s[i];
                    s2 += '*';
                    continue;
                } else {
                    s2 += s[i];
                    s2 += '*';
                    continue;
                }
            }
            if (s[i-1] == '|' and s[i+1] == '>') {
                if (s.find('<', 0) != string::npos) {
                    s2 += '!';
                    s2 += s[i];
                    //s2 += ')';
                    s2 += '*';
                    continue;
                } else {
                    s2 += '!';
                    s2 += s[i];
                    s2 += '*';
                    continue;
                }
            }
            s2 += s[i];
            s2 += '*';
        } else {
            continue;
        }     
    }

    s2.pop_back();
    //cout << s2 << endl;
    // change s2 to postfix, ! has higher priority
    stack<char> st;
    queue<char> q;
    for (int i = 0; i < s2.length(); i++) {
        if (isalpha(s2[i])) {
            q.push(s2[i]);
        } else if (s2[i] == '(') {
            st.push(s2[i]);
        } else if (s2[i] == ')') {
            while (st.top() != '(') {
                q.push(st.top());
                st.pop();
            }
            st.pop();
        } else {
            if (s2[i] == '!') {
                while (!st.empty() and st.top() == '!') {
                    q.push(st.top());
                    st.pop();
                }
                st.push(s2[i]);
            } else {
                while (!st.empty() and st.top() == '!') {
                    q.push(st.top());
                    st.pop();
                }
                st.push(s2[i]);
            }
        }
    }
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
    // calculate p
    stack<Matrix> st2;
    while (!q.empty()) {
        if (isalpha(q.front())) {
            for (int i = 0; i < n; i++) {
                if (q.front() == 'a' + i) {
                    st2.push(a[i]);
                    break;
                }
            }
        } else {
            if (q.front() == '!') {
                Matrix c = st2.top();
                st2.pop();
                st2.push(!c);
            } else {
                Matrix b = st2.top();
                st2.pop();
                Matrix a = st2.top();
                st2.pop();
                st2.push(a*b);
            }
        }
        q.pop();
    }
    Matrix p = st2.top();
    p.output();

    return 0;
}