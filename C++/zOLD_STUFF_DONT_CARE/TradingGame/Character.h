#ifndef CHARACTER_H
#define CHARACTER_H

#include "Level.h"
#include "Item.h"
#include "Inventory.h"

class Character {
    protected:
        string name;
        Level lv;
        int coin;
        Inventory Inventory;

        float buyMultiplier;
        float sellMultiplier;
    public:
        Character(string name = DEFAULT_NONAME, int coin = STARTING_COIN, float buyMultiplier = STD_BUY_MULTIPLIER, float sellMultiplier = STD_SELL_MULTIPLIER) {
            this->name = name;
            this->coin = coin;
            this->buyMultiplier = buyMultiplier;
            this->sellMultiplier = sellMultiplier;
        }
        void showInfo() {
            cout << "Name: " << name << endl;
            cout << "Lv: " << lv.getLv() << endl;
            cout << "Exp: " << lv.getExp() << "/" << lv.getMaxExp() << endl;
            cout << UPPER_COIN_NAME << ": " << coin << COIN_SYMBOL << endl;
            cout << "Items: " << endl;
            Inventory.showItems();
        }
        void setName(string name) {
            this->name = name;
        }
        void setGold(int gold) {
            this->coin = gold;
        }
        string getName() {
            return name;
        }
        int getGold() {
            return coin;
        }
        void addGold(int gold) {
            this->coin += gold;
        }
        void addExp(int exp) {
            lv.addExp(exp);
        }
        Item getItem(int index) {
            return Inventory.getItem(index);
        }
        int getAmount(int index) {
            return Inventory.getAmount(index);
        }
        int getSize() {
            return Inventory.getSize();
        }
        void addItem(Item item, int amount) {
            Inventory.addItem(item, amount);
        }
        void removeItem(int index, int amount) {
            Inventory.removeItem(index, amount);
        }
        float getBuyMultiplier() {
            return buyMultiplier;
        }
        float getSellMultiplier() {
            return sellMultiplier;
        }
        void showItems(string type = "default") {
            if (type == "buy") {
                Inventory.showItemsWithPrice(buyMultiplier);
            } else if (type == "sell") {
                Inventory.showItemsWithPrice(sellMultiplier);
            } else {
                Inventory.showItemsWithPrice();
            }
        }

};

void Buy(Character &seller, Character &buyer, int seller_item_index, int amount = 1) {
    Item item = seller.getItem(seller_item_index);
    float price = round(item.getPrice()*seller.getSellMultiplier()*amount);
    if (buyer.getGold() >= price) {
        buyer.addGold(-price);
        seller.addGold(price);
        seller.removeItem(seller_item_index, amount);
        buyer.addItem(item, amount);
        cout << buyer.getName() << " bought " << item.getName() << " from " << seller.getName() << " for " << price << COIN_SYMBOL << "." << endl;
        cout << buyer.getName() << " has " << buyer.getGold() << COIN_SYMBOL << " left." << endl;
        cout << seller.getName() << " has " << seller.getGold() << COIN_SYMBOL << " now." << endl;
    } else {
        cout << buyer.getName() << " doesn't have enough " << COIN_NAME << " to buy " << item.getName() << "." << endl;
    }
}
void Sell(Character &seller, Character &buyer, int buyer_item_index, int amount = 1) {
    Item item = buyer.getItem(buyer_item_index);
    float price = round(item.getPrice()*buyer.getBuyMultiplier()*amount);
    buyer.removeItem(buyer_item_index, amount);
    seller.addItem(item, amount);
    buyer.addGold(price);
    seller.addGold(-price);
    cout << seller.getName() << " sold " << item.getName() << " to " << buyer.getName() << " for " << price << COIN_SYMBOL << "." << endl;
    cout << buyer.getName() << " has " << buyer.getGold() << COIN_SYMBOL << " now." << endl;
    cout << seller.getName() << " has " << seller.getGold() << COIN_SYMBOL << " left." << endl;
}
#endif