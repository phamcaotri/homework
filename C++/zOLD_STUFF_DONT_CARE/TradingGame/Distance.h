#ifndef DISTANCE_H
#define DISTANCE_H

#include <vector>
#include <string>
using std::vector, std::string;
class Distance {
    private:
        vector<int> distances;
    public:
        int getDistanceTo(int index) {
            return distances[index];
        }
        void addDistance(int distance) {
            distances.push_back(distance);
        }
        void removeDistanceTo(int index) {
            distances.erase(distances.begin() + index);
        }
        int getNumberOfDistances() {
            return distances.size();
        }
        
};

#endif