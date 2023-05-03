#include "GameInterface.h"

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