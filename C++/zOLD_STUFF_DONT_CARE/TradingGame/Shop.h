#ifndef SHOP_H
#define SHOP_H

#include "Entity.h"

class Shop : public Entity {
    public:
// ------------------------- CONSTRUCTOR -------------------------
        Shop(string name = DEFAULT_NONAME, int coin = STARTING_COIN, float buyMultiplier = STD_BUY_MULTIPLIER, float sellMultiplier = STD_SELL_MULTIPLIER) {
            this->name = name;
            priceSystem.getBuyMultiplier() = buyMultiplier;
            priceSystem.getSellMultiplier() = sellMultiplier;
            listAcceptItems = vector<Item>();
        }
        Shop(string name, Inventory inventory, int coin = STARTING_COIN, float buyMultiplier = STD_BUY_MULTIPLIER, float sellMultiplier = STD_SELL_MULTIPLIER) {
            this->name = name;
            this->inventory = inventory;
            this->coin = coin;
            priceSystem.getBuyMultiplier() = buyMultiplier;
            priceSystem.getSellMultiplier() = sellMultiplier;
            listAcceptItems = inventory.getListItems();
        }
// ------------------------- METHOD -------------------------
};


#endif