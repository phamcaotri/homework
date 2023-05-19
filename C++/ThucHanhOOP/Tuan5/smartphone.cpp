#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class CPU {
    protected:
        string maCPU;
        int loaiCPU;
        string hangCPU;
        int soCoreCPU;
        float xungNhipCPU;
        int giaNhapCPU;
    public:
        CPU() {
            maCPU = string();
            loaiCPU = 0;
            hangCPU = string();
            soCoreCPU = 0;
            xungNhipCPU = 0;
            giaNhapCPU = 0;
        }
        void Nhap() {
            cin >> loaiCPU;
            cin >> maCPU;
        }
};

class Alpha : public CPU {
    public:
        Alpha() {
            loaiCPU = 1;
            hangCPU = "Black";
            soCoreCPU = 2;
            xungNhipCPU = 1.8;
            giaNhapCPU = 200;
        }
};

class Beta : public CPU {
    public:
        Beta() {
            loaiCPU = 2;
            hangCPU = "Black";
            soCoreCPU = 4;
            xungNhipCPU = 2.46;
            giaNhapCPU = 400;
        }
};

class Gamma : public CPU {
    public:
        Gamma() {
            loaiCPU = 3;
            hangCPU = "White";
            soCoreCPU = 4;
            xungNhipCPU = 2.6;
            giaNhapCPU = 600;
        }
};


class ManHinh {
    protected:
        string maMH;
        string hangSXMH;
        int giaNhapMH;
        float kichThuocMH;
    public:
        ManHinh() {
            maMH = string();
            hangSXMH = string();
            giaNhapMH = 0;
            kichThuocMH = 4.7;
        }
        void Nhap() {
            cin >> maMH;
            cin >> hangSXMH;
        }
};

class HD : public ManHinh {
    public:
        HD() : ManHinh() {
            giaNhapMH = 200;
        }
};

class FULLHD : public ManHinh {
    public:
        FULLHD() : ManHinh() {
            giaNhapMH = 300;
        }
};

class FULLHD_CL : public ManHinh {
    public:
        FULLHD_CL() : ManHinh() {
            giaNhapMH = 500;
        }
};

class Vo {
    protected:
        string maVo;
        int loaiVo;
        string hangSXVo;
        int giaNhapVo;
        int mauSacVo;

};

class VoNhom : public Vo {
    public:
        VoNhom() {
            loaiVo = 1;
            hangSXVo = "Black";
            giaNhapVo = 400;
            mauSacVo = 0;
        }

};

class VoNhua : public Vo {
    public:
        VoNhua() {
            loaiVo = 2;
            hangSXVo = "White";
            giaNhapVo = 200;
            mauSacVo = 0;
        }
};

class SmartPhone {
    protected:
        string maSP;
        int dongSP;
        int giaBanSP;
        Vo voSP;
        CPU cpuSP;
        ManHinh manHinhSp;
    public:
        virtual float giaBan() = 0;

        virtual void Nhap() {
            cin >> dongSP;
            cin >> maSP;
        }
};

class Venus : public SmartPhone {
    public:
        Venus() {
            dongSP = 1;
            cpuSP = CPU();
        }
        float giaBan() override {
            return 1.3 * giaBanSP;
        }
        void Nhap() override {
            SmartPhone::Nhap();
            cpuSP.Nhap();
            manHinhSp.Nhap();
            voSP.Nhap();
        }
};

class Mars : public SmartPhone {
    public:
        Mars() {
            dongSP = 2;
            cpuSP = CPU();
            manHinhSp = ManHinh();
            voSP = VoNhom();
        }
        float giaBan() override {
            return 1.5 * giaBanSP;
        }
        void Nhap() override {
            SmartPhone::Nhap();
            cpuSP.Nhap();
            manHinhSp.Nhap();
            voSP.Nhap();
        }
};

class Jupiter : public SmartPhone {
    public:
        Jupiter() {
            dongSP = 3;
            cpuSP = Gamma();
            manHinhSp = ManHinh();
            voSP = VoNhom();
        }
        float giaBan() override {
            return 1.8 * giaBanSP;
        }
        void Nhap() override {
            SmartPhone::Nhap();
            cpuSP = Gamma();
            manHinhSp = FULLHD_CL();
            voSP = VoNhom();
        }
};

class XuLy {
    private:
        vector<SmartPhone> dsSP;
    public:
        void nhap() {
            int n;
            cin >> n; // so luong sp
            for (int i = 0; i < n; i++) {
                int loaiSP;
                cin >> loaiSP;
                if (loaiSP == 1) {
                    Venus venus;
                    venus.Nhap();
                    dsSP.push_back(venus);
                }
                if (loaiSP == 2) {
                    Mars mars;
                    mars.Nhap();
                    dsSP.push_back(mars);
                }
                if (loaiSP == 3) {
                    Jupiter jupiter;
                    jupiter.Nhap();
                    dsSP.push_back(jupiter);
                }
            }
        }
        void xuat() {
            for (auto i : dsSP) {
                cout << i.giaBan() << endl;
            }
        }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
