#include "GameInterface.h"
#include "DatabaseReader.h"

int main() {
    Character player("Mike8", 100);
    Shop shop("Shop");
    ItemReader reader(ITEM_FILE);
    shop.setInventory(reader.getInventory());
    GameInterface game(player, shop);
    game.run();
    return 0;
}

/* -------------------------- FINISH ------------------------------
các class cơ bản
cơ chế mua bán
cơ chế đọc file

*/
/*--------------------------- TODO --------------------------------
cơ chế giá mua cao hơn giá bán
cơ chế mua bán giữa các character
thêm mua bán số lượng lớn
cơ chế tăng exp khi mua bán
cơ chế lưu game
cơ chế xem thông tin item
cơ chế đọc file từ file lưu game.

*/
