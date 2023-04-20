#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Diem {
    private:
        float toan = 0, van = 0, av = 0;
    public:
        Diem(float toan = 0, float van = 0, float av = 0) {
            this -> toan = toan;
            this -> van = van;
            this -> av = av;
        }
        bool Toan() {
            cin >> toan;
            if (toan < 0 or toan > 10)
                return false;
            return true;
        }
        bool Van() {
            cin >> van;
            if (van < 0 or van > 10)
                return false;
            return true;
        }
        bool Av() {
            cin >> av;
            if (av < 0 or av > 10)
                return false;
            return true;
        }
        float dToan() {
            return toan;
        }
        float dVan() {
            return van;
        }
        float dAV() {
            return av;
        }
        bool isValid() {
            if (toan < 0 or toan > 10)
                return false;
            if (van < 0 or van > 10)
                return false;
            if (av < 0 or av > 10)
                return false;
            return true;
        }
};

class Ngay {
    private:
        int ngay, thang, nam, dayNumber;
    public:
        Ngay(int ngay = 0, int thang = 0, int nam = 0) {
            this -> ngay = ngay;
            this -> thang = thang;
            this -> nam = nam;
            dayNumberGenerate();
        }
        void input() {
            do {
                string day, month, year;
                getline(cin,day,'/');
                getline(cin, month,'/');
                getline(cin,year, '\n');
                ngay = stoi(day);
                thang = stoi(month);
                nam = stoi(year);
                dayNumberGenerate();
            } while (not isValidDate());
        }
        bool isLeapYear() {
            if ((nam % 4 == 0 and nam % 100 != 0 ) or nam % 400 == 0)
                return true;
            return false;
        }
        bool isValidMonth() {
            if (thang < 1 or thang > 12)
                return false;
            return true;
        }
        bool isValidDay() {
            if (ngay < 1 or ngay > 31)
                return false;
            if (thang == 2) {
                if (isLeapYear() and ngay > 29)
                    return false;
                if (not isLeapYear() and ngay > 28)
                    return false;
            }
            if (thang == 4 or thang == 6 or thang == 9 or thang == 11) {
                if (ngay > 30)
                    return false;
            }
            return true;
        }
        bool isValidDate() {
            if (isValidMonth() and isValidDay())
                return true;
            return false;
        }
        int dayNumberGenerate() {
            int dayNumber = 0;
            int leap = 0;
            for (int i = 0; i < nam; i++) {
                if ((i % 4 == 0 and i % 100 != 0) or i % 400 == 0) {
                    dayNumber += 366;
                    leap ++;
                }
                else
                    dayNumber += 365;
            }
            for (int i = 1; i < thang; i++) {
                if (i == 1 or i == 3 or i == 5 or i == 7 or i == 8 or i == 10 or i == 12)
                    dayNumber += 31;
                else if (i == 2) {
                    if ((nam % 4 == 0 and nam % 100 != 0) or nam % 400 == 0)
                        dayNumber += 29;
                    else
                        dayNumber += 28;
                }
                else
                    dayNumber += 30;
            }
            dayNumber += ngay;
            this -> dayNumber = dayNumber;
            return dayNumber;
        }
        int khoangCach(Ngay x) {
            return abs(x.dayNumber - dayNumber);
        }
};

class HocSinh {
    private:
        string hoten;
        Ngay ngaysinh;
        Diem gk, ck;
    public:
        void input() {
            cin.ignore();
            getline(cin, hoten);
            ngaysinh.input();
            bool wrong = false;
            // do {
            //     gk.Toan(); ck.Toan();
            //     gk.Van(); ck.Van();
            //     gk.Av(); ck.Av();
            //     if (not gk.isValid() or not ck.isValid()) {
            //         //cout << "Nhap lai diem giua ky" << endl;
            //         wrong = true;
            //     }
            //     else
            //         wrong = false;
            // } while (wrong);
                do {
                    wrong = gk.Toan() and ck.Toan() and gk.Van() and ck.Van() and gk.Av() and ck.Av();
                } while (not wrong);
        }
        float TB() { 
            float TBToan = (gk.dToan()*3+ck.dToan()*7)/10;
            float TBVan = (gk.dVan()*3+ck.dVan()*7)/10;
            float TBAv = (gk.dAV()*3+ck.dAV()*7)/10;

            return round(100*((TBToan + TBVan + TBAv)/3))/100;
        }
        bool isPass() {
            float TBToan = (gk.dToan()*3+ck.dToan()*7)/10;
            float TBVan = (gk.dVan()*3+ck.dVan()*7)/10;
            float TBAv = (gk.dAV()*3+ck.dAV()*7)/10;
            if (TBToan < 7 or TBVan < 7 or TBAv < 7) {
                return false;
            } else if (gk.dToan() < 5 or ck.dToan() < 5 or gk.dVan() < 5
                    or ck.dVan() < 5 or gk.dAV() < 5 or ck.dAV() < 5) {
                        return false;
                    }
            return true;
        }
        bool is17() {
            Ngay hientai(1,1,2023);
            Ngay du17(1,1,2006);
            if (hientai.khoangCach(ngaysinh) >= hientai.khoangCach(du17))
                return true;
            return false;
        }
        bool isHSG() {
            if (is17() and TB() > 8 and isPass()) {
                return true;
            }
            return false;
        }
        friend bool operator>(HocSinh a, HocSinh b);
        friend bool operator<(HocSinh a, HocSinh b);
        void output() {
            cout << "Ho ten: " << hoten << " - Diem trung binh: " << TB() << '\n';
        }
};

bool operator<(HocSinh a, HocSinh b) {
if (a.TB() < b.TB())
    return true;
return false;
}

bool operator>(HocSinh a, HocSinh b) {
    if (a.TB() > b.TB())
        return true;
    return false;
}

class Lop {
    private:
        vector<HocSinh> hs;
        int n;
        int k;
    public:
        Lop(int n = 0) {
            hs.resize(n);
        }

        void input() {
            cin >> n;
            cin >> k;
            hs.resize(n);
            for (int i = 0; i < n; i++) {
                hs[i].input();
            }
            stable_sort(hs.begin(), hs.end(),greater<HocSinh>());
        }
        void output() {
            for (int i = 0; i < n; i++) {
                if (hs[i].isHSG())
                    hs[i].output();
            }
        }
};

int main() {
    Lop hs;
    hs.input();
    hs.output();
    return 0;
}
