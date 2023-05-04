#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include "Character.h"
#include "Shop.h"
#include "UserInput.h"

class GameInterface {
    private:
        Character player;
        vector<Character> traders;
        Shop shop;
        UserInput input;
    public:
        GameInterface() {
            player = Character();
            traders = vector<Character>();
            shop = Shop();
        }
        GameInterface(Character player, Shop shop) {
            this->player = player;
            this->shop = shop;
        }
        void setPlayer(Character player) {
            this->player = player;
        }
        void setShop(Shop shop) {
            this->shop = shop;
        }
        void addTrader(Character trader) {
            traders.push_back(trader);
        }
        Character getPlayer() {
            return player;
        }
        Shop getShop() {
            return shop;
        }
        void showPlayer() {
            player.showInfo();
        }
        void showShop() {
            shop.showItems("buy");
        }
        void showInterface() {
            cout << "\n-------------------------" << endl;
            cout << "1. Show Player" << endl;
            cout << "2. Show Shop" << endl;
            cout << "3. Buy Item" << endl;
            cout << "4. Sell Item" << endl;
            cout << "5. Talk to Trader" << endl;
            cout << "6. Buy from Trader" << endl;
            cout << "7. Sell to Trader" << endl;
            cout << "8. Exit" << endl;
            cout << "-------------------------" << endl;
        }
        void BuyItem() {
            shop.showItems("buy");
            cout << "You have " << player.getCoin() << COIN_SYMBOL << "." << endl;
            cout << "Enter item index and amount (default = 1): ";
            int index, amount = 1;
            input.getPairInt(index, amount);
            if (shop.isValidIndex(index-1) && shop.isValidAmount(index-1, amount)) {
                shop.Buy(player, index-1, amount);
            } else {
                cout << "Invalid input" << endl;
            }
        }
        void SellItem() {
            player.showItems("sell");
            cout << "You have " << player.getCoin() << COIN_SYMBOL << "." << endl;
            cout << "Enter item index and amount (default = 1): ";
            int index, amount = 1;
            input.getPairInt(index, amount);
            if (shop.isValidIndex(index-1) && shop.isValidAmount(index-1, amount)) {
                shop.Sell(player, index-1, amount);
            } else {
                cout << "Invalid input." << endl;
            }
        }
        void TalkToTrader() {
            cout << "Enter trader index: ";
            int index;
            input.getInt(index);
            if (index > 0 && index <= traders.size()) {
                traders[index-1].showInfo();
            } else {
                cout << "Invalid input." << endl;
            }
        }
        void BuyFromTrader() {
            cout << "Enter trader index: ";
            int index;
            input.getInt(index);
            if (index > 0 && index <= traders.size()) {
                traders[index-1].showItems("buy");
                cout << "You have " << player.getCoin() << COIN_SYMBOL << "." << endl;
                cout << "Enter item index and amount (default = 1): ";
                int itemIndex, amount = 1;
                input.getPairInt(itemIndex, amount);
                if (itemIndex > 0 && itemIndex <= traders[index-1].getSize()) {
                    player.BuyFrom(traders[index-1], itemIndex-1);
                } else {
                    cout << "Invalid input." << endl;
                }
            } else {
                cout << "Invalid input." << endl;
            }
        }
        void SellToTrader() {
            cout << "Enter trader index: ";
            int index;
            input.getInt(index);
            if (index > 0 && index <= traders.size()) {
                player.showItems("sell");
                cout << "You have " << player.getCoin() << COIN_SYMBOL << "." << endl;
                cout << "Enter item index and amount (default = 1): ";
                int itemIndex, amount = 1;
                input.getPairInt(itemIndex, amount);
                if (player.isValidIndex(itemIndex-1) && player.isValidAmount(itemIndex-1, amount)) {
                    player.SellTo(traders[index-1], itemIndex-1);
                } else {
                    cout << "Invalid input." << endl;
                }
            } else {
                cout << "Invalid input." << endl;
            }
        }
        void run() {
            do {
                showInterface();
                cout << "Enter choice: ";
                int choice;
                input.getInt(choice);
                clearScreen();
                cout << "\n-------------------------" << endl;
                switch (choice) {
                    case 1:
                        showPlayer();
                        break;
                    case 2:
                        showShop();
                        break;
                    case 3:
                        BuyItem();
                        break;
                    case 4:
                        SellItem();
                        break;
                    case 5:
                        TalkToTrader();
                        break;
                    case 6:
                        BuyFromTrader();
                        break;
                    case 7:
                        SellToTrader();
                        break;
                    case 8:
                        cout << "Exiting..." << endl;
                        return;
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                }
                cout << "-------------------------" << endl << endl;
            } while (true);
        }

};

#endif