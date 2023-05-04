#ifndef SHOP_H
#define SHOP_H

#include "Entity.h"

class Shop : public Entity {
    public:
        Shop(string name = DEFAULT_NONAME, float buyMultiplier = STD_BUY_MULTIPLIER, float sellMultiplier = STD_SELL_MULTIPLIER) {
            this->name = name;
            this->buyMultiplier = buyMultiplier;
            this->sellMultiplier = sellMultiplier;
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