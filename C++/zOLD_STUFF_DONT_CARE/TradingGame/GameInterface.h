#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include "Character.h"
#include "Shop.h"
#include "UserInput.h"
#include "Map.h"
#include "LocationData.h"
#include "Options.h"

bool TradeAction(Entity& player, Entity& trader, string action) {
    UserInput input;
    if (action == "buy") {
        trader.showItems("buy");
    } else if (action == "sell") {
        player.showItems_setPrice("sell", trader.getSellMultiplier());
    }
    cout << "You have " << player.getCoin() << COIN_SYMBOL << "." << endl;
    cout << "Enter item index and amount (default = 1): ";
    int index, amount = 1;
    input.getPairInt(index, amount, 0, 0);
    if (action == "buy") {
        if (trader.getInventory().isValidIndex(index-1) && trader.getInventory().isValidAmount(index-1, amount)) {
            player.BuyFrom(trader, index-1, amount);
        } else {
            cout << "Invalid index or amount." << endl;
        }
    } else if (action == "sell") {
        if (player.getInventory().isValidIndex(index-1) && player.getInventory().isValidAmount(index-1, amount)) {
            player.SellTo(trader, index-1, amount);
        } else {
            cout << "Invalid index or amount." << endl;
        }
    }
    return NO_RETURN;
}

class GameInterface {
    private:
        Character player;
        UserInput input;
        Map map;
        int mapIndex;
        Options<GameInterface> options;
    public:
// ------------------------- CONSTRUCTOR -------------------------
        GameInterface() {
            player = Character();
            map = Map();
            mapIndex = 0;
            options = Options<GameInterface>();
        }
        GameInterface(Character player, Map &map, int startLocation = 0) {
            this->player = player;
            this->map = map;
            mapIndex = startLocation;
        }
// ------------------------- GETTERS, SETTER, ADD, REMOVE -------------------------
        void setPlayer(Character player) {
            this->player = player;
        }
        Character getPlayer() {
            return player;
        }
        vector<Character>& getTraders() {
            return map[mapIndex].getTraders();
        }
        vector<Shop>& getShops() {
            return map[mapIndex].getShops();
        }
// ------------------------- METHOD -------------------------
        void clearScreen() {
            cout << "\033[2J\033[1;1H";
        }
        bool returnBack(int) {
            return RETURN;
        }
        void printTitle() {
            cout << "==============================" << endl;
            cout << GAME_TITLE << endl;
            cout << "==============================" << endl;
        }
        void showMenu() {
            cout << "You are at " << map[mapIndex].getName() << endl;
            cout << "==============================" << endl;
            options.showOptions();
            cout << "==============================" << endl;
        }
        void initMenu() {
            options.addOption("Show Map", &showMap);
            options.addOption("Show Player", &showPlayer);
            options.addOption("Show Shop", &showShop);
            options.addOption("Talk to Trader", &TalkToTrader);
            options.addOption("Next Day", &NextDay);
            options.addOption("Exit", &Exit);
        }
        bool showMap(int) {
            cout << map.getImage();
            map.showMap();
            Options<GameInterface> sub_options;
            sub_options.addOption("Go to", &GoTo);
            sub_options.addOption("Return", &returnBack, true);
            while (sub_options.getChoice(this) == NO_RETURN) {}
            return RETURN;
        }
        bool GoTo(int) {
            cout << map.getImage();
            map.showMap();
            cout << "Go to location: ";
            int index;
            input.getInt(index, 0);
            if (index > 0 && index <= map.size()) {
                cout << "You are at " << map[index-1].getName() << endl;
                this->mapIndex = index-1;
                return NO_RETURN;
            } else {
                cout << "Invalid index." << endl;
                return RETURN;
            }
        }
        bool showPlayer(int) {
            player.showInfo();
            Options<GameInterface> sub_options;
            sub_options.addOption("Return", &returnBack, true);
            while (sub_options.getChoice(this) == NO_RETURN) {}
            return RETURN;
        }
        bool showShop(int) {
            cout << "You can go to these shops: " << endl;
            for (int i = 0; i < map[mapIndex].getShops().size(); i++) {
                cout << i+1 << ". " << map[mapIndex].getShops()[i].getName() << endl;
            }
            cout << "Go to shop: ";
            int index;
            input.getInt(index, 0);
            if (index > 0 && index <= map[mapIndex].getShops().size()) {
                cout << "You are at " << map[mapIndex].getShops()[index-1].getName() << endl;
                map[mapIndex].getShops()[index-1].showInfo("show items");
                map[mapIndex].getShops()[index-1].showMultiplier();
                Options<GameInterface> sub_options;
                sub_options.addOption("Buy Item", &BuyItem);
                sub_options.addOption("Sell Item", &SellItem);
                sub_options.addOption("Return", &returnBack, true);
                while (sub_options.getChoice(this, index) == NO_RETURN) {}
            }
            return RETURN;
        }
        bool BuyItem(int index = 0) {
            return TradeAction(player, map[mapIndex].getShops()[index-1], "buy");
        }
        bool SellItem(int index = 0) {
            return TradeAction(player, map[mapIndex].getShops()[index-1], "sell");
        }
        bool TalkToTrader(int) {
            cout << "You can talk to these traders: " << endl;
            for (int i = 0; i < map[mapIndex].getTraders().size(); i++) {
                cout << i+1 << ". " << map[mapIndex].getTraders()[i].getName() << endl;
            }
            cout << "Talk to trader: ";
            int index;
            input.getInt(index, 0);
            if (index > 0 && index <= map[mapIndex].getTraders().size()) {
                map[mapIndex].getTraders()[index-1].showInfo();
                Options<GameInterface> sub_options;
                sub_options.addOption("Buy Item", &BuyFromTrader);
                sub_options.addOption("Sell Item", &SellToTrader);
                sub_options.addOption("Return", &returnBack, true);
                while (sub_options.getChoice(this, index) == NO_RETURN) {}
            }
            return RETURN;
        }
        bool BuyFromTrader(int index = 0) {
            return TradeAction(player, map[mapIndex].getTraders()[index-1], "buy");
        }
        bool SellToTrader(int index = 0) {
            return TradeAction(player, map[mapIndex].getTraders()[index-1], "sell");
        }
        int day = 0;
        float supply = 100;
        float demand = 100;
        float market = 100;
        float security = 100;
        bool NextDay(int) {
            day++;
            for (int i = 0; i < map.size(); i++)
                for (int j = 0; j < map[i].getShops().size(); j++) {
                    supply += 5 - rand()%10;
                    demand += 5 - rand()%10;
                    market += 5 - rand()%10;
                    security += 5 - rand()%10;
                    map[i].getShops()[j].MultiplierCalculate(supply/100, demand/100, market/100, security/100);
                }
            //map[mapIndex].getShops()[0].nextDay();
            // for (int i = 0; i < map[mapIndex].getTraders().size(); i++) {
            //     map[mapIndex].getTraders()[i].nextDay();
            // }
            return RETURN;
        }
        bool Exit(int) {
            cout << "Exiting..." << endl;
            exit(0);
        }

        void run() {
            initMenu();
            while (true) {
                clearScreen();
                printTitle();
                cout << "You are at " << map[mapIndex].getName() << endl;
                cout << "number of days: " << day << endl;
                options.getChoice(this);
            }
        }
};

#endif