#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <iostream>
using std::vector, std::string, std::cout, std::endl;

#include "Distance.h"

class Map {
    private:
        vector<string> locations;
        vector<Distance> distances;
    public:
        Map() {}
        Map(vector<string> locations, vector<Distance> distances) {
            this->locations = locations;
            this->distances = distances;
        }
        string getLocationName(int index) {
            return locations[index];
        }
        int getDistance(int index1, int index2) {
            return distances[index1].getDistanceTo(index2);
        }
        void addLocation(string location) {
            locations.push_back(location);
            for (int i = 0; i < distances.size(); i++) {
                distances[i].addDistance(0);
            }
            Distance distance;
            for (int i = 0; i < locations.size(); i++) {
                distance.addDistance(0);
            }
            distances.push_back(distance);
        }
        void addDistance(int index1, int index2, int distance) {
            distances[index1].addDistance(distance);
            distances[index2].addDistance(distance);
        }
        void removeLocation(int index) {
            locations.erase(locations.begin() + index);
            distances.erase(distances.begin() + index);
            for (int i = 0; i < distances.size(); i++) {
                distances[i].removeDistanceTo(index);
            }
        }
        void setLocationName(int index, string name) {
            locations[index] = name;
        }
        int getNumberOfLocations() {
            return locations.size();
        }
        void print() {
            for (int i = 0; i < locations.size(); i++) {
                cout << locations[i] << endl;
            }
        }
};

#endif