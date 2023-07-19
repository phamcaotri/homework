#include <iostream>

using namespace std;

class Elevator {
    private:
        int current_floor;
        int max_floor;
        int min_floor;
        int capacity;
        int current_people;
        int time_per_floor;
        int time_acceleration;

    public:
        Elevator(int current_floor = 1, int max_floor = 10, int min_floor = 1, int capacity = 10, int current_people = 0, int time_per_floor = 1, int time_acceleration = 1) {
            this->current_floor = current_floor;
            this->max_floor = max_floor;
            this->min_floor = min_floor;
            this->capacity = capacity;
            this->current_people = current_people;
            this->time_per_floor = time_per_floor;
            this->time_acceleration = time_acceleration;
        }

        int move(int floor) {
            int time = 0;
            if (floor > max_floor || floor < min_floor) {
                cout << "Khong the di chuyen den tang " << floor << endl;
                return time;
            }
            if (floor == current_floor) {
                cout << "Da den tang " << floor << endl;
                return time;
            }
            time += time_acceleration;
            if (floor > current_floor) {
                for (int i = current_floor; i < floor; i++) {
                    time += time_per_floor;
                }
            } else {
                for (int i = current_floor; i > floor; i--) {
                    time += time_per_floor;
                }
            }
            current_floor = floor;
            cout << "Da di chuyen den tang " << floor << endl;
            return time;
        }

        void add_people(int people) {
            if (people + current_people > capacity) {
                cout << "Khong the them " << people << " nguoi vao thang may" << endl;
                return;
            }
            current_people += people;
            cout << "Da them " << people << " nguoi vao thang may" << endl;
        }

        void remove_people(int people) {
            if (current_people - people < 0) {
                cout << "Khong the xoa " << people << " nguoi khoi thang may" << endl;
                return;
            }
            current_people -= people;
            cout << "Da xoa " << people << " nguoi khoi thang may" << endl;
        }


};

class ElevatorSystem {
    private:
        int number_of_elevators;
        Elevator* elevators;

    public:
        ElevatorSystem(int number_of_elevators = 1) {
            this->number_of_elevators = number_of_elevators;
            elevators = new Elevator[number_of_elevators];
        }

        void move(int index, int floor) {
            if (index < 0 || index >= number_of_elevators) {
                cout << "Khong the di chuyen thang may tai vi tri " << index << endl;
                return;
            }
            elevators[index].move(floor);
        }

        void add_people(int index, int people) {
            if (index < 0 || index >= number_of_elevators) {
                cout << "Khong the them nguoi vao thang may tai vi tri " << index << endl;
                return;
            }
            elevators[index].add_people(people);
        }

        void remove_people(int index, int people) {
            if (index < 0 || index >= number_of_elevators) {
                cout << "Khong the xoa nguoi khoi thang may tai vi tri " << index << endl;
                return;
            }
            elevators[index].remove_people(people);
        }
};

int main() {
    return 0;
}