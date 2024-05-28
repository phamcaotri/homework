





// Viết chương trình quản lý các loại súng cho một player trong Freefire. Mỗi cây súng đều có thông tin là tên súng, kích thước băng đạn, sát thương, tốc độ bắn, thời gian nạp đạn mất trung bình 2s ch mọi loại súng. Có 3 loại súng:

// Súng ngắn: G18 (Số loại 1, băng 12 viên, ST 2, 1 viên / s), M500 (Số loại 2, băng 5 viên ST 4, 0.5 viên / s)
// Súng trường: MP40 (Số loại 3, băng 20 viên, ST 3, 5 viên / s), AK (Số loại 4, băng 30 viên, ST 5, 1 viên / s). Sức sát thương của súng trường được cộng thêm nhờ skin.
// Súng bắn tỉa: SVD (Số loại 5, băng 10 viên, ST 5, 0.5 viên / s), AWM (Số loại 6, băng 5 viên, ST 10, 0.5 viên / s). Súng bắn tỉa bị cộng thêm 1 s mỗi viên do phải nạp lại.
// Sát thương và tốc độ bắn bị giảm theo độ hao mòn (0 đến 1), sát thương = độ hao mòn * sát thương gốc, tốc độ bắn chậm gấp đôi tốc độ bắn gốc. Nếu độ hao mòn bằng 1, không có ảnh hưởng gì, hiệu ứng hao mòn áp dụng trước các hiệu ứng khác.

// Nhập vào số lượng súng n, sau đó nhập vào thông tin của từng súng.

// [Số loại] [số lượng băng đạn] [độ hao mòn] [sát thương cộng thêm nếu là súng trường]
// Sau đó nhập vào thời gian bắn súng t. Và xuất ra tổng lượng sát thương của từng súng trên n dòng theo định dạng:

// [Tên]: [Tổng sát thương]

// Sample Input 0

// 3
// 1 3 0.9
// 3 2 0.8 2
// 4 1 1 2
// 15
// Sample Output 0

// G18: 14.4
// MP40: 145.2
// AK: 105

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Sung {
    protected:
        string tenSung;
        int soDan;
        float satThuong;
        float tocDoBan;
        const float thoiGianNapDan = 2;
        int soLuongBanDan;
        float doHaoMon;
    public:
        Sung(string tenSung, int soDan, float satThuong, float tocDoBan) {
            this->tenSung = tenSung;
            this->soDan = soDan;
            this->satThuong = satThuong;
            this->tocDoBan = tocDoBan;            
        }
        virtual void Nhap() {
            cin >> soLuongBanDan;
            cin >> doHaoMon;
        }
        virtual void Xuat(float thoiGianBan) {
            cout << tenSung << ": " << getTongSatThuong(thoiGianBan) << endl;
        }
        virtual float getTongSatThuong(float thoiGianBan) {
            float tongSatThuong = 0;
            int danTrongBangHienTai = soDan;
            while (true) {
                if (thoiGianBan <= 0) return tongSatThuong;
                if (soLuongBanDan <= 0) return tongSatThuong;
                if (danTrongBangHienTai == 0) {
                    danTrongBangHienTai = soDan;
                    thoiGianBan -= thoiGianNapDan;
                    soLuongBanDan --;
                    continue;
                } 
                tongSatThuong += satThuong;
                danTrongBangHienTai --;
                thoiGianBan -= 1.0/tocDoBan;
            }
        }
};

class SungNgan : public Sung {
    public:
        using Sung::Sung;
        void Nhap() override {
            Sung::Nhap();
            satThuong *= doHaoMon;
            if (doHaoMon != 1) {
                tocDoBan /= 2.0;
            }
        }

};

class SungTruong : public Sung {
    private:
        float satThuongCongThem;
    public:
        using Sung::Sung;
        void Nhap() override {
            Sung::Nhap();
            satThuong *= doHaoMon;
            if (doHaoMon != 1) {
                tocDoBan /= 2;
            }
            cin >> satThuongCongThem;
            satThuong += satThuongCongThem;
        }
};

