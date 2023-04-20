#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class DonThuc {
    private:
        int heso;
        int somu;
    public:
        DonThuc(int x = 0, int y = 0) {
            heso = x;
            somu = y;
        }
        void input(int x, int y) {
            heso = x;
            somu = y;
        }
        int getHeSo() {
            return heso;
        }
        int getSoMu() {
            return somu;
        }
        void output() {
            cout << heso << "x^" << somu;
        }
        bool operator<(DonThuc a) {
            if (somu < a.getSoMu())
                return true;
            if (somu == a.getSoMu() and heso < a.getHeSo())
                return true;
            return false;
        }
        bool operator>(DonThuc a) {
            if (somu > a.getSoMu())
                return true;
            if (somu == a.getSoMu() and heso > a.getHeSo())
                return true;
            return false;
        }
        bool operator==(DonThuc a) {
            if (somu == a.getSoMu() and heso == a.getHeSo())
                return true;
            return false;
        }
        bool operator!=(DonThuc a) {
            if (somu != a.getSoMu() or heso != a.getHeSo())
                return true;
            return false;
        }
        DonThuc operator+(DonThuc a) {
            DonThuc b;
            if (somu == a.getSoMu()) {
                b.input(heso + a.getHeSo(), somu);
            }
            else {
                b.input(heso, somu);
            }
            return b;
        }
        DonThuc operator-(DonThuc a) {
            DonThuc b;
            if (somu == a.getSoMu()) {
                b.input(heso - a.getHeSo(), somu);
            }
            else {
                b.input(heso, somu);
            }
            return b;
        }
        DonThuc operator*(DonThuc a) {
            DonThuc b;
            b.input(heso * a.getHeSo(), somu + a.getSoMu());
            return b;
        }

        
};

class DaThuc {
    private:
        int n;
        DonThuc *a;
    public:
        DaThuc(int n = 0) {
            this->n = n;
            a = new DonThuc[n+1];
            for (int i = 0; i <= n; i++) {
                a[i].input(0, i);
            }
        }
        void input() {
            cin >> n;
            a = new DonThuc[n+1];
            for (int i = 0; i <= n; i++) {
                int he_so; cin >> he_so;
                a[i].input(he_so, i);
            }
        }
        void output() {
            sort(a, a+n+1);
            for (int i = 0; i <= n; i++) {
                if (a[i].getHeSo() != 0) {
                    if (i != 0) {
                        if (a[i].getHeSo() > 0)
                            cout << "+";
                    }
                    a[i].output();
                }
            }
        }
        DonThuc& operator[](int i) {
            return a[i];
        }
        DaThuc operator+(DaThuc b) {
            DaThuc c(max(n, b.n));
            int j = 0, k = 0;
            for (int i = 0; i <= c.n; i++) { 
                if(a[j].getSoMu() == b[k].getSoMu()) {
                    c[i] = a[j] + b[k];
                    j++;
                    k++;
                }
                else if (a[j].getSoMu() > b[k].getSoMu()) {
                    c[i] = a[j];
                    j++;
                }
                else {
                    c[i] = b[k];
                    k++;
                }
            }
            return c;
        }
        DaThuc operator-(DaThuc b) {
            DaThuc c(max(n, b.n) );
            int j = 0, k = 0;
            for (int i = 0; i <= c.n; i++) { 
                if(a[j].getSoMu() == b[k].getSoMu()) {
                    c[i] = a[j] - b[k];
                    j++;
                    k++;
                }
                else if (a[j].getSoMu() > b[k].getSoMu()) {
                    c[i] = a[j];
                    j++;
                }
                else {
                    c[i] = b[k]*(-1);
                    k++;
                }
            }
            return c;
        }
        DaThuc operator*(DaThuc b) {
            DaThuc c(n + b.n);
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= b.n; j++) {
                    c[i+j] = c[i+j] + a[i]*b[j];
                }
            }
            return c;
        }

        DaThuc& operator=(DaThuc b) {
            n = b.n;
            a = new DonThuc[n+1];
            for (int i = 0; i <= n; i++) {
                a[i] = b[i];
            }
            return *this;
        }

};


int main() {
    DaThuc a, b, c;
    a.input();
    b.input();
    string s;
    cin >> s;
    if (s == "+")
        c = a + b;
    else if (s == "-")
        c = a - b;
    else if (s == "*")
        c = a * b;
    c.output();
    return 0;
}
