#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

class Ban {
    protected:
        string name;
        int age;
        float thoiGianGap;
        int tongSoBan;


    public:
        virtual void Nhap() {
            cin >> name;
            cin >> age;   
        }
        virtual void Update(int tongSoBan) {
            this->tongSoBan = tongSoBan;
        }
        virtual void Xuat() {
            cout << "Ten: " << name << ", tuoi: " << age;
        }
        float getThoiGianGap() {
            return thoiGianGap;
        }
        virtual string getType() = 0;
};

class BanThan : public Ban {
    private:
        string sdt;
    public:
        void Nhap() override {
            Ban::Nhap();
            cin >> sdt;
            thoiGianGap = 5;
        }
        void Xuat() override {
            Ban::Xuat();
            cout << ", so dien thoai: " << sdt << endl;
        }
        string getType() override {
            return "BanThan";
        }
};

class BanTrai : public Ban {
    private:
        float income;
    public:
        void Nhap() override {
            Ban::Nhap();
            cin >> income;
            thoiGianGap = 5 * income / 10000000.0;
        }
        void Xuat() override {
            Ban::Xuat();
            cout << ", thu nhap: " << fixed << setprecision(0) << income <<  "d" << endl;
        }
        string getType() override {
            return "BanTrai";
        }
};

class BanTraiKhac : public Ban {
    private:
        float doHapDan;
    public:
        void Nhap() override {
            Ban::Nhap();
            cin >> doHapDan;
        }
        void Update(int tongSoBan) override {
            Ban::Update(tongSoBan);
            thoiGianGap = doHapDan * 20/ tongSoBan;
        }
        void Xuat() override {
            Ban::Xuat();
            string doThuHut;
            if (doHapDan >= 0.7) {
                doThuHut = "cao";
            } else if (doHapDan >= 0.4 and doHapDan < 0.7) {
                doThuHut = "trung binh";
            } else {
                doThuHut = "thap";
            }
            cout << ", do thu hut: " << doThuHut << endl;
        }
        string getType() override {
            return "BanTraiKhac";
        }
};

class BanBe {
    private:
        vector<Ban*> b;
    public:
        void Nhap() {
            int n;
            cin >> n;
            for (int i = 0; i < n; i++) {
                Ban* new_ban = []() -> Ban* {
                    int loai; cin >> loai;
                    switch (loai) {
                        case 1: return new BanThan;
                        case 2: return new BanTrai;
                        case 3: return new BanTraiKhac;
                        default: return NULL;
                    }
                }();
                new_ban->Nhap();
                b.push_back(new_ban);
            }
            for (int i = 0; i < b.size(); i++) {
                b[i]->Update(n);
            }
        }
        float tongTGBanThan() {
            float tongTG = 0;
            for (int i = 0; i < b.size(); i++) {
                if (b[i]->getType() == "BanThan") {
                    tongTG +=  b[i]->getThoiGianGap();
                }
            }
            return tongTG;
        }
        float tongTGBanTrai() {
            float tongTG = 0;
            for (int i = 0; i < b.size(); i++) {
                if (b[i]->getType() == "BanTrai") {
                    tongTG +=  b[i]->getThoiGianGap();
                }
            }
            return tongTG;
        }
        float tongTGBanTraiKhac() {
            float tongTG = 0;
            for (int i = 0; i < b.size(); i++) {
                if (b[i]->getType() == "BanTraiKhac") {
                    tongTG +=  b[i]->getThoiGianGap();
                }           
            }
            return tongTG;
        }
        vector<Ban*> nguoiQuanTrongNhat() {
            if (b.size() == 0) return vector<Ban*>();
            auto sortByTimeSpent = [](Ban* a, Ban* b) {
                return a->getThoiGianGap() > b->getThoiGianGap();
            };
            stable_sort(b.begin(), b.end(), sortByTimeSpent);
            Ban* quanTrongNhat = b[0];
            vector<Ban*> nhungNguoiQuanTrongNhat;
            for (int i = 0; i < b.size(); i++) {
                if (b[i]->getThoiGianGap() == quanTrongNhat->getThoiGianGap()) {
                    nhungNguoiQuanTrongNhat.push_back(b[i]);
                }
            }
            return nhungNguoiQuanTrongNhat;

        }
        void Xuat() {
            cout << "Thong ke: " << endl;
            if (tongTGBanThan() != 0)
                cout << "-Thoi gian cho ban than: " << tongTGBanThan() << " h" << endl;
            if (tongTGBanTrai() != 0)
                cout << "-Thoi gian cho ban trai: " << tongTGBanTrai() << " h" << endl;
            if (tongTGBanTraiKhac() != 0)
                cout << "-Thoi gian cho ban trai khac: " << tongTGBanTraiKhac() << " h" << endl;
            cout << "Nguoi ban quan trong nhat:" << endl;
            auto qt = nguoiQuanTrongNhat();
            for (int i = 0; i < qt.size(); i++) {
                qt[i]->Xuat();
            }
        }
};

int main() {
    BanBe bb;
    bb.Nhap();
    bb.Xuat();
    return 0;
}
