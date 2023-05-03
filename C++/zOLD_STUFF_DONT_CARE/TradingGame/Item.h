#ifndef ITEM_H
#define ITEM_H

#include <string>
using std::string;

class Item {
    private:
        string name;
        int price;
        string description;
    public:
        Item() {
            name = "NoName";
            price = 0;
            description = "NoDescription";

        }
        Item(string name, int price, string description = "NoDescription") {
            this->name = name;
            this->price = price;
            this->description = description;
        }
        void setName(string name) {
            this->name = name;
        }
        void setPrice(int price) {
            this->price = price;
        }
        void setDescription(string description) {
            this->description = description;
        }
        string getName() {
            return name;
        }
        int getPrice() {
            return price;
        }
        string getDescription() {
            return description;
        }
};

#endif