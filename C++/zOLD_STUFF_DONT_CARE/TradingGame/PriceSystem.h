#ifndef PRICESYSTEM_H
#define PRICESYSTEM_H

#include <iostream>
using std::cout, std::endl;

#include "Constant.h"

class PriceSystem {
    private:
        float buyMultiplier;
        float sellMultiplier;
    public:
// ------------------------- CONSTRUCTOR -------------------------
        PriceSystem(float buyMultiplier = STD_BUY_MULTIPLIER, float sellMultiplier = STD_SELL_MULTIPLIER) {
            this->buyMultiplier = buyMultiplier;
            this->sellMultiplier = sellMultiplier;
        }
// ------------------------- GETTER -------------------------
        float& getBuyMultiplier() {
            return buyMultiplier;
        }
        float& getSellMultiplier() {
            return sellMultiplier;
        }
// ------------------------- METHOD -------------------------
        void showInfo() {
            cout << "Buy multiplier: " << buyMultiplier << endl;
            cout << "Sell multiplier: " << sellMultiplier << endl;
        }

        void MultiplierCalculate(float supply, float demand, float marketCondition, float securityCondition) {
            buyMultiplier = STD_BUY_MULTIPLIER * (supply / demand) * marketCondition * (2-securityCondition);
            // sellMultiplier = STD_SELL_MULTIPLIER * supply * marketCondition * (securityCondition);
            sellMultiplier = buyMultiplier * 0.7;
        }



};


#endif