class SungBanTia : public Sung {
    public:
        using Sung::Sung;
        void Nhap() override {
            Sung::Nhap();
            satThuong *= doHaoMon;
            if (doHaoMon != 1) {
                tocDoBan /= 2;
            }
        }
        float getTongSatThuong(float thoiGianBan) override {
            float tongSatThuong = 0;
            int danTrongBangHienTai = soDan;
            while (true) {
                if (thoiGianBan <= 0) return tongSatThuong;
                if (soLuongBanDan <= 0) return tongSatThuong;
                if (danTrongBangHienTai == 0) {
                    danTrongBangHienTai = soDan;
                    thoiGianBan -= thoiGianNapDan;
                    soLuongBanDan --;
                    continue;
                } 
                tongSatThuong += satThuong;
                danTrongBangHienTai --;
                thoiGianBan -= 1.0/tocDoBan +1;
            }
        }
};

class QuanLySung {
    private:
        vector<Sung*> sung;
        float tgBan;

    public:
        void Nhap() {
            int soLuong;
            cin >> soLuong;
            for (int i = 0; i < soLuong; i++) {
                Sung* new_sung = []() -> Sung* {
                    int loai;
                    cin >> loai;
                    switch (loai) {
                        case 1: return new SungNgan("G18", 12, 2, 1);
                        case 2: return new SungNgan("M500", 5, 4, 0.5);
                        case 3: return new SungTruong("MP40", 20, 3, 5);
                        case 4: return new SungTruong("AK", 30, 5, 1);
                        case 5: return new SungBanTia("SVD", 10, 5, 0.5);
                        case 6: return new SungBanTia("AWM", 5, 10, 0.5);
                        default: return NULL;
                    }
                }();
                new_sung->Nhap();
                sung.push_back(new_sung);
            }
            cin >> tgBan;
        }
        void Xuat() {
            for (int i = 0; i < sung.size(); i++) {
                sung[i]->Xuat(tgBan);
            }

        }
};

int main() {
    QuanLySung ql;
    ql.Nhap();
    ql.Xuat();
    return 0;
}


// Kaguya có rất nhiều bạn: bao gồm bạn thân (BestFriend), bạn trai (BoyFriend) và các bạn trai khác (OtherBoy). Tất cả những người bạn đều cần lưu thông tin bao gồm tên (name, không có khoảng trắng) và độ tuổi (age, từ 0 đến 100).

// Bạn thân (loại 1) cần lưu thêm số điện thoại (phone), thời gian dành cho bạn thân là 5h / tuần.
// Bạn trai (loại 2) lưu thêm mức thu nhập (income), thời gian dành cho bạn trai là 5 * income / 10000000.0 / tuần.
// Bạn trai khác (loại 3) thì là độ hấp dẫn (attractiveness, có giá trị từ 0 đến 1), thời gian dành cho bạn trai khác là độ hấp dẫn * 20 / tổng số bạn.
// Viết chương trình nhập vào thông tin của n người bạn, mỗi người bạn sẽ nhập trên cùng một dòng lần lượt:

// [tên] [tuổi] [thông tin phụ: số điện thoại, mức thu nhập hoặc độ hấp dẫn] 
// Sau đó xuất ra thống kê thời gian dành cho mỗi loại bạn / tuần theo định dạng của sample test case (lưu ý giả sử nếu không có bạn trai khác, thì không cần thống kê thời gian dành ra cho bạn trai khác, tương tự với những loại bạn khác). Cuối cùng là xuất ra thông tin người bạn quan trọng nhất (dành nhiều thời gian nhất, nếu k người có thời gian bằng nhau thì xuất k người theo thứ tự đã nhập), với mỗi người theo định dạng:

// Ten: [name], tuoi: [age], so dien thoai: [phone]
// hoặc:

// Ten: [name], tuoi: [age], thu nhap: [income]d
// hoặc:

// Ten: [name], tuoi: [age], do thu hut: [level]* (level = 'cao' nếu độ thu hút >= 0.7, 'trung binh' nếu độ thu hút >= 0.4 và < 0.7, 'thap' nếu độ thu hút < 0.4)
// Xuất ra kết quả tính tính với định dạng:

// Thong ke:
// -Thoi gian cho ban than: ... h
// -Thoi gian cho ban trai: ... h
// -Thoi gian cho ban trai khac: ... h
// Nguoi ban quan trong nhat:
// [Ten: [name], tuoi: [age], ...]
// image

