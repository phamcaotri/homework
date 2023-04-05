/*
Sửa hàng rào
input:
n
a[1] a[2] ... a[n]
m
b[1] b[2] ... b[m]
output:
h k
x[1] y[1]
x[2] y[2]
...
x[k] y[k]
Bài toán:
hàng rào được tạo bởi n tấm gỗ, mỗi tấm dài a[i]
có m tấm gỗ thừa, mỗi tấm dài b[j]
khi thêm vào hàng rào, hàng rào sẽ tăng chiều dài thêm a[i] += b[j] và chỉ được thêm 1 lần
có thể cho j++ để chọn b[j] khác, nhưng không được chọn lại b[j] đã chọn trước đó
tìm h: chiều dài hàng rào lớn nhất thoả mãn a[i] + b[j] <= h với mọi i, j
tìm k: số lần thêm tấm gỗ thừa vào hàng rào
và x[k]: tấm gỗ a[i] được thêm vào hàng rào
y[k]: tấm gỗ b[j] thêm vào hàng rào

giải quyết bài toán bằng giải thuật tìm kiếm nhị phân và giải thuật tham lam
1. tìm min(h) sao cho min(h) >= min(min(a), min(b))
2. tìm max(h) sao cho max(h) <= max(a) + max(b)
3. dùng binary search để tìm h trong đoạn từ min(h) đến max(h)
4. kiểm tra h có phải là h lớn nhất thoả mãn yêu cầu không bằng giải thuật tham lam:
    step 1: chạy i từ 1 đến n, j từ 1 đến m
    step 2: nếu a[i] + b[j] < h thì tăng j lên 1 đơn vị đến khi a[i] + b[j] >= h.
        nếu không tìm được a[i] + b[j] >= h thì trả về false
    step 3: nếu a[i] + b[j] >= h thì gán x[k] = a[i], y[k] = b[j], k++, i++, j++
    step 4: lặp lại step 2 và step 3 cho đến khi j > m, nếu vậy kiểm tra xem a[i] >= h không
        nếu a[i] >= h thì trả về true,
        nếu không thì trả về false
    step 5: trả về k
5. nếu h đúng là h lớn nhất, kiểm tra tiếp trên đoạn từ h+1 đến right
        nếu không tìm thấy h lớn hơn h thỏa mãn yêu cầu thì in ra h và k
6. nếu h không phải là h lớn nhất, kiểm tra tiếp trên đoạn từ min(h) đến h-1

chương trình có sử dụng hàm Search() để binary search, hàm isPossible() để kiểm tra h có phải là h lớn nhất thoả mãn yêu cầu không

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int> a, vector<int> b, int h, int n, int m, int &k, vector<pair<int,int>> &c) {
    int i = 1, j = 1;
    k = 0;
    bool flag = true;
    while (i <= n and j <= m) {
        if (a[i]  >= h and flag) {
            i++;
            continue;
        }
        if (a[i] + b[j] < h) {
            j++;
            flag = false;
        }
        else {
            c[k] = make_pair(i,j);
            k++;
            i++;
            j++;
            flag = true;
        }
    }
    if (i <= n) {
        for (; i <= n; i++) {
            if (a[i] < h) {
                return false;
            }
        }

    } 
    return true;

}

void Search(vector<int> a, vector<int> b, int left, int right, int n, int m, int &h, int &k, vector<pair<int,int>> &c) {
    int prev_h = -1, prev_k = -1;
    vector<pair<int,int>> prev_c;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (isPossible(a, b, mid, n, m, k, c)) {
            prev_h = mid;
            prev_k = k;
            prev_c = c;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    h = prev_h;
    k = prev_k;
    c = prev_c;
}



int main() {
    int n, m;
    int max_a, min_a, max_b, min_b;
    cin >> n;
    vector<int> a(n + 1); // làm biếng shift sang phải 1 đơn vị
    cin >> a[1];
    max_a = a[1]; min_a = a[1];
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        if (a[i] > max_a) {
            max_a = a[i];
        }
        if (a[i] < min_a) {
            min_a = a[i];
        }
    }
    cin >> m;
    vector<int> b(m + 1); // làm biếng shift sang phải 1 đơn vị
    cin >> b[1];
    max_b = b[1]; min_b = b[1];
    for (int i = 2; i <= m; i++) {
        cin >> b[i];
        if (b[i] > max_b) {
            max_b = b[i];
        }
        if (b[i] < min_b) {
            min_b = b[i];
        }
    }
    vector<pair<int,int>> c(n); // c[i] = (x[i], y[i])
    int left = min(min_a, min_b);
    int right = max_a + max_b;
    int h = 0;
    int k = 0;
    Search(a, b, left, right, n, m, h, k, c);
    cout << h << " " << k << '\n';
    for (int i = 0; i < k; i++) {
        cout << c[i].first << " " << c[i].second << '\n';
    }

    return 0;
}

