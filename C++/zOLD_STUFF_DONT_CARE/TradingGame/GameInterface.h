#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include "Character.h"
#include "Shop.h"
#include "UserInput.h"
#include "Map.h"

bool TradeAction(Entity& player, Entity& trader, string action) {
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
    if (index == 0) {
        return RETURN;
    }
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
    return NO_RETURN;
}

class GameInterface {
    private:
        Character player;
        vector<Character> traders;
        Shop shop;
        UserInput input;
        Map map;
        vector<std::pair<string, bool (GameInterface::*)()>> options;
    public:
// ------------------------- CONSTRUCTOR -------------------------
        GameInterface() {
            player = Character();
            traders = vector<Character>();
            shop = Shop();
            map = Map();
            options = vector<std::pair<string, bool (GameInterface::*)()>>();
        }
        GameInterface(Character player, Shop shop) {
            this->player = player;
            this->shop = shop;
        }
// ------------------------- GETTERS, SETTER, ADD, REMOVE -------------------------
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
        void setMap(Map map) {
            this->map = map;
        }
        void addTrader(Character trader) {
            traders.push_back(trader);
        }
        void addOption(string name, bool (GameInterface::*function)()) {
            options.push_back(std::make_pair(name, function));
        }
// ------------------------- METHOD -------------------------
        void clearScreen() {
            cout << "\033[2J\033[1;1H";
        }
        bool pause() {
            cout << "==============================" << endl;
            cout << "Enter choice: ";
            char key;
            input.getChar(key);
            return key == KEY_RETURN;
        }
        void guide() {
            cout << "return: " << KEY_RETURN << endl;
            cout << "==============================" << endl;
        }
        void printTitle() {
            cout << "==============================" << endl;
            cout << GAME_TITLE << endl;
            cout << "==============================" << endl;
        }
        void showMenu() {
            cout << "==============================" << endl;
            for (int i = 0; i < options.size(); i++) {
                cout << i + 1 << ". " << options[i].first << endl;
            }
            cout << "==============================" << endl;
        }
        void initOption() {
            addOption("Show Map", &GameInterface::showMap);
            addOption("Show Player", &GameInterface::showPlayer);
            addOption("Show Shop", &GameInterface::showShop);
            addOption("Buy Item", &GameInterface::BuyItem);
            addOption("Sell Item", &GameInterface::SellItem);
            addOption("Talk to Trader", &GameInterface::TalkToTrader);
            addOption("Buy from Trader", &GameInterface::BuyFromTrader);
            addOption("Sell to Trader", &GameInterface::SellToTrader);
            addOption("Exit", &GameInterface::Exit);
        }
        bool showMap() {
            map.showMap();
            return pause();
        }
        bool showPlayer() {
            player.showInfo();
            return pause();
        }
        bool showShop() {
            shop.showInfo("not show items");
            shop.showItems("buy");
            return pause();
        }
        bool BuyItem() {
            if (TradeAction(player, shop, "buy") == RETURN) {
                return RETURN;
            }
            return pause();

        }
        bool SellItem() {
            if (TradeAction(player, shop, "sell") == RETURN) {
                return RETURN;
            }
            return pause();
        }
        bool TalkToTrader() {
            cout << "Enter trader index: ";
            int index;
            input.getInt(index);
            if (index > 0 && index <= traders.size()) {
                traders[index-1].showInfo();
            } else {
                cout << "Invalid input." << endl;
            }
        }
        bool BuyFromTrader() {
            cout << "Enter trader index: ";
            int index;
            input.getInt(index);
            if (index > 0 && index <= traders.size()) {
                TradeAction(player, traders[index-1], "buy");
            } else {
                cout << "Invalid input." << endl;
            }
        }
        bool SellToTrader() {
            cout << "Enter trader index: ";
            int index;
            input.getInt(index);
            if (index > 0 && index <= traders.size()) {
                TradeAction(player, traders[index-1], "sell");
            } else {
                cout << "Invalid input." << endl;
            }
        }
        bool Exit() {
            cout << "Exiting..." << endl;
            exit(0);
        }

        void run() {
            initOption();
            do { 
                showMenu();
                cout << "Enter choice: ";
                int choice;
                input.getInt(choice);
                if (choice > 0 && choice <= options.size()) {
                    do {
                        clearScreen();
                        guide();
                    }
                    while ((this->*options[choice-1].second)() == false);
                } else {
                    cout << "Invalid input." << endl;
                }
                clearScreen();
            } while (true);
        }
};

#endif