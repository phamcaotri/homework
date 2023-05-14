#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Constant.h"
using std::string;

class Item {
    private:
        string name;
        int price;
        string description;
    public:
// ------------------------- CONSTRUCTOR -------------------------
        Item(string name = DEFAULT_NONAME, int price = 0, string description = DEFAULT_NODESCRIPTION) {
            this->name = name;
            this->price = price;
            this->description = description;
        }
// ------------------------- GETTER -------------------------
        string& getName() {
            return name;
        }
        int& getPrice() {
            return price;
        }
        string& getDescription() {
            return description;
        }
};

#endif