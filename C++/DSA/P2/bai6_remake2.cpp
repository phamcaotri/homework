
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void Sort(vector<long> &a, long max_value) {
    vector<long> b(max_value+1, 0);
    for (long i = 0; i < a.size(); i++) {
        b[a[i]] ++;
    }
    int j = 0;
    for (long i = 0; i < max_value+1; i++) {
        while (b[i] > 0) {
            a[j] = i;
            b[i] --;
            j++;
        }
    }
}
long binarysearch(vector<long> v, long b) {
    long l = 0, r = v.size() - 1;
    while (l <= r) {
        long mid = (l + r) / 2;
        if (v[mid] == b) return mid;
        if (v[mid] < b) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int main() {
    // khai báo vector v
    vector<long> v;
    unordered_map<long, long> m;
    long a, b, max_value = 0;
    int i = 0;
    do {
        cin >> a;
        if (a == 0) break;
        cin >> b;
        if (a == 1) {
            if (m.find(b) == m.end()) {
                m[b] = 1;
                v.push_back(b);
            }
            if (b > max_value) 
                max_value = b;
            
        }
        else {
            if (m.find(b) == m.end()) {
                cout << "0" << '\n';
            }
            else {
                Sort(v, max_value);
                cout << binarysearch(v, b) + 1 << '\n';

            }
        }

    } while(true);
    return 0;
}
