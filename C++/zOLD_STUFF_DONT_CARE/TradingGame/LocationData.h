#ifndef LOCATIONDATA_H
#define LOCATIONDATA_H

#include <string>
#include <vector>
#include <iostream>
using std::string, std::vector, std::cout, std::endl;

#include "Location.h"
#include "UserInput.h"
#include "Shop.h"
#include "Character.h"

class LocationData {
    private:
        Location location;
        vector<Shop> shops;
        vector<Character> traders;
    public:
// ------------------------- CONSTRUCTOR -------------------------
        LocationData(Location location = Location(), vector<Shop> shops = vector<Shop>(), vector<Character> traders = vector<Character>()) {
            this->location = location;
            this->shops = shops;
            this->traders = traders;
        }
        LocationData& operator=(const LocationData& currentLocation) {
            location = currentLocation.location;
            shops = currentLocation.shops;
            traders = currentLocation.traders;
            return *this;
        }
// ------------------------- GETTERS, SETTERS ---------------------
        vector<Shop> getShops() {
            return shops;
        }
        void setShops(vector<Shop> shops) {
            this->shops = shops;
        }
        Location getLocationData() {
            return location;
        }
        vector<Character> getTraders() {
            return traders;
        }
        string getName() {
            return location.getName();
        }
        int getDistanceTo(int index) {
            return location.getDistanceTo(index);
        }
        void addDistance(int distance) {
            location.addDistance(distance);
        }
        void setName(string name) {
            location.setName(name);
        }
        void setDistance(Distance distance) {
            location.setDistance(distance);
        }
        void removeDistanceTo(int index) {
            location.removeDistanceTo(index);
        }
        void addShop(Shop shop) {
            shops.push_back(shop);
        }
        void addTrader(Character trader) {
            traders.push_back(trader);
        }
        void removeShop(int index) {
            shops.erase(shops.begin() + index);
        }
        void removeTrader(int index) {
            traders.erase(traders.begin() + index);
        }

// ------------------------ METHOD ------------------------
        void print() {
            location.print();
            cout << "Shops: " << endl;
            for (int i = 0; i < shops.size(); i++) {
                cout << shops[i].getName() << endl;
            }
            cout << "Traders: " << endl;
            for (int i = 0; i < traders.size(); i++) {
                cout << traders[i].getName() << endl;
            }
        }

};

#endif