#include <complex>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#define complex complex<double>

using namespace std;

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
            for (int i = 0; i < n; i++) {
                a[i].resize(n);
            }
        }

        Matrix(int row, int col) {
            this->row = row;
            this->col = col;
            a.resize(row);
            for (int i = 0; i < row; i++){
                a[i].resize(col);
            }
        }

        void resize(int n) {
            row = col = n;
            a.resize(n);
            for (int i = 0; i < n; i++) {
                a[i].resize(n);
            }
        }

        void resize(int row, int col) {
            this->row = row;
            this->col = col;
            a.resize(row);
            for (int i = 0; i < row; i++) {
                a[i].resize(col);
            }
        }


        void scalarInput() {
            double x, y;
            cin >> x >> y;
            a[0][0] = complex(x, y);
            type = "scalar";
        }

        void vectorInput() { // bra
            for (int i = 0; i < col; i++) {
                double x, y;
                cin >> x >> y;
                a[0][i] = complex(x, y);
            }
            type = "vector";
            bra = true;
        }

        void operatorInput() {
            for (int i = 0; i < row; i++) 
                for (int j = 0; j < col; j++) {
                double x, y;
                cin >> x >> y;
                a[i][j] = complex(x, y);
            }
            type = "operator";
        }

        void output() {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    cout << a[i][j].real() << " " << a[i][j].imag() << " ";
                }
                if (type != "vector") {
                    cout << endl;
                }
            }
        }

        complex& operator() (int i, int j) {
            return a[i][j];
        }

        Matrix operator!() {
            Matrix c(col, row);
            for (int i = 0; i < row; i++) 
                for (int j = 0; j < col; j++) {
                    c(j, i) = a[i][j];
                }
            c.type = type;
            c.bra = !bra;
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
                for (int i = 0; i < a.col; i++){
                    c(0, 0) += a(0, i) * b(i, 0);
                }
                c.type = "scalar";
                return c;
            } else if (type == "vector" or type == "operator") {
                if (a.col != b.row) {
                    return b*a; // noted
                }
                Matrix c(a.row, b.col);
                for (int i = 0; i < c.row; i++) 
                    for (int j = 0; j < c.col; j++) {
                        c(i,j) = 0;
                        for (int k = 0; k < a.col; k++){
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
                for (int i = 0; i < a.row; i++) 
                    for (int j = 0; j < a.col; j++)  {
                        for (int x = 0; x < b.row; x++) 
                            for (int y = 0; y < b.col; y++) {
                                c(i*b.row+x, j*b.col+y) = a(i,j) * b(x,y);
                            }
                        }
                c.type = "operator";
                return c;
            }
        }

};

int main() {
    int n; cin >> n;
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