#ifndef CURRENTLOCATION_H
#define CURRENTLOCATION_H

#include <string>
#include <vector>
#include <iostream>
using std::string, std::vector, std::cout, std::endl;

#include "Location.h"
#include "UserInput.h"
#include "Shop.h"
#include "Character.h"

class CurrentLocation {
    private:
        Location location;
        UserInput input;

        vector<Shop> shops;
        Character player;
        vector<Character> traders;
    public:
// ------------------------- CONSTRUCTOR -------------------------
        CurrentLocation() {
            location = Location();
            input = UserInput();
            shops = vector<Shop>();
            player = Character();
            traders = vector<Character>();
        }
        CurrentLocation(Location location, vector<Shop> shops, Character player, vector<Character> traders) {
            this->location = location;
            this->shops = shops;
            this->player = player;
            this->traders = traders;
        }
        CurrentLocation(CurrentLocation& currentLocation) {
            location = currentLocation.location;
            shops = currentLocation.shops;
            player = currentLocation.player;
            traders = currentLocation.traders;
        }
// ------------------------- GETTERS, SETTERS ---------------------
        Character getPlayer() {
            return player;
        }
        void setPlayer(Character player) {
            this->player = player;
        }
        Shop getShop() {
            return shops[0];
        }
        void setShop(Shop shop) {
            shops[0] = shop;
        }
        Location getLocation() {
            return location;
        }
        vector<Character> getTraders() {
            return traders;
        }

};

#endif