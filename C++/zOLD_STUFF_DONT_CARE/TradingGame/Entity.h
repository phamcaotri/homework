#ifndef ENTITY_H
#define ENTITY_H

#include "Item.h"
#include "Inventory.h"
#include "PriceSystem.h"

class Entity {
    protected:
        string name;
        int coin;
        Inventory inventory;
// ------------------------- BUY/SELL MULTIPLIER -------------------------
        PriceSystem priceSystem;
// -----------------------------------------------------------------------
        vector<Item> listAcceptItems;
    public:
// ------------------------- CONSTRUCTOR -------------------------
        Entity(string name = DEFAULT_NONAME, int coin = STARTING_COIN, float buyMultiplier = STD_BUY_MULTIPLIER, float sellMultiplier = STD_SELL_MULTIPLIER) {
            this->name = name;
            this->coin = coin;
            priceSystem.getBuyMultiplier() = buyMultiplier;
            priceSystem.getSellMultiplier() = sellMultiplier;
        }
// ------------------------- GETTERS, SETTER, ADD, REMOVE -------------------------
        string& getName() {
            return name;
        }
        int& getCoin() {
            return coin;
        }
        void addCoin(int coin) {
            this->coin += coin;
        }
        Inventory& getInventory() {
            return inventory;
        }
        float& getBuyMultiplier() {
            return priceSystem.getBuyMultiplier();
        }
        float& getSellMultiplier() {
            return priceSystem.getSellMultiplier();
        }
        void MultiplierCalculate(float supply, float demand, float marketCondition, float securityCondition) {
            priceSystem.MultiplierCalculate(supply, demand, marketCondition, securityCondition);
        }
        void showMultiplier() {
            priceSystem.showInfo();
        }
// ------------------------- METHODS -------------------------
        bool isAcceptItem(Item item) {
            if (listAcceptItems.size() == 0) {
                return true;
            }
            for (int i = 0; i < listAcceptItems.size(); i++) {
                if (item.getName() == listAcceptItems[i].getName()) {
                    return true;
                }
            }
            return false;
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
                inventory.showItemsWithPrice(priceSystem.getBuyMultiplier());
            } else if (type == "sell") {
                inventory.showItemsWithPrice(priceSystem.getSellMultiplier());
            } else {
                inventory.showItemsWithPrice();
            }
        }
        virtual void BuyFrom(Entity &seller, int seller_item_index, int amount = 1) {};
        virtual void SellTo(Entity &buyer, int seller_item_index, int amount = 1) {};
};

#endif