#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

const float PI = 3.14159;

class SoPhuc_Basic {
    private:
        float thuc;
        float ao;
    public:
        SoPhuc_Basic(float thuc = 0, float ao = 0) {
            this->thuc = thuc;
            this->ao = ao;
        }
        void input() {
            cin >> thuc >> ao;
        }
        float getThuc() {
            return thuc;
        }
        float getAo() {
            return ao;
        }
        float module() {
            return sqrt(thuc * thuc + ao * ao);
        }
        float pha() {
            return atan(ao / thuc);
        }
        void canBac(int n, int k = 0) {
            float moduleBacN = pow(module(), 1.0 / n);
            float phaBacN = (pha()+k*2*PI) / n;
            float thucBacN = moduleBacN * cos(phaBacN);
            float aoBacN = moduleBacN * sin(phaBacN);
            cout << round(thucBacN * 100) / 100 << " " << round(aoBacN * 100) / 100 << endl;
        }


};

int main() {
    SoPhuc_Basic bs;
    bs.input();
    int n; cin >> n;
    if (bs.getThuc() == 0 && bs.getAo() == 0) {
    for (int i = 0; i < n; i++) {
        cout << "0 0" << endl;

    }

        return 0;
    }
    
    for (int i = 0; i < n; i++) {
        bs.canBac(n,i);

    }
    return 0;
}
