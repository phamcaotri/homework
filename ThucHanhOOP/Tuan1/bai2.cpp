#include <iostream>
#include <vector>
#include <algorithm>
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

        PhanSo(const PhanSo &a) {
            this -> tu_so = a.tu_so;
            this -> mau_so = a.mau_so;
        }
        PhanSo(int tu_so = 0, int mau_so = 1) {
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

        float getValue() {
            return (float) tu_so/mau_so;
        }
        void simpify() {
            int GCD = gcd(tu_so,mau_so);
            tu_so /= GCD;
            mau_so /= GCD;
        }


};

int main() {
    int n, k;
    cin >> n >> k;
    vector<PhanSo> a(n);
    vector<float> b(n);
    if (k > n)
        return 0;
    for (int i = 0; i < n; i++) {
        a[i].input();
        b[i] = a[i].getValue();
    }
    sort(b.begin(),b.end()); 
    if (n-k < 0 or k-1 < 0)
        return 0;
    float max = b[n-k], min = b[k-1];
    for (int i = 0; i < n; i++) {
        if (a[i].getValue() == max)
            a[i].output();
    } 
    cout << '\n'; 
    for (int i = 0; i < n; i++) {
        if (a[i].getValue() == min)
            a[i].output();
    }






    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
