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
    public:
        Character(string name = DEFAULT_NONAME, int coin = STARTING_COIN) {
            this->name = name;
            this->coin = coin;
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
        void showItems() {
            Inventory.showItems();
        }
        void showItemsWithPrice(float priceMultiplier = 1.0) {
            Inventory.showItemsWithPrice(priceMultiplier);
        }

};

#endif