// Input Format

// int

// [string int ...]

// Constraints

// No constraint

// Output Format

// string

// Sample Input 0

// 4
// 1 banthan 23 012345
// 2 bantrai 23 15000000
// 3 bantrai1 23 0.5
// 3 bantrai2 24 0.7
// Sample Output 0

// Thong ke:
// -Thoi gian cho ban than: 5 h
// -Thoi gian cho ban trai: 7.5 h
// -Thoi gian cho ban trai khac: 6 h
// Nguoi ban quan trong nhat:
// Ten: bantrai, tuoi: 23, thu nhap: 15000000d

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

// Overlord là một seri anime thể loại chuyển sinh, tại đây nhân vật chính là Momonga phiêu lưu vào thế giới thần thoại đầy rẫy quái vật. Để làm nhiệm vụ nguy hiểm, như tiêu diệt boss, con người ở đây tạo ra Guild, một Guild sẽ bao gồm n thành viên thực hiện chung một nhiệm vụ nào đó, mỗi thành viên có tên và các chỉ số HP, ATK và DEF.

// HP là chỉ số sinh mệnh, nếu HP <=0 thì coi như đã chết, không còn khả năng ATK.
// ATK là chỉ số tấn công, DEF là chỉ số phòng thủ, mỗi lượt đánh sẽ gây sát thương (tức là trừ vào HP của đối phương) một lượng là (ATK bản thân – DEF đối phương), nếu DEF của đối phương cao hơn thì coi như sát thương là 0.
// Mỗi thành viên trong Guild có thể là:

// Nhân loại (có thêm thuộc tính job class): bao gồm Human (loại 1) và Elf (loại 2). Người không có khả năng gì thêm, còn Elf được + 50% DEF dựa trên DEF nhập vào.
// Bán nhân (có thêm thuộc tính racial class): bao gồm Orc (loại 3) và Golbin (loại 4). Orc được +50% HP dựa trên HP nhập vào, Golbin được + 10% ATK dựa trên ATK nhập vào.
// Dị hình: bao gồm Vampire (loại 5) và Devil (loại 6), Vampire được +10% HP / mỗi thành viên Guild là nhân loại, Devil được +10% ATK và +10% DEF / mỗi Devil trong Guild.
// Sau khi nhập các thông tin cho Guild, Giả sử Guild đi đánh Boss, hãy tính khả năng chiến thắng. Biết rằng 2 bên sẽ đánh nhau theo lượt, và bên Guild sẽ tấn công trước còn Boss sẽ ưu tiên tấn công thành viên ít máu nhất.

// Input:

// [Số lượng]*
// [[loại] [tên] [HP] [ATK] [DEF] [Thông tin thêm]]
// [Tên boss] [HP] [ATK] [DEF]
// Output:

// Nếu chiến thắng, xuất ra danh sách các thành viên còn sống theo thứ tự HP thấp đến cao:

// [[Tên] [HP]]
// Nếu thua hoặc quá 100 lượt mà chưa có kết quả, xuất ra thông tin HP còn lại của Boss:

// [Tên boss] [HP]
// image

// Tham khảo lời giải tại: BHT CNPM

// Input Format

// int

// [int string float float float string]

// string float float float

// Constraints

// No constraint

// Output Format

// [string float]

// Sample Input 0

// 3
// 1
// Adam 100 10 10 NongDan
// 2 Vi 200 10 10 CungThu
// 6 Jacob 400 50 30
// Ainz 200 50 20
// Sample Output 0

// Vi 130
// Jacob 400


#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

class Character {
    protected:
        string name;
        float hp;
        float atk;
        float def;
        vector<int> guild;

    public:
        virtual void Nhap() {
            cin >> name;
            cin >> hp;
            cin >> atk;
            cin >> def;
        }
        void Xuat() {
            cout << name << ' ' << hp << '\n';
        }
        float getAtk() {
            return atk;
        }
        float getDef() {
            return def;
        }
        float getHp() {
            return hp;
        }
        void changeHp(float x) {
            hp += x;
        }
        virtual void UpdateGuild(vector<int> x) {
            guild = x;
        }

};

class NhanLoai : public Character {
    protected:
        string job;
    public:
        void Nhap() override {
            Character::Nhap();
            cin >> job;
        }
};

