#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <iostream>
using std::vector, std::string, std::cout, std::endl;

#include "LocationData.h"

class Map {
    private:
        vector<LocationData> locations;
    public:
// ------------------------- CONSTRUCTOR -------------------------
        Map() {}
        Map(vector<LocationData> locations) {
            this->locations = locations;
        }
// ------------------------- GETTERS, SETTERS, ADD, REMOVE -------------------------
        string getLocationName(int index) {
            return locations[index].getName();
        }
        int getDistance(int index1, int index2) {
            int distance = locations[index1].getDistanceTo(index2);
            if (distance == -1) {
                return locations[index2].getDistanceTo(index1);
            }
            return distance;
        }
        void addLocation(LocationData Location) {
            locations.push_back(Location);
            for (int i = 0; i < locations.size(); i++) {
                locations[i].addDistance(0);
            }
        }
        void removeLocation(int index) {
            locations.erase(locations.begin() + index);
            for (int i = 0; i < locations.size(); i++) {
                locations[i].removeDistanceTo(index);
            }
        }
        void setLocationName(int index, string name) {
            locations[index].setName(name);
        }
        int getNumberOfLocations() {
            return locations.size();
        }
        LocationData& operator[](int index) {
            return locations[index];
        }
// ------------------------- METHOD -------------------------
        void print() {
            for (int i = 0; i < locations.size(); i++) {
                locations[i].print();
            }
        }
        void showMap() {
            cout << "Map:" << endl;
            for (int i = 0; i < locations.size(); i++) {
                cout << i+1 << ". " << locations[i].getName() << endl;
            }
        }
        int size() {
            return locations.size();
        }
};

#endif