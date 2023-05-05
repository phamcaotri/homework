#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include "Character.h"
#include "Shop.h"
#include "UserInput.h"
#include "Map.h"
#include "Windows.h"

void TradeAction(Entity& player, Entity& trader, string action) {
    UserInput input;
    if (action == "buy") {
        trader.showItems("buy");
    } else if (action == "sell") {
        player.showItems("sell");
    }
    cout << "You have " << player.getCoin() << COIN_SYMBOL << "." << endl;
    cout << "Enter item index and amount (default = 1): ";
    int index, amount = 1;
    input.getPairInt(index, amount);
    if (action == "buy") {
        if (trader.isValidIndex(index-1) && trader.isValidAmount(index-1, amount)) {
            player.BuyFrom(trader, index-1, amount);
        } else {
            cout << "Invalid input" << endl;
        }
    } else if (action == "sell") {
        if (player.isValidIndex(index-1) && player.isValidAmount(index-1, amount)) {
            player.SellTo(trader, index-1, amount);
        } else {
            cout << "Invalid input" << endl;
        }
    }
}

class GameInterface {
    private:
        Character player;
        vector<Character> traders;
        Shop shop;
        UserInput input;
        Map map;
        vector<Option> options;
        Windows windows;
    public:
        GameInterface() {
            player = Character();
            traders = vector<Character>();
            shop = Shop();
            map = Map();
            options = vector<Option>();
            windows = Windows();
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
        void setMap(Map map) {
            this->map = map;
        }
        void addTrader(Character trader) {
            traders.push_back(trader);
        }
        void addOption(string name, void (GameInterface::*function)()) {
            options.push_back(Option(name, function));
            windows.addMenuOption(name);
        }
        void initOption() {
            addOption("Show Player", &GameInterface::showPlayer);
            addOption("Show Shop", &GameInterface::showShop);
            addOption("Buy Item", &GameInterface::BuyItem);
            addOption("Sell Item", &GameInterface::SellItem);
            addOption("Talk to Trader", &GameInterface::TalkToTrader);
            addOption("Buy from Trader", &GameInterface::BuyFromTrader);
            addOption("Sell to Trader", &GameInterface::SellToTrader);
            addOption("Exit", &GameInterface::Exit);
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
            shop.showInfo("not show items");
            shop.showItems("buy");
        }
        void Exit() {
            cout << "Exiting..." << endl;
            exit(0);
        }
        void BuyItem() {
            TradeAction(player, shop, "buy");
        }
        void SellItem() {
            TradeAction(player, shop, "sell");
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
                TradeAction(player, traders[index-1], "buy");
            } else {
                cout << "Invalid input." << endl;
            }
        }
        void SellToTrader() {
            cout << "Enter trader index: ";
            int index;
            input.getInt(index);
            if (index > 0 && index <= traders.size()) {
                TradeAction(player, traders[index-1], "sell");
            } else {
                cout << "Invalid input." << endl;
            }
        }
        void run() {
            do {
                windows.showMenu();
                cout << "Enter choice: ";
                int choice;
                input.getInt(choice);
                //clearScreen();
                if (choice > 0 && choice <= options.size()) {
                    options[choice-1].getFunction();
                } else {
                    cout << "Invalid input." << endl;
                }
            } while (true);
        }
};

#endif