#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include "Character.h"
#include "Shop.h"

class GameInterface {
    private:
        Character player;
        Shop shop;
    public:
        GameInterface() {
            player = Character();
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
            shop.showItems();
        }
        void showInterface() {
            cout << "1. Show Player" << endl;
            cout << "2. Show Shop" << endl;
            cout << "3. Buy Item" << endl;
            cout << "4. Sell Item" << endl;
            cout << "5. Exit" << endl;
        }
        void BuyItem() {
            shop.showItems();
            int index;
            cout << "Enter item index: ";
            cin >> index;
            if (index > 0 && index <= shop.getSize()) {
                shop.Buy(index-1, player);
            } else {
                cout << "Invalid index." << endl;
            }
        }
        void SellItem() {
            int index;
            cout << "Enter item index: ";
            cin >> index;
            if (index > 0 && index <= player.getSize()) {
                shop.Sell(player, index-1);
            } else {
                cout << "Invalid index." << endl;
            }
        }
        void run() {
            int choice;
            do {
                showInterface();
                cout << "Enter choice: ";
                cin >> choice;
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
                        cout << "Exiting..." << endl;
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                }
                cout << "-------------------------" << endl << endl;
            } while (choice != 5);
        }

};

#endif