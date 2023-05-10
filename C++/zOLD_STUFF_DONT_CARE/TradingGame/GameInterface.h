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
        player.showItems("sell");
    }
    cout << "You have " << player.getCoin() << COIN_SYMBOL << "." << endl;
    cout << "Enter item index and amount (default = 1): ";
    int index, amount = 1;
    input.getPairInt(index, amount, 0, 0);
    if (action == "buy") {
        if (trader.isValidIndex(index-1) && trader.isValidAmount(index-1, amount)) {
            player.BuyFrom(trader, index-1, amount);
        } else {
            cout << "Invalid index or amount." << endl;
        }
    } else if (action == "sell") {
        if (player.isValidIndex(index-1) && player.isValidAmount(index-1, amount)) {
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
        vector<Character> traders;
        vector<Shop> shops;
        UserInput input;
        Map map;
        LocationData currentLocation;
        Options<GameInterface> options;
    public:
// ------------------------- CONSTRUCTOR -------------------------
        GameInterface() {
            player = Character();
            traders = vector<Character>();
            shops = vector<Shop>();
            map = Map();
            currentLocation = LocationData();
            options = Options<GameInterface>();
        }
        GameInterface(Character player = Character(), vector<Shop> shops = vector<Shop>(), Map map = Map(), LocationData currentLocation = LocationData()) {
            this->player = player;
            this->shops = shops;
            this->map = map;
            this->currentLocation = currentLocation;
        }
        GameInterface(Map map, LocationData currentLocation) {
            this->traders = currentLocation.getTraders();
            this->shops = currentLocation.getShops();
            this->map = map;
            this->currentLocation = currentLocation;
        }
// ------------------------- GETTERS, SETTER, ADD, REMOVE -------------------------
        void setPlayer(Character player) {
            this->player = player;
        }
        void setTraders(vector<Character> traders) {
            this->traders = traders;
        }
        void setShops(vector<Shop> shops) {
            this->shops = shops;
        }
        Character getPlayer() {
            return player;
        }
        vector<Character> getTraders() {
            return traders;
        }
        vector<Shop> getShops() {
            return shops;
        }
        void setMap(Map map) {
            this->map = map;
        }
        void addTrader(Character trader) {
            traders.push_back(trader);
        }
        void updateLocation(LocationData currentLocation) {
            this->traders = currentLocation.getTraders();
            this->shops = currentLocation.getShops();
            this->map = map;
            this->currentLocation = currentLocation;
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
            cout << "You are at " << currentLocation.getName() << endl;
            cout << "==============================" << endl;
            options.showOptions();
            cout << "==============================" << endl;
        }
        void initMenu() {
            options.addOption("Show Map", &showMap);
            options.addOption("Show Player", &showPlayer);
            options.addOption("Show Shop", &showShop);
            options.addOption("Talk to Trader", &TalkToTrader);
            options.addOption("Exit", &Exit);
        }
        bool showMap(int) {
            map.showMap();
            Options<GameInterface> sub_options;
            sub_options.addOption("Go to", &GoTo);
            sub_options.addOption("Return", &returnBack, true);
            while (sub_options.getChoice(this) == NO_RETURN) {}
            return RETURN;
        }
        bool GoTo(int) {
            map.showMap();
            cout << "Go to location: ";
            int index;
            input.getInt(index, 0);
            if (index > 0 && index <= map.size()) {
                cout << "You are at " << map.getLocationData(index-1).getName() << endl;
                currentLocation = map.getLocationData(index-1);
                updateLocation(currentLocation);
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
            for (int i = 0; i < shops.size(); i++) {
                cout << i+1 << ". " << shops[i].getName() << endl;
            }
            cout << "Go to shop: ";
            int index;
            input.getInt(index, 0);
            if (index > 0 && index <= shops.size()) {
                cout << "You are at " << shops[index-1].getName() << endl;
                Shop shop = shops[index-1];
                shop.showInfo("show items");
                Options<GameInterface> sub_options;
                sub_options.addOption("Buy Item", &BuyItem);
                sub_options.addOption("Sell Item", &SellItem);
                sub_options.addOption("Return", &returnBack, true);
                while (sub_options.getChoice(this, index) == NO_RETURN) {}
            }
            return RETURN;
        }
        bool BuyItem(int index = 0) {
            return TradeAction(player, shops[index-1], "buy");
        }
        bool SellItem(int index = 0) {
            return TradeAction(player, shops[index-1], "sell");
        }
        bool TalkToTrader(int) {
            cout << "You can talk to these traders: " << endl;
            for (int i = 0; i < traders.size(); i++) {
                cout << i+1 << ". " << traders[i].getName() << endl;
            }
            cout << "Talk to trader: ";
            int index;
            input.getInt(index, 0);
            if (index > 0 && index <= traders.size()) {
                traders[index-1].showInfo();
                Options<GameInterface> sub_options;
                sub_options.addOption("Buy Item", &BuyFromTrader);
                sub_options.addOption("Sell Item", &SellToTrader);
                sub_options.addOption("Return", &returnBack, true);
                while (sub_options.getChoice(this, index) == NO_RETURN) {}
            }
            return RETURN;
        }
        bool BuyFromTrader(int index = 0) {
            return TradeAction(player, traders[index-1], "buy");
        }
        bool SellToTrader(int index = 0) {
            return TradeAction(player, traders[index-1], "sell");
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
                cout << "You are at " << currentLocation.getName() << endl;
                options.getChoice(this);
            }
        }
};

#endif