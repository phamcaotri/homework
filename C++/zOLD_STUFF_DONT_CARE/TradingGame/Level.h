#ifndef LEVEL_H
#define LEVEL_H

class Level {
    private:
        int lv;
        int exp;
        int maxExp;

    public:
        Level() {
            lv = 1;
            exp = 0;
            maxExp = 100;
        }
        void setLv(int lv) {
            this->lv = lv;
            maxExp = calMaxExp();
        }
        void setExp(int exp) {
            this->exp = exp;
            setMaxExp();
        }
        void addExp(int exp) {
            this->exp += exp;
            setMaxExp();
        }
        void setMaxExp() {
            while (exp >= maxExp) {
                exp -= maxExp;
                lv++;
                maxExp = calMaxExp();
            }
        }
        int getLv() {
            return lv;
        }
        int getExp() {
            return exp;
        }
        int getMaxExp() {
            return maxExp;
        }
        int calMaxExp() {
            return lv*(500+lv*250);
        }
};

#endif