#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class DV {
    protected:
        int tuoi;
        string name;
    public:
        DV(int tuoi = 0) {
            this->tuoi = tuoi;
        }
        int& getTuoi() {
            return tuoi;
        }
        virtual bool coTheSinh() {
            return tuoi == 3;
        }
        virtual DV* SinhCon() = 0;
        virtual int ChoSua() = 0;
};

class DanDV {
    private:
        vector<DV*> dv;

        int soLuong;
        int tongSua;
        int slDVTruongThanh = 0;
    public:
        DanDV(DV* dv, int soLuong) {
            this->soLuong = soLuong;
            this->dv.resize(soLuong);
            for (int i = 0; i < soLuong; i++) {
                this->dv[i] = dv->SinhCon();
                this->dv[i]->getTuoi() = dv->getTuoi(); 
                slDVTruongThanh ++;
            }
            tongSua = 0;
        }
        int size() {
            return soLuong;
        }
        void capNhat() {
            int soLuongCu = soLuong;
            soLuong += floor(slDVTruongThanh/2);
            dv.resize(soLuong);
            for (int i = soLuongCu; i < soLuong; i++) {
                dv[i] = dv[0]->SinhCon();
            }
            for (int i = 0; i < soLuongCu; i++) {
                dv[i]->getTuoi()++;
                if (dv[i]->coTheSinh()) {
                    slDVTruongThanh++;
                }
            }
            for (int i = 0; i < soLuong; i++) {
                tongSua += dv[i]->ChoSua();
            }




// sinh
// cho sữa

// cập nhật tuổi những người chưa sinh




            
        }
        DV* get(int i) {
            return dv[i];
        }
        int getSua() {
            return tongSua;
        }
};

class Bo : public DV {
    public:
        Bo(int i = 0) : DV(i) {
            name = "Bo";
        }
        Bo *SinhCon() override {
            return new Bo(0);
        }
        int ChoSua() override {
            if (tuoi <= 3) {
                return 0;
            }
            return 10;
        }
};

class Cuu : public DV {
    public:
        Cuu(int i = 0) : DV(i) {
            name = "Cuu";
        }
        Cuu *SinhCon() override {
            return new Cuu(0);
        }
        int ChoSua() override {
            if (tuoi <= 3) {
                return 0;
            }
            return 5;
        }

};

class De : public DV {
    public:
        De(int i = 0) : DV(i) {
            name = "De";
        }
        De *SinhCon() override {
            return new De(0);
        }
        int ChoSua() override {
            if (tuoi <= 3) {
                return 0;
            }
            return 8;
        }

};

class Tho : public DV {
    public:
        Tho(int i = 0) : DV(i) {
            name = "Tho";
        }
        bool coTheSinh() override {
            return tuoi == 1;
        }
        Tho *SinhCon() override {
            return new Tho(0);
        }
        int ChoSua() override {
            return 0;
        }

};

class TrangTrai {
    private:
        vector<DanDV*> dan;
        int turn;
    public:
        void Nhap() {
            int sl;
            cin >> sl;
            dan.push_back(new DanDV(new Bo(3), sl));
            cin >> sl;
            dan.push_back(new DanDV(new Cuu(3), sl));
            cin >> sl;
            dan.push_back(new DanDV(new De(3), sl));
            cin >> sl;
            dan.push_back(new DanDV(new Tho(1), sl));
            cin >> turn;          
        }

        void Chay() {
            for (int i = 0; i < turn; i++) {
                for (int j = 0; j < dan.size(); j++) {
                    dan[j]->capNhat();
                }
            }
        }
        void Xuat() {
            cout << "Bo: " << dan[0]->size() << "," << dan[0]->getSua() << endl;
            cout << "Cuu: " << dan[1]->size() << "," << dan[1]->getSua() << endl;
            cout << "De: " << dan[2]->size() << "," << dan[2]->getSua() << endl;
            cout << "Tho: " << dan[3]->size() << "," << dan[3]->getSua() << endl;
        }
};

int main() {
    TrangTrai tt;
    tt.Nhap();
    tt.Chay();
    tt.Xuat();
    return 0;
}
