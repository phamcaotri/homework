#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> hs(n + 1, 0); 
    // bước 1: khởi tạo học sinh cuối cùng và rank.
    // rank dùng để xác định thứ tự của học sinh đó
    int hs_cuoi_cung = n;
    int rank = 0;
    for (int i = 0; i < m; i++) {
        // bước 2: khi không có sự thay đổi về vị trí cuối cùng,
        // tăng rank lên 1 đơn vị và in vị trí cuối cùng hiện tại
        int x;
        cin >> x;
        rank += 1;
        hs[x] = rank;
        if (hs_cuoi_cung == x) {
            // bước 3: khi có sự thay đổi về vị trí cuối cùng,
            // trừ rank tất cả học sinh cho học sinh có rank nhỏ nhất
            // ta tìm được một học sinh có rank = 0
            // đó là học sinh cuối cùng kế tiếp
            int min = *min_element(hs.begin() + 1, hs.end());
            int temp_x = x;
            bool flag = false;
            do {
                x --;
                if (x == 0) {
                    x = n;
                }
                if (hs[x] == min and flag == false) {
                    hs_cuoi_cung = x;
                    flag = true;
                }
                hs[x] -= min;

            } while (hs[x] != hs[temp_x]);
        }
        cout << hs_cuoi_cung << ' ';
    }

    return 0;

};