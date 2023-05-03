#include "GameInterface.h"
#include "DatabaseReader.h"

int main() {
    Character player("Mike8", 100);
    Shop shop("Shop");
    ItemReader reader("ItemDatabase.txt");
    shop.setInventory(reader.getInventory());
    GameInterface game(player, shop);
    game.run();
    return 0;
}