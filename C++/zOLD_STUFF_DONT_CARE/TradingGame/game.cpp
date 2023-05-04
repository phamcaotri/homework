#include "GameInterface.h"
#include "DatabaseReader.h"

int main() {
    Character player("Mike8", 100);
    Shop shop("Shop");
    ItemReader reader(ITEM_FILE);
    shop.setInventory(reader.getInventory());
    GameInterface game(player, shop);

    ItemReader reader2(ITEM_FILE, 3);
    Character trader("Michael", 1000);
    trader.setInventory(reader2.getInventory());
    game.addTrader(trader);
    game.run();
    return 0;
}

/* -------------------------- FINISH ------------------------------
các class cơ bản
cơ chế mua bán
cơ chế đọc file
cơ chế giá mua cao hơn giá bán
cơ chế mua bán giữa các character
*/
/*--------------------------- TODO --------------------------------
class đọc input từ người dùng
thêm mua bán số lượng lớn
cơ chế tăng exp khi mua bán
cơ chế lưu game
cơ chế xem thông tin item
cơ chế đọc file từ file lưu game.
xây dựng một môi trường game cơ bản
gom chung cha các class character, shop, item, thành một class entity
Thêm mô tả cho player

*/
