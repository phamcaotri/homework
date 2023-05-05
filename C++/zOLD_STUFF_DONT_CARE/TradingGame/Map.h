#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <iostream>
using std::vector, std::string, std::cout, std::endl;

#include "Location.h"

class Map {
    private:
        // vector<string> locations;
        // vector<Distance> distances;
        vector<Location> locations;
    public:
// ------------------------- CONSTRUCTOR -------------------------
        Map() {}
        // Map(vector<string> locations, vector<Distance> distances) {
        //     this->locations = locations;
        //     this->distances = distances;
        // }
        Map(vector<Location> locations) {
            this->locations = locations;
        }
// ------------------------- GETTERS, SETTERS, ADD, REMOVE -------------------------
        // string getLocationName(int index) {
        //     return locations[index];
        // }
        string getLocationName(int index) {
            return locations[index].getName();
        }
        // int getDistance(int index1, int index2) {
        //     int distance = distances[index1].getDistanceTo(index2);
        //     if (distance == -1) {
        //         return distances[index2].getDistanceTo(index1);
        //     }
        //     return distance;
        // }
        int getDistance(int index1, int index2) {
            int distance = locations[index1].getDistanceTo(index2);
            if (distance == -1) {
                return locations[index2].getDistanceTo(index1);
            }
            return distance;
        }
        // void addLocation(string location) {
        //     locations.push_back(location);
        //     for (int i = 0; i < distances.size(); i++) {
        //         distances[i].addDistance(0);
        //     }
        //     Distance distance;
        //     for (int i = 0; i < locations.size(); i++) {
        //         distance.addDistance(0);
        //     }
        //     distances.push_back(distance);
        // }
        void addLocation(Location Location) {
            locations.push_back(Location);
            for (int i = 0; i < locations.size(); i++) {
                locations[i].addDistance(0);
            }
        }
        // void removeLocation(int index) {
        //     locations.erase(locations.begin() + index);
        //     distances.erase(distances.begin() + index);
        //     for (int i = 0; i < distances.size(); i++) {
        //         distances[i].removeDistanceTo(index);
        //     }
        // }
        void removeLocation(int index) {
            locations.erase(locations.begin() + index);
            for (int i = 0; i < locations.size(); i++) {
                locations[i].removeDistanceTo(index);
            }
        }
        // void setLocationName(int index, string name) {
        //     locations[index] = name;
        // }
        void setLocationName(int index, string name) {
            locations[index].setName(name);
        }
        int getNumberOfLocations() {
            return locations.size();
        }
// ------------------------- METHOD -------------------------
        // void print() {
        //     for (int i = 0; i < locations.size(); i++) {
        //         cout << locations[i] << endl;
        //         for (int j = 0; j < locations.size(); j++) {
        //             cout << getDistance(i, j) << " ";
        //         }
        //         cout << endl;
        //     }
        // }
        void print() {
            for (int i = 0; i < locations.size(); i++) {
                locations[i].print();
            }
        }
        // void showMap() {
        //     cout << "Map:" << endl;
        //     for (int i = 0; i < locations.size(); i++) {
        //         cout << locations[i] << endl;
        //     }
        // }
        void showMap() {
            cout << "Map:" << endl;
            for (int i = 0; i < locations.size(); i++) {
                cout << locations[i].getName() << endl;
            }
        }
};

#endif