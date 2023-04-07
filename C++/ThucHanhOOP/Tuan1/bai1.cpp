#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a == 0  and b == 0)
        return 1;
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    return gcd(b,a%b);
}

class PhanSo {
    private:
        int tu_so;
        int mau_so;
    public:
        PhanSo() {};

        PhanSo(int tu_so, int mau_so) {
            this -> tu_so = tu_so;
            this -> mau_so = mau_so;
        }

        void input() {
            bool valid_input = false;
            cin >> tu_so;
            do {
                cin >> mau_so;
                if (mau_so != 0)
                    valid_input = true;
                    
            }while (not valid_input);
        }
        void output() {
            cout << tu_so << '/' << mau_so;
        }
        void simpify() {
            int GCD = gcd(tu_so,mau_so);
            tu_so /= GCD;
            mau_so /= GCD;
        }


};

int main() {
    int n;
    cin >> n;
    vector<PhanSo> a(n);
    for (int i = 0; i < n; i++) {
        a[i].input();
    }

    for (int i = 0; i < n; i++) {
        a[i].simpify();
        a[i].output();
        cout << '\n';
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
