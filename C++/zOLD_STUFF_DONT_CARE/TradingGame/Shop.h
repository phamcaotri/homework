#ifndef SHOP_H
#define SHOP_H

#include "Character.h"
#include "Inventory.h"
#include "Item.h"
#include "Constant.h"
#include <math.h>
class Shop {
    private:
        string name;
        Inventory items;
        float buyMultiplier;
        float sellMultiplier;
    public:
        Shop(string name = DEFAULT_NONAME, float buyMultiplier = STD_BUY_MULTIPLIER, float sellMultiplier = STD_SELL_MULTIPLIER) {
            this->name = name;
            this->buyMultiplier = buyMultiplier;
            this->sellMultiplier = sellMultiplier;
        }
        void setName(string name) {
            this->name = name;
        }
        string getName() {
            return name;
        }
        void setInventory(Inventory items) {
            this->items = items;
        }
        void addItem(Item item, int amount = 1) {
            items.addItem(item, amount);
        }
        void removeItem(int index, int amount = 1) {
            items.removeItem(index, amount);
        }
        void showItems(string type = "default") {
            if (type == "buy") {
                items.showItemsWithPrice(buyMultiplier);
            }
            else if (type == "sell") {
                items.showItemsWithPrice(sellMultiplier);
            }
            else {
                items.showItems();
            }
        }
        Item getItem(int index) {
            return items.getItem(index);
        }
        int getAmount(int index) {
            return items.getAmount(index);
        }
        int getSize() {
            return items.getSize();
        }
        bool isValidIndex(int index) {
            return items.isValidIndex(index);
        }
        bool isValidAmount(int index, int amount) {
            return items.isValidAmount(index, amount);
        }
        void Buy(Character &player, int shop_item_index, int amount = 1) {
            Item item = getItem(shop_item_index);
            float price = round(item.getPrice()*buyMultiplier*amount); 
            if (player.getCoin() >= price) {
                player.addCoin(-price);
                removeItem(shop_item_index, amount);
                player.addItem(item, amount);
                cout << "You bought " << amount << " " << item.getName() << " for " << price << COIN_SYMBOL <<"." << endl;
                cout << "You have " << player.getCoin() << COIN_SYMBOL << " left." << endl;
            } else {
                cout << "You don't have enough " << COIN_NAME <<" to buy " << amount << " " << item.getName() << "." << endl;
            }
        }
        void Sell(Character &player, int player_item_index, int amount = 1) {
            Item item = player.getItem(player_item_index);
            float price = round(item.getPrice()*sellMultiplier*amount);
            player.removeItem(player_item_index, amount);
            addItem(item, amount);
            player.addCoin(price);
            cout << "You sold " << amount << " " << item.getName() << " for " << price << COIN_SYMBOL << "." << endl;
            cout << "You have " << player.getCoin() << COIN_SYMBOL << " now." << endl;
        }
};


#endif