#ifndef DATABASEREADER_H
#define DATABASEREADER_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using std::ifstream, std::string, std::vector, std::cout, std::endl;

#include "Item.h"
#include "Inventory.h"
#include "Shop.h"
#include "Character.h"
#include "Map.h"

class ItemReader {
    private:
        ifstream file;
        string fileName;
        Inventory inventory;

    public:
// ------------------------- CONSTRUCTOR -------------------------
        ItemReader(string fileName, int amount = INFINITY_AMOUNT) {
            this->fileName = fileName;
            file.open(fileName);
            if (!file.is_open()) {
                cout << "Error opening file " << fileName << endl;
                exit(1);
            }
            string name;
            int price;
            string description;
            while (!file.eof()) {
                // ignore comments starting with #
                if (file.peek() == '#' || file.peek() == '\n') {
                    file.ignore(1000, '\n');
                    continue;
                }
                getline(file, name);
                file >> price;
                file.ignore();
                getline(file, description);
                inventory.addItem(Item(name, price, description), amount);
            }
            file.close();
        }
// ------------------------- GETTER -------------------------
        Inventory getInventory() {
            return inventory;
        }
};

class MapReader {
    private:
        ifstream file;
        string fileName;
        Map map;

    public:
// ------------------------- CONSTRUCTOR -------------------------
        MapReader(string fileName) {
            this->fileName = fileName;
            file.open(fileName);
            if (!file.is_open()) {
                cout << "Error opening file " << fileName << endl;
                exit(1);
            }
            string locationName;
            vector<LocationData> locations;
            while (!file.eof()) {
                // ignore comments starting with #
                if (file.peek() == '#' || file.peek() == '\n') {
                    file.ignore(1000, '\n');
                    continue;
                }
                getline(file, locationName);
                Distance distance;
                int distanceTo;
                while (file.peek() != '\n' && !file.eof()) {
                    file >> distanceTo;
                    distance.addDistance(distanceTo);
                }
                locations.push_back(LocationData(locationName, distance));
                file.ignore();
            }
            file.close();
            // map = Map(locations, distances);
            map = Map(locations);
        }

// ------------------------- GETTER -------------------------
        Map getMap() {
            return map;
        }
};

class LocationReader {
    private:
        ifstream file;
        string fileName;
        vector<LocationData> locations;

    public:
// ------------------------- CONSTRUCTOR -------------------------
        LocationReader(string fileName, Map &map, Inventory itemList) {
            this->fileName = fileName;
            file.open(fileName);
            if (!file.is_open()) {
                cout << "Error opening file " << fileName << endl;
                exit(1);
            }
            for (int i = 0; i < map.size(); i++) {
                string locationName;
                vector<Shop> shops;
                while (!file.eof()) {
                    // ignore comments starting with #
                    if (file.peek() == '#' || file.peek() == '\n') {
                        file.ignore(1000, '\n');
                        continue;
                    }
                    getline(file, locationName);
                    int shopNumber;
                    file >> shopNumber;
                    file.ignore();
                    for (int j = 0; j < shopNumber; j++) {
                        string shopName;
                        Inventory shopInventory;
                        getline(file, shopName);           
                        while (file.peek() != '\n' && !file.eof()) {
                            string item;
                            file >> item;
                            shopInventory.addItem(itemList.getItem(item), INFINITY_AMOUNT);
                        }
                        shops.push_back(Shop(shopName, shopInventory));
                    }
                    locations.push_back(LocationData(shops));
                    file.ignore();
                }
                
            }
            map = Map(locations);
            file.close();
        }

// ------------------------- GETTER -------------------------
        vector<LocationData> getLocations() {
            return locations;
        }
};  


#endif