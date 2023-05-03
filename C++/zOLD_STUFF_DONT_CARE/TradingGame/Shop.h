#ifndef SHOP_H
#define SHOP_H

#include "Character.h"
#include "Inventory.h"
#include "Item.h"
#include "Constant.h"

// todo: thêm tính năng thay đổi giá mua/bán

class Shop {
    private:
        string name;
        Inventory items;
        float priceMultiplier;
    public:
        Shop() {
            name = "NoName";
        }
        Shop(string name) {
            this->name = name;
        }
        void setName(string name, int priceMultiplier = 1.0) {
            this->name = name;
            this->priceMultiplier = priceMultiplier;
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
        void showItems() {
            items.showItemsWithPrice(priceMultiplier);
        }
        Item getItem(int index) {
            return items.getItem(index);
        }
        int getSize() {
            return items.getSize();
        }
        void Buy(int shop_item_index, Character &player) {
            Item item = getItem(shop_item_index);
            if (player.getGold() >= item.getPrice()) {
                player.addGold(-item.getPrice());
                removeItem(shop_item_index);
                player.addItem(item, 1);
                cout << "You bought " << item.getName() << " for " << item.getPrice() << " gold." << endl;
            } else {
                cout << "You don't have enough gold to buy " << item.getName() << "." << endl;
            }
        }
        void Sell(Character &player, int player_item_index, int amount = 1) {
            Item item = player.getItem(player_item_index);
            player.removeItem(player_item_index, amount);
            addItem(item, amount);
            player.addGold(item.getPrice());
            cout << "You sold " << item.getName() << " for " << item.getPrice() << " gold." << endl;
        }
};

#endif