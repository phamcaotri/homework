#ifndef ITEM_H
#define ITEM_H

#include <string>
using std::string;

class Item {
    private:
        string name;
        int price;
    public:
        Item() {
            name = "NoName";
            price = 0;

        }
        Item(string name, int price) {
            this->name = name;
            this->price = price;
        }
        void setName(string name) {
            this->name = name;
        }
        void setPrice(int price) {
            this->price = price;
        }
        string getName() {
            return name;
        }
        int getPrice() {
            return price;
        }
};

#endif