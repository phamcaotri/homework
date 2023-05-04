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
            cout << "Enter item index: ";
            int index;
            cin >> index;
            if (index > 0 && index <= shop.getSize()) {
                shop.Buy(player, index-1);
            } else {
                cout << "Invalid index." << endl;
            }
        }
        void SellItem() {
            player.showItems("sell");
            int index;
            cout << "You have " << player.getCoin() << COIN_SYMBOL << "." << endl;
            cout << "Enter item index: ";
            cin >> index;
            if (index > 0 && index <= player.getSize()) {
                shop.Sell(player, index-1);
            } else {
                cout << "Invalid index." << endl;
            }
        }
        void TalkToTrader() {
            int index;
            cout << "Enter trader index: ";
            cin >> index;
            if (index > 0 && index <= traders.size()) {
                traders[index-1].showInfo();
            } else {
                cout << "Invalid index." << endl;
            }
        }
        void BuyFromTrader() {
            int index;
            cout << "Enter trader index: ";
            cin >> index;
            if (index > 0 && index <= traders.size()) {
                traders[index-1].showItems("buy");
                cout << "You have " << player.getCoin() << COIN_SYMBOL << "." << endl;
                int itemIndex;
                cout << "Enter item index: ";
                cin >> itemIndex;
                if (itemIndex > 0 && itemIndex <= traders[index-1].getSize()) {
                    player.BuyFrom(traders[index-1], itemIndex-1);
                } else {
                    cout << "Invalid index." << endl;
                }
            } else {
                cout << "Invalid index." << endl;
            }
        }
        void SellToTrader() {
            int index;
            cout << "Enter trader index: ";
            cin >> index;
            if (index > 0 && index <= traders.size()) {
                player.showItems("sell");
                int itemIndex;
                cout << "You have " << player.getCoin() << COIN_SYMBOL << "." << endl;
                cout << "Enter item index: ";
                cin >> itemIndex;
                if (itemIndex > 0 && itemIndex <= player.getSize()) {
                    player.SellTo(traders[index-1], itemIndex-1);
                } else {
                    cout << "Invalid index." << endl;
                }
            } else {
                cout << "Invalid index." << endl;
            }
        }
        void run() {
            do {
                showInterface();
                cout << "Enter choice: ";
                int choice = input.getInt();
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