class Human : public NhanLoai {
};

class Elf : public NhanLoai {
    public:
        void Nhap() override {
            NhanLoai::Nhap();
            def += def*50/100.0;
        }
};
    
class BanNhan : public Character {
    protected:
        string racial;
    public:
        void Nhap() override {
            Character::Nhap();
            cin >> racial;
        }        
};

class Orc : public BanNhan {
    public:
        void Nhap() override {
            BanNhan::Nhap();
            hp += hp*50/100.0;
        }
};

class Golbin : public BanNhan {
    public:
        void Nhap() override {
            BanNhan::Nhap();
            atk += atk*10/100.0;
        }
};

class DiHinh : public Character {
};

class Vampire : public DiHinh {
    public:
        void Nhap() override {
            DiHinh::Nhap();
        }
        void UpdateGuild(vector<int> x) override {
            Character::UpdateGuild(x);
            int soHuman = guild[0] + guild[1];
            hp += soHuman*hp*10/100.0;
        }
};

class Devil : public DiHinh {
    public:
        void Nhap() override {
            Character::Nhap();
        }
        void UpdateGuild(vector<int> x) override {
            Character::UpdateGuild(x);
            int soDevil = guild[5];
            atk += soDevil*atk*10/100.0;
            def += soDevil*def*10/100.0;
        }
};


class BossBattle {
    private:
        vector<Character*> c;
        Character * boss;
    public:
        void Nhap() {
            int n; cin >> n;
            c.resize(n);
            vector<int> guild(6,0);
            for (int i = 0; i < n; i++) {
                c[i] = [ & ]() -> Character* {
                    int loai; cin >> loai;
                    guild[loai-1]++;
                    switch (loai) {
                        case 1: return new Human;
                        case 2: return new Elf;
                        case 3: return new Orc;
                        case 4: return new Golbin;
                        case 5: return new Vampire;
                        case 6: return new Devil;
                        default: return NULL;
                    }
                }();
                c[i]->Nhap();

            }
            for (int i = 0; i < n; i++) {
                c[i]->UpdateGuild(guild);
            }
            boss = new Character;
            boss->Nhap();
            auto HpThapDenCao = [](Character* a, Character* b) {
                return a->getHp() < b->getHp();
            };
            stable_sort(c.begin(), c.end(), HpThapDenCao);
            
        }
        void Xuat() {
            if (Action() == 1) {
                for (int i = 0; i < c.size(); i++) {
                    if (c[i]->getHp() > 0) c[i]->Xuat();
                }
            } else {
                boss->Xuat();
            }
        }
        float DmgCal(Character* a, Character* b) {
            if (a->getHp() <= 0)
                return 0;
            float atk = a->getAtk();
            if (atk == 0) return 0;
            float def = b->getDef();
            float st = atk - def;
            if (st <= 0) return 0;
            return st;
        }

        bool Action() {
            int turn = 1;
            while (turn <= 100) {
                for (int i = 0; i < c.size(); i++) {
                    float stBoss = DmgCal(c[i], boss);
                    boss->changeHp(-stBoss);
                    if (boss->getHp() <= 0) {
                        return 1;
                    }
                }
                Character* cHpThapNhat = [&]() -> Character* {
                    if (c.size() > 0) return c[0];
                    return NULL;
                }();
                if (cHpThapNhat == NULL) return 0;
                float stCharacter = DmgCal(boss, cHpThapNhat);
                cHpThapNhat->changeHp(-stCharacter);
                if (c[0]->getHp() <= 0) {
                    c.erase(c.begin());
                }
                turn ++;
            }
            return 0;
        }
};

int main() {
    BossBattle bt;
    bt.Nhap();
    bt.Xuat();
    return 0;   
}


// Trong quá trình đi làm trừ nợ cho nhà quan thống lý. Ngày nào A Phủ cũng phải đốt rừng, cày nương, cuốc nương, săn bò tót, bẫy hổ, chăn bò chăn ngựa, quanh năm một thân một mình rong ruổi ngoài gò rừng. Hãy tính toán khả năng A Phủ trở về nhà an toàn sau một ngày làm việc bằng cách nhập những thông tin vũ khí và thú dữ A Phủ gặp phải.

