#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class CPU {
    protected:
        string maSo;

        // output only
        string hangSX;
        string loai;
        int soCore;
        float xungNhip;

        // runtime defined
        float gia;
    public:
        void Nhap() {
            cin >> maSo;
        }
        float getGia() {
            return gia;
        }
        string getMaSo() {
            return maSo;
        }
        string getHangSX() {
            return hangSX;
        }
        string getLoai() {
            return loai;
        }
        int getSoCore() {
            return soCore;
        }
        float getXungNhip() {
            return xungNhip;
        }

};

    class Alpha : public CPU {
        public:
            Alpha() {
                CPU::Nhap();
                hangSX = "Black";
                loai = "Alpha";
                soCore = 2;
                xungNhip = 1.8;
                gia = 200;
            }
    };

    class Beta : public CPU {
        public:
            Beta() {
                CPU::Nhap();
                hangSX = "Black";
                loai = "Beta";
                soCore = 4;
                xungNhip = 2.46;
                gia = 400;
            }
    };

    class Gamma : public CPU {
        public:
            Gamma() {
                CPU::Nhap();
                hangSX = "White";
                loai = "Gamma";
                soCore = 4;
                xungNhip = 2.6;
                gia = 600;
            }
    };

class ManHinh {
    protected:
        string maSo;
        string hangSX;
        string doPhanGiai;
        // runtime defined
        float gia;
        int coChongLoa = 0;
    public:
        void Nhap(string maSo = "", string hangSX = "") {
            this->maSo = maSo;
            this->hangSX = hangSX;
        }
        float getGia() {
            return gia;
        }
        string getMaSo() {
            return maSo;
        }
        string getHangSX() {
            return hangSX;
        }
        string getDoPhanGiai() {
            return doPhanGiai;
        }
        string getCoChongLoa() {
            if (coChongLoa == 0) return "";
            return "Chong_loa";
        }


};

    class HD : public ManHinh {
        public:
            HD() {
                hangSX = "Black";
                gia = 200;
                doPhanGiai = "HD";
            }
    };

    class FullHD : public ManHinh {
        public:
            FullHD(int chongLoa = -1) {
                hangSX = "White";
                gia = 400;
                doPhanGiai = "FullHD";
                coChongLoa = [](int chongLoa) -> int {
                    if (chongLoa == -1) {
                        cin >> chongLoa;
                        return chongLoa;
                    }
                    return chongLoa;
                }(chongLoa);
            }
    };


class Vo {
    protected:
        string maSo;
        string loai;
        string mauSac;
        string hangSX;
        // runtime defined
        float gia;
    public:
        virtual void Nhap() {
            cin >> maSo;
        }
        float getGia() {
            return gia;
        }
        string getMaSo() {
            return maSo;
        }
        string getLoai() {
            return loai;
        }
        string getHangSX() {
            return hangSX;
        }
        string getMauSac() {
            return mauSac;
        }



};

    class VoNhom : public Vo {
        public:
            VoNhom() {
                hangSX = "Black";
                loai = "Nhom";
                gia = 400;
                Vo::Nhap();
                int ms; cin >> ms;
                mauSac = [](int ms) -> string {
                    switch (ms) {
                        case 1: return "Do";
                        case 2: return "Den";
                        default: return "Do";
                    }
                }(ms); 
            }
    };

    class VoNhua : public Vo {
        public:
            VoNhua() {
                hangSX = "White";
                loai = "Nhua";
                gia = 200;
                Vo::Nhap();
                int ms; cin >> ms;
                mauSac = [](int ms) -> string {
                    switch (ms) {
                        case 1: return "Do";
                        case 2: return "Den";
                        case 3: return "Xanh";
                        default: return "Do";
                    }
                }(ms); 
            }
    };


