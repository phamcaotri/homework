#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <iostream>
using std::string, std::cout, std::endl;

#include "Distance.h"

class Location {
    private:
        string name;
        Distance distance;
    public:
// ------------------------- CONSTRUCTOR -------------------------
        Location(string name, Distance distance) {
            this->name = name;
            this->distance = distance;
        }
// ------------------------- GETTERS, SETTERS -------------------------
        string getName() {
            return name;
        }
        int getDistanceTo(int index) {
            if (index < distance.getNumberOfDistances()) {
                return distance.getDistanceTo(index);
            } else {
                return -1;
            }
        }
        void addDistance(int distance) {
            this->distance.addDistance(distance);
        }
        void setName(string name) {
            this->name = name;
        }
        void setDistance(Distance distance) {
            this->distance = distance;
        }
        void removeDistanceTo(int index) {
            distance.removeDistanceTo(index);
        }
// ---------------- METHOD ----------------------
        void print() {
            cout << "Location: " << name << endl;
            cout << "Distances: ";
            for (int i = 0; i < distance.getNumberOfDistances(); i++) {
                cout << distance.getDistanceTo(i) << " ";
            }
            cout << endl;
        }
};

#endif