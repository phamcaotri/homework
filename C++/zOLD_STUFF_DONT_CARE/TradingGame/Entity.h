#ifndef ENTITY_H
#define ENTITY_H

#include "Item.h"
#include "Inventory.h"

class Entity {
    protected:
        string name;
        int coin;
        Inventory inventory;
// ------------------------- BUY/SELL MULTIPLIER -------------------------
        float buyMultiplier;
        float sellMultiplier;
    public:
// ------------------------- CONSTRUCTOR -------------------------
        Entity(string name = DEFAULT_NONAME, int coin = STARTING_COIN, float buyMultiplier = STD_BUY_MULTIPLIER, float sellMultiplier = STD_SELL_MULTIPLIER) {
            this->name = name;
            this->coin = coin;
            this->buyMultiplier = buyMultiplier;
            this->sellMultiplier = sellMultiplier;
        }
// ------------------------- GETTERS, SETTER, ADD, REMOVE -------------------------
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
        virtual void addItem(Item item, int amount) {
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
// ------------------------- METHODS -------------------------
        bool isValidIndex(int index) {
            return inventory.isValidIndex(index);
        }
        bool isValidAmount(int index, int amount) {
            return inventory.isValidAmount(index, amount);
        }
        void showInfo(string condition = "show items") {
            cout << "Name: " << name << endl;
            cout << UPPER_COIN_NAME << ": " << coin << COIN_SYMBOL << endl;
            cout << "Items: " << endl;
            if (condition == "show items") {
                inventory.showItems();
            }
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
        virtual void BuyFrom(Entity &seller, int seller_item_index, int amount = 1) {};
        virtual void SellTo(Entity &buyer, int seller_item_index, int amount = 1) {};
};

#endif