class SmartPhone {
    protected:
        string maSo;
        string dongSP;
        CPU cpu;
        ManHinh manHinh;
        Vo vo;
        float gia;
    public:
        virtual void Nhap() {
            cin >> maSo;
        }
        virtual void Xuat() = 0;
};

    class Venus : public SmartPhone {
        public:
            Venus() {
                dongSP = "Venus";
            }
            void Nhap() {
                SmartPhone::Nhap();
                int loaiCPU; cin >> loaiCPU;
                cpu = [](int loaiCPU) -> CPU {
                    switch (loaiCPU) {
                        case 1: return Alpha();
                        case 2: return Beta();
                        default: return Alpha();
                    }
                }(loaiCPU);
                string maSo; cin >> maSo;
                string hangSX; cin >> hangSX;
                int loaiManHinh; cin >> loaiManHinh;
                manHinh = [](int loaiManHinh) -> ManHinh {
                    switch (loaiManHinh) {
                        case 1: return HD();
                        case 2: return FullHD();
                        default: return HD();
                    }
                }(loaiManHinh);
                manHinh.Nhap(maSo, hangSX);

                int loaiVo; cin >> loaiVo;
                vo = [](int loaiVo) -> Vo {
                    switch (loaiVo) {
                        case 1: return VoNhom();
                        case 2: return VoNhua();
                        default: return VoNhom();
                    }
                }(loaiVo);

                // calculate gia
                float multiplier = [](string dongSP) -> float {
                    if (dongSP == "Venus") return 1.3;
                    if (dongSP == "Mars") return 1.5;
                    if (dongSP == "Jupiter") return 1.8;
                    return 0;
                }(dongSP);

                gia = cpu.getGia() + manHinh.getGia() + vo.getGia();
                gia *= multiplier;

            }
            void Xuat() {
                cout << "Smartphone: " << maSo << " " << dongSP << " " << gia << endl;
                cout << "CPU: " << cpu.getMaSo() << " " << cpu.getLoai() << " " << cpu.getHangSX() << " " << cpu.getSoCore() << " " << cpu.getXungNhip() << " " << cpu.getGia() << endl;
                cout << "Man hinh: " << manHinh.getMaSo() << " " << manHinh.getHangSX() << " " << manHinh.getDoPhanGiai() << " " << manHinh.getGia() << " " << manHinh.getCoChongLoa() << endl;
                cout << "Vo smartphone: " << vo.getMaSo() << " " << vo.getLoai() << " " << vo.getHangSX() << " " << vo.getMauSac() << " " << vo.getGia() << endl;
            }
    };

    class Mars : public SmartPhone {
        public:
            Mars() {
                dongSP = "Mars";
            }
            void Nhap() {
                SmartPhone::Nhap();
                int loaiCPU; cin >> loaiCPU;
                cpu = [](int loaiCPU) -> CPU {
                    switch (loaiCPU) {
                        case 1: return Alpha();
                        case 2: return Beta();
                        case 3: return Gamma();
                        default: return Alpha();
                    }
                }(loaiCPU);

                manHinh = FullHD();

                vo = VoNhom();
            }
            void Xuat() {

            }
    };

    class Jupiter : public SmartPhone {
        public:
            Jupiter() {
                dongSP = "Jupiter";
            }
            void Nhap() {
                SmartPhone::Nhap();

                cpu = Gamma();
                
                manHinh = FullHD(1);

                vo = VoNhom();
            }
            void Xuat() {

            }
    };


class XuLy {
    private:
        vector<SmartPhone*> SPs;
        
    public:
        XuLy() {
        }
        void Nhap() {
            int n; cin >> n;
            for (int i = 0; i < n; i++) {
                int dongSP; cin >> dongSP;
                SmartPhone* sp = [](int dongSP) -> SmartPhone* {
                    switch (dongSP) {
                        case 1: return new Venus();
                        case 2: return new Mars();
                        case 3: return new Jupiter();
                        default: return NULL;
                    }
                }(dongSP);
                sp->Nhap();
                SPs.push_back(sp);
            }
        }
        void Xuat() {
            for (int i = 0; i < SPs.size(); i++) {
                SPs[i]->Xuat();
            }
        }

        ~XuLy() {
            for (int i = 0; i < SPs.size(); i++) {
                delete SPs[i];
            }
        }
};


int main() {
    XuLy xuLy;
    xuLy.Nhap();
    xuLy.Xuat();
    return 0;
}
