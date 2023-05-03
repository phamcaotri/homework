#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using std::cout, std::cin, std::endl, std::string, std::vector;

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

class Level {
    private:
        int lv;
        int exp;
        int maxExp;

    public:
        Level() {
            lv = 1;
            exp = 0;
            maxExp = 100;
        }
        void setLv(int lv) {
            this->lv = lv;
            maxExp = calMaxExp();
        }
        void setExp(int exp) {
            this->exp = exp;
            setMaxExp();
        }
        void setMaxExp() {
            while (exp >= maxExp) {
                exp -= maxExp;
                lv++;
                maxExp = calMaxExp();
            }
        }
        int getLv() {
            return lv;
        }
        int getExp() {
            return exp;
        }
        int getMaxExp() {
            return maxExp;
        }
        int calMaxExp() {
            return lv*(500+lv*250);
        }
        void addExp(int exp) {
            this->exp += exp;
            setMaxExp();
        }
};

class Inventory {
    private:
        vector<std::pair<Item, int>> items;

    public:
        Inventory() {}
        void addItem(Item item, int amount) {
            for (int i = 0; i < items.size(); i++) {
                if (items[i].first.getName() == item.getName()) {
                    items[i].second += amount;
                    return;
                }
            }
            items.push_back(std::make_pair(item, amount));
        }
        void removeItem(Item item, int amount) {
            for (int i = 0; i < items.size(); i++) {
                if (items[i].first.getName() == item.getName()) {
                    items[i].second -= amount;
                    if (items[i].second <= 0) {
                        items.erase(items.begin()+i);
                    }
                    return;
                }
            }
        }
        void showItems() {
            if (items.size() == 0) {
                cout << "No items" << endl;
                return;
            }
            for (int i = 0; i < items.size(); i++) {
                cout << items[i].first.getName() << " x" << items[i].second << endl;
            }
        }
        vector<std::pair<Item, int>> getItems() {
            return items;
        }
}; 

class Character {
    protected:
        string name;
        Level lv;
        int gold;
        Inventory Inventory;
    public:
        Character() {
            name = "NoName";
            gold = 0;
        }
        Character(string name) {
            this->name = name;
            gold = 0;
        }
        Character(string name, int gold) {
            this->name = name;
            this->gold = gold;
        }
        void showInfo() {
            cout << "Name: " << name << endl;
            cout << "Lv: " << lv.getLv() << endl;
            cout << "Exp: " << lv.getExp() << "/" << lv.getMaxExp() << endl;
            cout << "Gold: " << gold << endl;
            cout << "Items: " << endl;
            Inventory.showItems();
        }
        void setName(string name) {
            this->name = name;
        }
        void setGold(int gold) {
            this->gold = gold;
        }
        string getName() {
            return name;
        }
        int getGold() {
            return gold;
        }
        void addGold(int gold) {
            this->gold += gold;
        }
        void addExp(int exp) {
            lv.addExp(exp);
        }
        void addItem(Item item, int amount) {
            Inventory.addItem(item, amount);
        }
        void removeItem(Item item, int amount) {
            Inventory.removeItem(item, amount);
        }
        void showItems() {
            Inventory.showItems();
        }
        vector<std::pair<Item, int>> getItems() {
            return Inventory.getItems();
        }

};

