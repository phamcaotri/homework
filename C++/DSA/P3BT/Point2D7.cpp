#include <iostream>
#include <vector>
using namespace std;

void merge(vector<pair<int, int>> &a, int start, int pivot, int end) {
    vector<pair<int, int>> b(end-start+1);
    int i = start, j = pivot +1, k = 0;
    while (i <= pivot and j <= end) { // gộp 2 nửa lại
        if (a[i] < a[j]) {
            b[k] = a[i];
            k++;
            i++;
        }
        else {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    for (i;i <= pivot; i++) { // nếu nửa trái còn phần tử, thì gộp vào
        b[k] = a[i];
        k++;
    }
    for (j;j <= end; j++) { // nếu nửa phải còn phần tử, thì gộp vào
        b[k] = a[j];
        k++;
    }
    k = 0;
    for (i = start; i <= end; i++) { // gán lại mảng a
        a[i] = b[k];
        k++;
    } 
}

void Sort(vector<pair<int, int>> &v, int start, int end) {
    int pivot = (start + end)/2; // tìm trục
    if (start < pivot) Sort(v, start,pivot); // sắp xếp nửa trái
    if (end > pivot +1 ) Sort(v, pivot+1,end); // sắp xếp nửa phải
    merge(v, start,pivot,end); // gộp 2 nửa lại
}
int main() {
    int n; cin >> n;
    vector<pair<int, int>> v;
    int x, y;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        v.push_back({x, -y});
    }
    Sort(v, 0, n-1);
    for (auto i = v.begin(); i != v.end(); i++) {
        cout << i->first << " " << -i->second << '\n';
    }

    return 0;
}