// Vũ khí có 3 loại: dao, cung tên và tay không.

// Dao (loại 1): chỉ số sát thương, số lượt sử dụng, chiều dài. Sát thương mỗi lượt sử dụng được tính bằng chỉ số sát thương * chiều dài. Số lượt sử dụng giảm 1 mỗi lần sử dụng.
// Cung tên (loại 2): chỉ số sát thương, số lượt sử dụng, số mũi tên. Sát thương mỗi lượt sử dụng được tính bằng chỉ số sát thương * số mũi tên / 2. Số lượt sử dụng giảm 2 mỗi lần sử dụng.
// Tay không: chỉ số sát thương, số lượt sử dụng vô tận. Sát thương mỗi lượt chính bằng chỉ số sát thương = 10% HP tối đa, tuy nhiên mỗi lần sử dụng sẽ tự giảm lượng HP bằng 10% HP tối đa. Tay không luôn là vũ khí được sử dụng sau cùng, không cần nhập.
// Thú dữ có 2 loại: bò tót và hổ:

// Bò tót (loại 1): chỉ số HP, chỉ số sát thương, số lần chịu đánh. Sát thương mỗi lượt bằng chỉ số sát thương. Chỉ bị hạ gục khi số lần chịu đánh về 0 hoặc HP <= 0.
// Hổ (loại 2): chỉ số HP, chỉ số sát thương. Sát thương mỗi lượt bằng 1.5 chỉ số sát thương. Bị hạ gục khi HP <= 0.
// B1: Nhập vào lượng HP tối đa của A Phủ hiện tại.

// B2: Nhập vào số lượng vũ khí mà A Phủ đem theo (n), mỗi vũ khí nhập trên một dòng, thứ tự nhập là:

// [loại] [chỉ số sát thương] [số lượt sử dụng] [chiều dài / số mũi tên]
// B3: Nhập vào số lượng thú dữ (m), mỗi thú dữ nhập trên một dòng, thứ tự nhập là:

// [loại [chỉ số HP] [chỉ số sát thương] [số lần chịu đánh nếu là bò tót]
// B4: Tính toán theo các bước, thứ tự sử dụng vũ khí và thú dữ xuất hiện theo đúng như thứ tự đã nhập.

// A Phủ sẽ tấn công thú dữ trước => vũ khí bị giảm số lượng sử dụng (nếu vũ khí có số lần sử dụng <= 0 thì lượt tấn công tiếp theo sử dụng vũ khí tiếp theo) => A Phủ gây ra lượng sát thương lên thú dữ => Nếu thú dữ chưa chết, chúng gây ra một lượng sát thương ngược lại cho A Phủ, ngược lại thú dữ tiếp theo sẽ được xuất hiện ở lượt kế tiếp => A Phủ lại bắt đầu tấn công.

// B5: Xuất ra thông tin về kết quả ngày đi làm của A Phủ như sau:

// Nếu A Phủ tiêu diệt được tất cả thú rừng, xuất ra:

// A Phu chien thang, hp con lai: [hp còn lại], so luong vu khi con lai: [số lượng vũ khí còn lại, không tính tay không]
// Nếu HP của A Phủ thấp hơn hoặc bằng 0, xuất ra:

// A Phu that bai, so thu du con lai: [số lượng thú dữ còn lại]
// image

// Input Format

// float

// int

// [int float int float]

// int

// [int float float]

// Constraints

// No constraint

// Output Format

// String

// Sample Input 0

// 30
// 3
// 1 5 2 1.1
// 1 2 1 1.3
// 2 3 3 4
// 3
// 1 100 3 5
// 2 40 2
// 1 50 5 3
// Sample Output 0

// A Phu that bai, so thu du con lai: 2
// Explanation 0

// image

// Sample Input 1

// 100
// 3
// 1 20 3 1.5
// 1 30 2 2
// 2 3 3 4
// 3
// 1 100 3 3
// 2 40 2
// 2 10 2
// Sample Output 1

// A Phu chien thang, hp con lai: 94, so vu khi con lai: 1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

class APhu {
    private:
        float hp;
        float maxHp;
    public:
        virtual void Nhap() {
            cin >> hp;
            maxHp = hp;
        }
        float getHp() {
            return hp;
        }
        float getMaxHp() {
            return maxHp;
        }
        void changeHp(float x) {
            hp += x;
        }
};

