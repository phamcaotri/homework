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

    MapReader mapReader("LocationDistanceMap.txt");
    mapReader.getMap().print();
    game.setMap(mapReader.getMap());

    game.run();
    return 0;
}

/* -------------------------- FINISH ------------------------------
các class cơ bản
cơ chế mua bán
cơ chế đọc file
cơ chế giá mua cao hơn giá bán
cơ chế mua bán giữa các character
class đọc input từ người dùng
thêm mua bán số lượng lớn
gom chung cha các class character, shop, thành một class entity
fix vấn đề làm tròn số
cơ chế tăng exp khi mua bán
xây dựng một môi trường game cơ bản
thêm class các địa điểm
*/
/*--------------------------- TODO --------------------------------
tạo danh sách các trader
cơ chế xem thông tin item
cơ chế đọc file từ file lưu game.
Thêm mô tả cho player
cơ chế lưu game
thêm class tiến trình thời gian
thêm class các sự kiện
nâng cấp gameinterface
thiết lập ai trader hoạt động độc lập với người chơi (hoạt động nền)
thiết lập các sự kiện hoạt động nền
*/
