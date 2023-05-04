#ifndef ENTITY_H
#define ENTITY_H

#include "Item.h"
#include "Inventory.h"

class Entity {
    protected:
        string name;
        int coin;
        Inventory inventory;

        float buyMultiplier;
        float sellMultiplier;
    public:
        Entity(string name = DEFAULT_NONAME, int coin = STARTING_COIN, float buyMultiplier = STD_BUY_MULTIPLIER, float sellMultiplier = STD_SELL_MULTIPLIER) {
            this->name = name;
            this->coin = coin;
            this->buyMultiplier = buyMultiplier;
            this->sellMultiplier = sellMultiplier;
        }
        void showInfo() {
            cout << "Name: " << name << endl;
            cout << UPPER_COIN_NAME << ": " << coin << COIN_SYMBOL << endl;
            cout << "Items: " << endl;
            inventory.showItems();
        }
        void setName(string name) {
            this->name = name;
        }
        void setCoin(int coin) {
            this->coin = coin;
        }
        string getName() {
            return name;
        }
        void setInventory(Inventory inventory) {
            this->inventory = inventory;
        }
        int getCoin() {
            return coin;
        }
        void addCoin(int coin) {
            this->coin += coin;
        }
        Item getItem(int index) {
            return inventory.getItem(index);
        }
        int getAmount(int index) {
            return inventory.getAmount(index);
        }
        int getSize() {
            return inventory.getSize();
        }
        void addItem(Item item, int amount) {
            inventory.addItem(item, amount);
        }
        void removeItem(int index, int amount) {
            inventory.removeItem(index, amount);
        }
        float getBuyMultiplier() {
            return buyMultiplier;
        }
        float getSellMultiplier() {
            return sellMultiplier;
        }
        bool isValidIndex(int index) {
            return inventory.isValidIndex(index);
        }
        bool isValidAmount(int index, int amount) {
            return inventory.isValidAmount(index, amount);
        }
        void showItems(string type = "default") {
            if (type == "buy") {
                inventory.showItemsWithPrice(buyMultiplier);
            } else if (type == "sell") {
                inventory.showItemsWithPrice(sellMultiplier);
            } else {
                inventory.showItemsWithPrice();
            }
        }
        void BuyFrom(Entity &seller, int seller_item_index, int amount = 1) {
            Item item = seller.getItem(seller_item_index);
            float price = round(item.getPrice()*seller.getBuyMultiplier()*amount);
            if (getCoin() >= price) {
                addCoin(-price);
                seller.addCoin(price);
                seller.removeItem(seller_item_index, amount);
                addItem(item, amount);
                cout << getName() << " bought " << item.getName() << " from " << seller.getName() << " for " << price << COIN_SYMBOL << "." << endl;
                cout << getName() << " has " << getCoin() << COIN_SYMBOL << " left." << endl;
                cout << seller.getName() << " has " << seller.getCoin() << COIN_SYMBOL << " now." << endl;
            } else {
                cout << getName() << " doesn't have enough " << COIN_NAME << " to buy " << item.getName() << "." << endl;
            }
        }
        void SellTo(Entity &buyer, int seller_item_index, int amount = 1) {
            Item item = getItem(seller_item_index);
            float price = round(item.getPrice()*getSellMultiplier()*amount);
            if (buyer.getCoin() >= price) {
                addCoin(price);
                buyer.addCoin(-price);
                buyer.addItem(item, amount);
                removeItem(seller_item_index, amount);
                cout << getName() << " sold " << item.getName() << " to " << buyer.getName() << " for " << price << COIN_SYMBOL << "." << endl;
                cout << getName() << " has " << getCoin() << COIN_SYMBOL << " now." << endl;
                cout << buyer.getName() << " has " << buyer.getCoin() << COIN_SYMBOL << " left." << endl;
            } else {
                cout << buyer.getName() << " doesn't have enough " << COIN_NAME << " to buy " << item.getName() << "." << endl;
            }
        }
};

#endif