class Shop {
    private:
        string name;
        vector<std::pair<Item, int>> items;
        static const int infinity = 999999999;
    public:
        Shop() {
            name = "NoName";
        }
        Shop(string name) {
            this->name = name;
        }
        void setName(string name) {
            this->name = name;
        }
        string getName() {
            return name;
        }
        void addItem(Item item, int amount = 1) {
            items.push_back(std::make_pair(item, amount));
        }
        void removeItem(int index) {
            if (index >= 0 && index < items.size()) {
                items.erase(items.begin()+index);
                return;
            }
            cout << "cannot removed" << endl;
        }
        void removeItem(string name) {
            for (int i = 0; i < items.size(); i++) {
                if (items[i].first.getName() == name) {
                    items.erase(items.begin()+i);
                    break;
                }
            }
            cout << "cannot removed" << endl;
        }
        void showItems() {
            cout << "Shop: " << name << endl;
            for (int i = 0; i < items.size(); i++) {
                cout << i+1 << ". " << items[i].first.getName() << " - " << items[i].first.getPrice() << " gold" << " x" << items[i].second << endl;
            }
        }
        Item getItem(int index) {
            return items[index].first;
        }
        Item getItem(string name) {
            for (int i = 0; i < items.size(); i++) {
                if (items[i].first.getName() == name) {
                    return items[i].first;
                }
            }
            return Item();
        }
        int getSize() {
            return items.size();
        }
        void Buy(Item item, Character &player) {
            if (player.getGold() >= item.getPrice()) {
                player.setGold(player.getGold()-item.getPrice());
                player.addItem(item, 1);
                cout << "You bought " << item.getName() << " for " << item.getPrice() << " gold." << endl;
            } else {
                cout << "You don't have enough gold to buy " << item.getName() << "." << endl;
            }
        }
        void Sell(Item item, Character &player) {
            for (int i = 0; i < player.getItems().size(); i++) {
                if (player.getItems()[i].first.getName() == item.getName()) {
                    player.removeItem(item, 1);
                    player.setGold(player.getGold()+item.getPrice());
                    cout << "You sold " << item.getName() << " for " << item.getPrice() << " gold." << endl;
                    return;
                }
            }
            cout << "You don't have " << item.getName() << "." << endl;
        }
};

class GameInterface {
    private:
        Character player;
        Shop shop;
    public:
        GameInterface() {
            player = Character();
            shop = Shop();
        }
        GameInterface(Character player, Shop shop) {
            this->player = player;
            this->shop = shop;
        }
        void setPlayer(Character player) {
            this->player = player;
        }
        void setShop(Shop shop) {
            this->shop = shop;
        }
        Character getPlayer() {
            return player;
        }
        Shop getShop() {
            return shop;
        }
        void showPlayer() {
            player.showInfo();
        }
        void showShop() {
            shop.showItems();
        }
        void showInterface() {
            cout << "1. Show Player" << endl;
            cout << "2. Show Shop" << endl;
            cout << "3. Buy Item" << endl;
            cout << "4. Sell Item" << endl;
            cout << "5. Exit" << endl;
        }
        void BuyItem() {
            int index;
            cout << "Enter item index: ";
            cin >> index;
            if (index > 0 && index <= shop.getSize()) {
                shop.Buy(shop.getItem(index-1), player);
            } else {
                cout << "Invalid index." << endl;
            }
        }
        void SellItem() {
            int index;
            cout << "Enter item index: ";
            cin >> index;
            if (index > 0 && index <= shop.getSize()) {
                shop.Sell(shop.getItem(index-1), player);
            } else {
                cout << "Invalid index." << endl;
            }
        }
        void run() {
            int choice;
            do {
                showInterface();
                cout << "Enter choice: ";
                cin >> choice;
                cout << "\n-------------------------" << endl;
                switch (choice) {
                    case 1:
                        showPlayer();
                        break;
                    case 2:
                        showShop();
                        break;
                    case 3:
                        BuyItem();
                        break;
                    case 4:
                        SellItem();
                        break;
                    case 5:
                        cout << "Exiting..." << endl;
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                }
                cout << "-------------------------" << endl << endl;
            } while (choice != 5);
        }

};
int main() {
    Character player("Mike8", 100);
    Shop shop("Shop");
    shop.addItem(Item("Rice", 10));
    shop.addItem(Item("Sugar", 20));
    shop.addItem(Item("Wood", 30));
    shop.addItem(Item("Iron", 40));
    shop.addItem(Item("Oil", 50));
    GameInterface game(player, shop);
    game.run();
    return 0;
}