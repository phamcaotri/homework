#ifndef SHOP_H
#define SHOP_H

#include "Entity.h"

class Shop : public Entity {
    public:
// ------------------------- CONSTRUCTOR -------------------------
        Shop(string name = DEFAULT_NONAME, float buyMultiplier = STD_BUY_MULTIPLIER, float sellMultiplier = STD_SELL_MULTIPLIER) {
            this->name = name;
            this->buyMultiplier = buyMultiplier;
            this->sellMultiplier = sellMultiplier;
        }
// ------------------------- METHOD -------------------------
        void BuyFrom(Entity &seller, int seller_item_index, int amount = 1) override {
            Item item = seller.getItem(seller_item_index);
            float price = round(item.getPrice()*seller.getBuyMultiplier())*amount;
            if (getCoin() >= price) {
                addCoin(-price);
                seller.addCoin(price);
                seller.removeItem(seller_item_index, amount);
                addItem(item, amount);
                cout << getName() << " bought " << amount << " " << item.getName() << " from " << seller.getName() << " for " << price << COIN_SYMBOL << "." << endl;
                cout << getName() << " has " << getCoin() << COIN_SYMBOL << " left." << endl;
                cout << seller.getName() << " has " << seller.getCoin() << COIN_SYMBOL << " now." << endl;
            } else {
                cout << getName() << " doesn't have enough " << COIN_NAME << " to buy " << amount << " " << item.getName() << "." << endl;
            }
        }
        void SellTo(Entity &buyer, int seller_item_index, int amount = 1) override {
            Item item = getItem(seller_item_index);
            float price = round(item.getPrice()*getSellMultiplier())*amount;
            if (buyer.getCoin() >= price) {
                addCoin(price);
                buyer.addCoin(-price);
                buyer.addItem(item, amount);
                removeItem(seller_item_index, amount);
                cout << getName() << " sold " << amount << " " << item.getName() << " to " << buyer.getName() << " for " << price << COIN_SYMBOL << "." << endl;
                cout << getName() << " has " << getCoin() << COIN_SYMBOL << " now." << endl;
                cout << buyer.getName() << " has " << buyer.getCoin() << COIN_SYMBOL << " left." << endl;
            } else {
                cout << buyer.getName() << " doesn't have enough " << COIN_NAME << " to buy " << amount << " " << item.getName() << "." << endl;
            }
        }
};


#endif