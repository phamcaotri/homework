#include <iostream>
using namespace std;

class PhanSo {
    private:
        int tu_so;
        int mau_so;
    public:
        PhanSo() {}
        PhanSo(const PhanSo &p) {}
        PhanSo(int tu_so, int mau_so) : tu_so(tu_so) , mau_so(mau_so) {}
        void setPhanSo() {
            cin >> tu_so;
            cin >> mau_so;
            

        }
        int getTuSo() {
            return tu_so;
        }

        int getMauSo() {
            return mau_so;
        }

        float getValuePhanSo() {
            if (mau_so != 0)
                return (float) tu_so/mau_so;
        }
    PhanSo Cong_PhanSo(PhanSo B) {
        return {(tu_so*B.getMauSo()+B.getTuSo()*mau_so),(mau_so*B.getMauSo())};
    }

    float Cong(PhanSo B) {
        return (float) (tu_so*B.getMauSo()+B.getTuSo()*mau_so)/(mau_so*B.getMauSo());
    }
    float Cong_Cach2(PhanSo B) {
        return (float) this -> getValuePhanSo() + B.getValuePhanSo();
    }

};




int main() {
    PhanSo A, B;
    A.setPhanSo();
    B.setPhanSo();
    cout << "Tong2 = " << A.Cong_Cach2(B) << '\n';
    cout << "Tong1 = " << A.Cong(B) << '\n';
    cout << A.Cong_PhanSo(B).getTuSo() << '/' << A.Cong_PhanSo(B).getMauSo();

    return  0;
}

