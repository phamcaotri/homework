/*Cho một tập N điểm (x,y) trên mặt phẳng Oxy. Bạn hãy sắp xếp và in ra các điểm tăng dần theo x, nếu x bằng nhau thì sắp xếp các điểm giảm dần theo y.

 Input: 

    Dòng đầu tiên chứa số nguyên N

,  (1≤N≤106)

là số lượng điểm trên mặt phẳng.

N dòng tiếp theo gồm 2 số nguyên x, y (−109≤x,y≤109)

    là toạ độ của các điểm trên mặt phẳng.

Output:   Các điểm đã được sắp xếp , mỗi điểm được in trên một hàng.*/

#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(int *a, int *b, int l, int r) {
    int i = l, j = r;
    int x = a[(l+r)/2];
    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            swap(b[i], b[j]);
            i++;
            j--;
        }
    }
    if (l < j) quickSort(a, b, l, j);
    if (i < r) quickSort(a, b, i, r);
}

int main() {
    cin.tie (NULL);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        b[i] = -b[i];
    }
    quickSort(a, b, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " << -b[i] << "\n";
    }

    return 0;
}