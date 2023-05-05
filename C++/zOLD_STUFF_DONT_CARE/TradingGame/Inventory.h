#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <iostream>
using std::vector, std::cin, std::cout, std::endl;
#include "Item.h"
#include <math.h>

class Inventory {
    private:
        vector<std::pair<Item, int>> items;
    public:
// ----------------------- CONSTRUCTOR -----------------------
        Inventory() {}
        Inventory(vector<std::pair<Item, int>> items) {
            this->items = items;
        }
// ------------------------- GETTERS, SETTER, ADD, REMOVE -------------------------
        Item getItem(int index) {
            return items[index].first;
        }
        int getAmount(int index) {
            return items[index].second;
        }
        int getSize() {
            return items.size();
        }
        string getItemName(int index) {
            return items[index].first.getName();
        }
        int getItemPrice(int index) {
            return items[index].first.getPrice();
        }
        void increaseAmount(int index, int amount) {
            if (items[index].second >= INFINITY_AMOUNT) {
                return;
            } else {
                items[index].second += amount;
            }
        }
        void addItem(Item item, int amount) {
            // if item is already in inventory, increase amount
            int index = -1;
            if (isContain(item, index)) {
                increaseAmount(index, amount);
                return;
            }
            // if not, add item in price order
            for (int i = 0; i < items.size(); i++) {
                if (item.getPrice() < getItemPrice(i)) {
                    items.insert(items.begin()+i, std::make_pair(item, amount));
                    return;
                }
            }
            items.push_back(std::make_pair(item, amount));
        }
        void removeItem(int index, int amount) {
            increaseAmount(index, -amount);
            if (items[index].second <= 0) {
                items.erase(items.begin()+index);
            }
        }
// ------------------------- OTHER METHODS -------------------------
        bool isContain(Item item, int& index) {
            for (int i = 0; i < items.size(); i++) {
                if (getItemName(i) == item.getName()) {
                    index = i;
                    return true;
                }
            }
            index = -1;
            return false;
        }
        bool isValidIndex(int index) {
            return index >= 0 && index < items.size();
        }
        bool isValidAmount(int index, int amount) {
            return amount >= 0 && (items[index].second >= amount || items[index].second >= INFINITY_AMOUNT);
        }
        void showItems() {
            if (items.size() == 0) {
                cout << "Empty" << endl;
                return;
            }
            for (int i = 0; i < items.size(); i++) {
                if (items[i].second < INFINITY_AMOUNT) {
                    cout << i+1 << ". " << items[i].first.getName() << " x" << items[i].second << endl;
                } else {
                    cout << i+1 << ". " << items[i].first.getName() << endl;
                }
            }
        }
        void showItemsWithPrice(float multiplier = 1.0) {
            if (items.size() == 0) {
                cout << "Empty" << endl;
                return;
            }
            for (int i = 0; i < items.size(); i++) {
                if (items[i].second < INFINITY_AMOUNT) {
                    cout << i+1 << ". " << items[i].first.getName() << " x" << items[i].second << " - " << round(items[i].first.getPrice()*multiplier) << COIN_SYMBOL << endl;
                } else {
                    cout << i+1 << ". " << items[i].first.getName() << " - " << round(items[i].first.getPrice()*multiplier) << COIN_SYMBOL << endl;
                }
            }
        }
}; 

#endif