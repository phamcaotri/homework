#ifndef LEVEL_H
#define LEVEL_H

#include "Constant.h"

class Level {
    private:
        int lv;
        int exp;
        int maxExp;

    public:
// ------------------------- CONSTRUCTOR -------------------------
        Level() {
            lv = STARTING_LV;
            exp = STARTING_EXP;
            maxExp = STARTING_MAXEXP;
        }
// ------------------------- GETTER -------------------------
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
// ------------------------- METHODS -------------------------
        int calMaxExp() {
            return lv*(500+lv*250);
        }
};

#endif