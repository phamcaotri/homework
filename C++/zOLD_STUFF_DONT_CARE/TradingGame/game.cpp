#include "GameInterface.h"
#include "DatabaseReader.h"

int main() {
    Character player("Mike8", 1000);

    ItemReader reader(ITEM_FILE);
    Inventory inventory = reader.getInventory();
    MapReader mapReader("LocationDistanceMap.txt");
    mapReader.readImage("MapImage.txt");
    Map map = mapReader.getMap();

    LocationReader locationReader("LocationDataDatabase.txt", map, inventory);
    GameInterface game(player, map, 0);
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
thêm bản đồ
khởi tạo các shop mặc định cho địa điểm đó
update LocationData thành shared_ptr
xoá cơ chế shared_ptr này, thay bằng truy cập trực tiếp vào map
khoá mua bán những món không có trong shop
tạo hệ thống giá cả cho các shop dựa trên mặt hàng
*/
/*--------------------------- TODO --------------------------------
điều chỉnh các hàm tăng giảm cung cầu,..
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
