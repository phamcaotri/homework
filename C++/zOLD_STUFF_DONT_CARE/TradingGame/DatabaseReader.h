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
                getline(file, name);
                file >> price;
                file.ignore();
                getline(file, description);
                inventory.addItem(Item(name, price, description), amount);
            }
            file.close();
        }
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
        MapReader(string fileName) {
            this->fileName = fileName;
            file.open(fileName);
            if (!file.is_open()) {
                cout << "Error opening file " << fileName << endl;
                exit(1);
            }
            string locationName;
            vector<string> locations;
            Distance distance;
            vector<Distance> distances;
            while (!file.eof()) {
                getline(file, locationName);
                locations.push_back(locationName);
                for (int i = 0; i < locations.size(); i++) {
                    distance.addDistance(-1);
                }
                distances.push_back(distance);
                for (int i = 0; i < locations.size(); i++) {
                    int d;
                    file >> d;
                    distances[i].addDistance(d);
                }
                file.ignore();
            }
            file.close();
            map = Map(locations, distances);
        }
        Map getMap() {
            return map;
        }
};

#endif