#ifndef SHOP_H
#define SHOP_H

#include "Entity.h"

class Shop : public Entity {
    public:
// ------------------------- CONSTRUCTOR -------------------------
        Shop(string name = DEFAULT_NONAME, float buyMultiplier = STD_BUY_MULTIPLIER, float sellMultiplier = STD_SELL_MULTIPLIER) {
            this->name = name;
            priceSystem.getBuyMultiplier() = buyMultiplier;
            priceSystem.getSellMultiplier() = sellMultiplier;
            listAcceptItems = vector<Item>();
        }
        Shop(string name, Inventory inventory, float buyMultiplier = STD_BUY_MULTIPLIER, float sellMultiplier = STD_SELL_MULTIPLIER) {
            this->name = name;
            this->inventory = inventory;
            priceSystem.getBuyMultiplier() = buyMultiplier;
            priceSystem.getSellMultiplier() = sellMultiplier;
            listAcceptItems = inventory.getListItems();
        }
// ------------------------- METHOD -------------------------
};


#endif