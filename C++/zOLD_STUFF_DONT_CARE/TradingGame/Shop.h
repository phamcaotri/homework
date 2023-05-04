#ifndef SHOP_H
#define SHOP_H

#include "Entity.h"

class Shop : public Entity {
    public:
        Shop(string name = DEFAULT_NONAME, float buyMultiplier = STD_BUY_MULTIPLIER, float sellMultiplier = STD_SELL_MULTIPLIER) {
            this->name = name;
            this->buyMultiplier = buyMultiplier;
            this->sellMultiplier = sellMultiplier;
        }
};


#endif