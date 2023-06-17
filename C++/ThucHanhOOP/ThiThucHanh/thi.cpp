#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <climits>
using namespace std;

class ToaDo {
    private:
        int x, y;
    public:
        ToaDo(int x = 0, int y = 0) {
            this->x = x;
            this->y = y;
        }
        void input() {
            cin >> x >> y;
        }
        void output() {
            cout << x << " " << y << endl;
        }
        float get_distance(ToaDo l) {
            return sqrt(pow(x-l.x, 2) + pow(y-l.y, 2));
        }
};

class Chat {
    protected:
        char name;
        int loai_chat;

    public:
        virtual void input(char name) = 0;
        void add(char name) {
            this->name = name;
        }
        char get_name() {
            return name;
        }
        virtual float get_kich_thuoc() = 0;
};

class Chat1 : public Chat {
    private:
        float kich_thuoc;
    public:
        void input(char x) override {
            name = x;
            cin >> kich_thuoc;
        }
        float get_kich_thuoc() override {
            return kich_thuoc;
        }
};

class Chat2 : public Chat {
    private:
        float kich_thuoc;
    public:
        void input(char x) override {
            name = x;
            cin >> kich_thuoc;
        }
        float get_kich_thuoc() override {
            return kich_thuoc;
        }
};

class Chat3 : public Chat {
    public:
        void input(char x) override {
            name = x;
        }
        float get_kich_thuoc() override {
            return 0;
        }
};



class HopChat {
    private:
        tuple<Chat*, Chat*, Chat*> chat;
        string name;
        float kich_thuoc;
        int loai;
        ToaDo toa_do;


    public:
        HopChat() {}
        HopChat(Chat* x, Chat* y = nullptr, Chat* z = nullptr) {
            get<0>(chat) = x;
            get<1>(chat) = y;
            get<2>(chat) = z;
            name = x->get_name() + y->get_name() + z->get_name();
            kich_thuoc = x->get_kich_thuoc() + y->get_kich_thuoc() + z->get_kich_thuoc();
            toa_do = ToaDo(INT_MAX, INT_MAX);
        }
        void input() {
            cin >> name;
            if (name.size() == 3) {
                loai = 3;
                Chat* x;
                for (int i = 0; i < 3; ++i) {
                    if (get_loai_chat(name[i]) == 1) {
                        x = new Chat1();
                    } else if (get_loai_chat(name[i]) == 2) {
                        x = new Chat2();
                    } else {
                        x = new Chat3();
                    }
                    x->add(name[i]);
                    if (i == 0) {
                        get<0>(chat) = x;
                    } else if (i == 1) {
                        get<1>(chat) = x;
                    } else {
                        get<2>(chat) = x;
                    }
                }
                cin >> kich_thuoc;
                toa_do.input();
            } else if (name.size() == 2) {
                loai = 2;
                Chat* x;
                for (int i = 0; i < 2; ++i) {
                    if (get_loai_chat(name[i]) == 1) {
                        x = new Chat1();
                    } else if (get_loai_chat(name[i]) == 2) {
                        x = new Chat2();
                    } else {
                        x = new Chat3();
                    }
                    x->add(name[i]);
                    if (i == 0) {
                        get<0>(chat) = x;
                    } else {
                        get<1>(chat) = x;
                    }
                }
                cin >> kich_thuoc;
                toa_do.input();
                get<2>(chat) = nullptr;
            } else {
                loai = 1;
                Chat* x;
                if (get_loai_chat(name[0]) == 1) {
                    x = new Chat1();
                } else if (get_loai_chat(name[0]) == 2) {
                    x = new Chat2();
                } else {
                    x = new Chat3();
                }
                x->input(name[0]);
                get<0>(chat) = x;
                get<1>(chat) = nullptr;
                get<2>(chat) = nullptr;
                toa_do.input();
            }
        }
        int get_loai_chat(char name) {
            if (isalpha(name)) {
                return 1;
            } else if (isdigit(name) and name != '0') {
                return 2;
            } else {
                return 3;
            }
        }
        float get_distance(ToaDo t) {
            return toa_do.get_distance(t);
        }
        ToaDo get_toa_do() {
            return toa_do;
        }
        int get_loai() {
            return loai;
        }
        Chat* get_chat(int i) {
            if (i == 0) {
                return get<0>(chat);
            } else if (i == 1) {
                return get<1>(chat);
            } else {
                return get<2>(chat);
            }
        }
        void output() {
            cout << name << " ";
            toa_do.output();
        }
};


