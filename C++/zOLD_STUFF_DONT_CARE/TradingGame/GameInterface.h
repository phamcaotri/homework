#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include "Character.h"
#include "Shop.h"
#include "UserInput.h"
#include "Map.h"
#include "CurrentLocation.h"
#include "Options.h"

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
    input.getPairInt(index, amount, 0, 0);
    if (action == "buy") {
        if (trader.isValidIndex(index-1) && trader.isValidAmount(index-1, amount)) {
            player.BuyFrom(trader, index-1, amount);
        }
    } else if (action == "sell") {
        if (player.isValidIndex(index-1) && player.isValidAmount(index-1, amount)) {
            player.SellTo(trader, index-1, amount);
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
        Location currentLocation;
        Options<GameInterface> options;
    public:
// ------------------------- CONSTRUCTOR -------------------------
        GameInterface() {
            player = Character();
            traders = vector<Character>();
            shop = Shop();
            map = Map();
            currentLocation = Location();
            options = Options<GameInterface>();
        }
        GameInterface(Character player = Character(), Shop shop = Shop(), Map map = Map(), Location currentLocation = Location()) {
            this->player = player;
            this->shop = shop;
            this->map = map;
            this->currentLocation = currentLocation;
        }
        GameInterface(Map map, CurrentLocation currentLocation) {
            this->player = currentLocation.getPlayer();
            this->traders = currentLocation.getTraders();
            this->shop = currentLocation.getShop();
            this->map = map;
            this->currentLocation = currentLocation.getLocation();
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
        bool returnBack() {
            return RETURN;
        }
        void printTitle() {
            cout << "==============================" << endl;
            cout << GAME_TITLE << endl;
            cout << "==============================" << endl;
        }
        void showMenu() {
            cout << "You are at " << currentLocation.getName() << endl;
            cout << "==============================" << endl;
            options.showOptions();
            cout << "==============================" << endl;
        }
        void initMenu() {
            options.addOption("Show Map", &GameInterface::showMap);
            options.addOption("Show Player", &GameInterface::showPlayer);
            options.addOption("Show Shop", &GameInterface::showShop);
            options.addOption("Talk to Trader", &GameInterface::TalkToTrader);
            options.addOption("Exit", &GameInterface::Exit, true);
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
            Options<GameInterface> sub_options;
            sub_options.addOption("Buy Item", &GameInterface::BuyItem);
            sub_options.addOption("Sell Item", &GameInterface::SellItem);
            sub_options.addOption("Return (other keys)", &GameInterface::returnBack, true);
            while (sub_options.getChoice(this) == NO_RETURN) {}
            return RETURN;
        }
        bool BuyItem() {
            return TradeAction(player, shop, "buy");
        }
        bool SellItem() {
            return TradeAction(player, shop, "sell");
        }
        bool TalkToTrader() {
            cout << "Enter trader index: ";
            int index;
            input.getInt(index);
            if (index == 0) {
                return RETURN;
            }
            if (index > 0 && index <= traders.size()) {
                traders[index-1].showInfo();
            } else {
                cout << "Invalid input." << endl;
            }
            return pause();
        }
        bool BuyFromTrader() {
            cout << "Enter trader index: ";
            int index;
            input.getInt(index);
            if (index == 0) {
                return RETURN;
            }
            if (index > 0 && index <= traders.size()) {
                TradeAction(player, traders[index-1], "buy");
            } else {
                cout << "Invalid input." << endl;
            }
            return pause();
        }
        bool SellToTrader() {
            cout << "Enter trader index: ";
            int index;
            input.getInt(index);
            if (index == 0) {
                return RETURN;
            }
            if (index > 0 && index <= traders.size()) {
                TradeAction(player, traders[index-1], "sell");
            } else {
                cout << "Invalid input." << endl;
            }
            return pause();
        }
        bool Exit() {
            cout << "Exiting..." << endl;
            exit(0);
        }

        void run() {
            initMenu();
            do { 
                showMenu();
                cout << "Enter choice: ";
                int choice;
                input.getInt(choice);
                if (choice > 0 && choice <= options.size()) {
                    do {
                        clearScreen();
                    }
                    while (options.run(choice-1, this) == NO_RETURN);
                } else {
                    cout << "Invalid input." << endl;
                }
                clearScreen();
            } while (true);
        }
};

#endif