#include "GameInterface.h"
#include "DatabaseReader.h"

int main() {
    Character player("Mike8", 1000);

    Shop shop("Shop"), shop2("Shop2");
    ItemReader reader(ITEM_FILE);
    shop.setInventory(reader.getInventory());
    shop2.setInventory(reader.getInventory());

    MapReader mapReader("LocationDistanceMap.txt");
    Map map = mapReader.getMap();
    Location location(map.getLocationData(0).getLocationData());

    ItemReader reader2(ITEM_FILE, 3);
    Character trader("Michael", 100), trader2("David", 2000);
    trader.setInventory(reader2.getInventory());
    trader2.setInventory(reader2.getInventory());

    LocationData currentLocation(location, vector<Shop>{shop, shop2}, player, vector<Character>{trader, trader2});
    GameInterface game(map, currentLocation);
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
đánh bóng code
nâng cấp gameinterface
gom 2 thuộc tính map thành 1
tạo các địa điểm riêng biệt
xoá lớp windows ko cần thiết
Nâng cấp class GameInterface lần 2
làm người chơi có thể di chuyển giữa các khu vực
*/
/*--------------------------- TODO --------------------------------

khởi tạo các shop mặc định cho địa điểm đó
tạo danh sách các trader
cơ chế xem thông tin item
cơ chế đọc file từ file lưu game.
Thêm mô tả cho player
cơ chế lưu game
thêm class tiến trình thời gian
thêm class các sự kiện
thiết lập ai trader hoạt động độc lập với người chơi (hoạt động nền)
thiết lập các sự kiện hoạt động nền
*/