class Enzyme {
    protected:
        string name;
        int loai_enzyme;
        float thoi_gian_xuat_hien;
        ToaDo toa_do;
        Chat* chat;
    public:
        virtual void input(string) = 0;
        virtual void tuong_tac(vector<HopChat*>) = 0;
        void set_hopchat(Chat* x) {
            chat = x;
        }
        Chat* get_hopchat() {
            return chat;
        }
        void huy() {
            delete this;
        }
        float get_distance(ToaDo t) {
            return toa_do.get_distance(t);
        }
        int get_loai() {
            return loai_enzyme;
        }
};

class EC3 : public Enzyme {
    private:
        float kich_thuoc;
    public:
        void input(string n) override {
            name = n;
            cin >> kich_thuoc;
            cin >> thoi_gian_xuat_hien;
            toa_do.input();
        }
        void tuong_tac(vector<HopChat*> x) override {
            HopChat *h;
            float min = INFINITY;
            for (auto& hopchat : x) {
                if (hopchat->get_loai() == 2 or hopchat->get_loai() == 3) {
                    if (hopchat->get_distance(toa_do) < min) {
                        min = hopchat->get_distance(toa_do);
                        h = hopchat;
                    }
                }
            }
            if (min == INFINITY) {
                return;
            }
            if (h->get_loai() == 2) {
                x.push_back(new HopChat(h->get_chat(0)));
                x.push_back(new HopChat(h->get_chat(1)));
            } else {
                HopChat* hc = new HopChat(h->get_chat(1), h->get_chat(2));
                x.push_back(hc);
                x.push_back(new HopChat(h->get_chat(2)));
            }
        }
};

class EC6 : public Enzyme {
    public:
        void input(string n) override {
            name = n;
            // thuoc tinh them
            cin >> thoi_gian_xuat_hien;
            toa_do.input();
        }
        void tuong_tac(vector<HopChat*> x) override {
            HopChat *h;
            float min = INFINITY;
            for (auto& hopchat : x) {
                if (hopchat->get_loai() == 1 or hopchat->get_loai() == 3) {
                    if (hopchat->get_distance(toa_do) < min) {
                        min = hopchat->get_distance(toa_do);
                        h = hopchat;
                    }
                }
            }
            if (min == INFINITY) {
                return;
            }
            HopChat* newhc = new HopChat(chat, h->get_chat(1));
        }
};

class EC7 : public Enzyme {
    private:
        float toc_do_toi_da;
    public:
        void input(string n) override {
            name = n;
            cin >> toc_do_toi_da;
            cin >> thoi_gian_xuat_hien;
            toa_do.input();
        }
        void tuong_tac(vector<HopChat*> x) override {
            HopChat* h;
            float min = INFINITY;
            for (auto& hopchat : x) {
                if (hopchat->get_loai() == 1 or hopchat->get_loai() == 2) {
                    if (hopchat->get_distance(toa_do) < min) {
                        min = hopchat->get_distance(toa_do);
                        h = hopchat;
                    }
                }
            }
            if (min == INFINITY) {
                return;
            }
            chat = h->get_chat(0);
        }
};

class KhongGian {
    private:
        vector<Enzyme*> enzyme;
        vector<HopChat*> hopchat;

    public:
        void input() {
            int n; cin >> n;
            for (int i=0; i<n; i++) {
                HopChat* h = new HopChat();
                h->input();
                hopchat.push_back(h);
            }


            int m; cin >> m;
            for (int i=0; i<m; i++) {
                string name; cin >> name;
                Enzyme* e;
                if (name == "EC3") {
                    e = new EC3();
                } else if (name == "EC6") {
                    e = new EC6();
                } else {
                    e = new EC7();
                }
                e->input(name);
                enzyme.push_back(e);
            }
        }

        void process() {
            for (auto e : enzyme) {

                if (e->get_loai() == 1) {
                    e->tuong_tac(hopchat);
                } else if (e->get_loai() == 2) {
                    e->tuong_tac(hopchat);
                } else {
                    e->tuong_tac(hopchat);
                }
            }
        }

        void output() {
            //process();
            for (auto c : hopchat) {
                c->output();
            }
        }
};






int main() {
    KhongGian k;
    k.input();
    k.output();
    return 0;   
}