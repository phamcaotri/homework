
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int binarysearch(vector<int> v, int b) {
    int l = 0, r = v.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid] == b) return mid;
        if (v[mid] < b) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

void Sort(vector<int> &a, int left, int right, int pivot) {
    int mid = a[pivot];
    int i = left, j = right;
    while (i <= j) {
        while (a[i] < mid) {
            i ++;
        }

        while (a[j] > mid) {
            j --;  
        }

        if (i <= j) {
            swap(a[i], a[j]);
            i ++; 
            j --;
        }
    }
    if (left < j) Sort(a, left,j,(left+j)/2);
    if (right > i) Sort(a, i,right, (i+right)/2);
}

int main() {
    vector<int> v(10000000);
    int a, b;
    //string buffer;
    do {
        cin >> a;
        if (a == 0) break;
        cin >> b;
        if (a == 1) {
            if (m.find(b) == m.end()) {
                v.push_back(b)
                //Sort(v, 0, v.size()-1, v.size()-1);
                m[b] = 1;
            }
        }
        else {
            if (m.find(b) == m.end()) {
                cout << "0" << '\n';
                //buffer += "0" + '\n';
            }
            else {
                cout << binarysearch(v, b) + 1 << '\n';
                //buffer += to_string(binarysearch(v, b) + 1) + '\n';
            }
        }
            
    } while(true);
    //cout << buffer;
    return 0;
}
