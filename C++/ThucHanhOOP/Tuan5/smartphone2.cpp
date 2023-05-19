#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class SmartPhone {

};

class XuLy {
    private:
        vector<SmartPhone*> smartPhones;
    public:
        void Nhap() {
            int n; cin >> n;
            for (int i = 0; i < n; i++) {
                SmartPhone* newSmartPhone = new SmartPhone();
                newSmartPhone->Nhap();
                smartPhones.push_back(newSmartPhone);
            }
        }
        void Xuat() {


        }
};


int main() {
    XuLy xuLy;
    xuLy.Nhap();
    xuLy.Xuat();
    return 0;
}