class VuKhi {
    protected:
        float atk;
        int soLuotSuDung;

        APhu* a;
    public:
        VuKhi(APhu* a) {
            this-> a = a;
        }
        virtual void Nhap() {
            cin >> atk;
            cin >> soLuotSuDung;
        }
        virtual float DmgCal() = 0;
        int getSoLuotSuDung() {
            return soLuotSuDung;
        }
};

class Dao : public VuKhi {
    private:
        float chieuDai;
    public:
        using VuKhi::VuKhi;
        void Nhap() override {
            VuKhi::Nhap();
            cin >> chieuDai;
        }
        float DmgCal() override {
            soLuotSuDung--;
            return atk * chieuDai;
        }
};

class CungTen : public VuKhi {
    private:
        int soMuiTen;
    public:
        using VuKhi::VuKhi;
        void Nhap() override {
            VuKhi::Nhap();
            cin >> soMuiTen;
        }
        float DmgCal() override {
            soLuotSuDung -= 2;
            return atk * soMuiTen / 2.0;
        }
};

class TayKhong : public VuKhi {
    public:
        TayKhong(APhu* a) : VuKhi(a) {
            atk = 0;
            soLuotSuDung = 1;
        }
        void Nhap() override {
            return;
        }
        float DmgCal() override {
            float st = 10/100.0 * a->getMaxHp();
            a->changeHp(-st);
            return st;
            
        }
};

class ThuDu {
    protected:
        float hp;
        float atk;
    public:
        virtual void Nhap() {
            cin >> hp;
            cin >> atk;
        }
        virtual float DmgCal() = 0;

        float getHp() {
            return hp;
        }
        void changeHp(float x) {
            hp += x;
        }

};

class BoTot : public ThuDu {
    private:
        int soLanChiuDanh;
    public:
        void Nhap() override {
            ThuDu::Nhap();
            cin >> soLanChiuDanh;
        }
        float DmgCal() override {
            soLanChiuDanh--;
            if (soLanChiuDanh == 0) return 0;
            if (hp <= 0) return 0;
            return atk;
        }
};

class Ho : public ThuDu {
    public:
        void Nhap() override {
            ThuDu::Nhap();
        }
        float DmgCal() override {
            if (hp <= 0) return 0;
            return atk*1.5;
        }
};

class Battle {
    private:
        APhu* a;
        list<VuKhi*> v;
        list<ThuDu*> t;
    public:
        void Nhap() {
            a = new APhu();
            a->Nhap();
            int n; cin >> n;
            for (int i = 0; i < n; i++) {
                VuKhi* vk = [&]() -> VuKhi* {
                    int type; cin >> type;
                    switch (type) {
                        case 1: return new Dao(a);
                        case 2: return new CungTen(a);
                        default: return NULL;
                    }
                }();
                vk->Nhap();
                v.push_back(vk);
            }
            v.push_back(new TayKhong(a));
            int m; cin >> m;
            for (int i = 0; i < m; i++) {
                ThuDu* td = []() -> ThuDu* {
                    int type; cin >> type;
                    switch (type) {
                        case 1: return new BoTot();
                        case 2: return new Ho();
                        default: return NULL;
                    }
                }();
                td->Nhap();
                t.push_back(td);
            }
        }
        bool Action() {
            while (true) {
                if (a->getHp() <= 0) return false;
                if (t.size() == 0) return true;

                float dmgAPhu = v.front()->DmgCal();
                if (v.front()->getSoLuotSuDung() <= 0) {
                    v.pop_front();
                }
                t.front()->changeHp(-dmgAPhu);
                float dmgThuDu = t.front()->DmgCal();
                if (dmgThuDu <= 0) {
                    t.pop_front();
                    continue;
                }
                a->changeHp(-dmgThuDu);
            }
        }
        void Xuat() {
            if (Action()) {
                cout << "A Phu chien thang, hp con lai: " << a->getHp();
                cout << ", so vu khi con lai: " << v.size()-1;
                
            } else {
                cout << "A Phu that bai, so thu du con lai: " << t.size();
            }
        }
};

int main() {
    Battle bt;
    bt.Nhap();
    bt.Xuat();
    return 0;
}

