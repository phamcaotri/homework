#ifndef DISTANCE_H
#define DISTANCE_H

#include <vector>
#include <string>
using std::vector, std::string;
class Distance {
    private:
        vector<int> distances;
    public:
        Distance() {}
        Distance(vector<int> distances) {
            this->distances = distances;
        }
        Distance(int numberOfDistances) {
            for (int i = 0; i < numberOfDistances; i++) {
                distances.push_back(0);
            }
        }
        int getDistanceTo(int index) {
            if (index < distances.size()) {
                return distances[index];
            } else {
                return -1;
            }
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