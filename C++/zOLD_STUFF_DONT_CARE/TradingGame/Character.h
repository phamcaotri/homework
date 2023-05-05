#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"
#include "Level.h"
#include "UserInput.h"

class Character : public Entity {
    private:
        Level lv;
    public:
// ------------------------- CONSTRUCTOR -------------------------
        Character(string name = DEFAULT_NONAME, int coin = STARTING_COIN, float buyMultiplier = STD_BUY_MULTIPLIER, float sellMultiplier = STD_SELL_MULTIPLIER) {
            this->name = name;
            this->coin = coin;
            this->buyMultiplier = buyMultiplier;
            this->sellMultiplier = sellMultiplier;
        }
// ------------------------- GETTERS, SETTER, ADD, REMOVE -------------------------
        int getLv() {
            return lv.getLv();
        }
        int getExp() {
            return lv.getExp();
        }
        int getMaxExp() {
            return lv.getMaxExp();
        }
        void setLv(int lv) {
            this->lv.setLv(lv);
        }
        void setExp(int exp) {
            this->lv.setExp(exp);
        }
        void addExp(int exp) {
            lv.addExp(exp);
        }
// ------------------------- METHODS -------------------------
        void showInfo() {
            cout << "Name: " << name << endl;
            cout << "Lv: " << lv.getLv() << endl;
            cout << "Exp: " << lv.getExp() << "/" << lv.getMaxExp() << endl;
            cout << UPPER_COIN_NAME << ": " << coin << COIN_SYMBOL << endl;
            cout << "Items: " << endl;
            inventory.showItems();
        }
        void BuyFrom(Entity &seller, int seller_item_index, int amount = 1) override {
            Item item = seller.getItem(seller_item_index);
            float price = round(item.getPrice()*seller.getBuyMultiplier())*amount;
            float exp = round(price*EXP_MULTIPLIER);
            if (getCoin() >= price) {
                addCoin(-price);
                seller.addCoin(price);
                seller.removeItem(seller_item_index, amount);
                addItem(item, amount);
                addExp(exp);
                cout << getName() << " bought " << amount << " " << item.getName() << " from " << seller.getName() << " for " << price << COIN_SYMBOL << "." << endl;
                cout << getName() << " gained " << exp << " exp." << endl;
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