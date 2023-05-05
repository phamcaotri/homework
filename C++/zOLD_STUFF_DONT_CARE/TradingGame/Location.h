#ifndef LOCATION_H
#define LOCATION_H

#include <string>
using std::string;

#include "Distance.h"

class Location {
    private:
        string name;
        Distance distance;
    public:
        Location(string name, Distance distance) {
            this->name = name;
            this->distance = distance;
        }
        string getName() {
            return name;
        }
        int getDistanceTo(int index) {
            return distance.getDistanceTo(index);
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
};

#endif