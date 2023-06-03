#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>

using namespace std;

struct ImageTree {
    deque<int> image;
    vector<int> list;
    vector<int> result;
    void input() {
        int n;
        cin >> n;
        int max = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x > max) {
                max = x;
                list.resize(max + 1);
                result.resize(max + 1);
            }
            list[x] = i;
            insert(x);
        }
    }

    void insert(int x) {
        if (image.empty()) {
            image.push_back(x);
            result[x] ++;
            return;
        }
        if (x <= image.front()) {
            image.push_front(x);
            result[x] ++;
            return;
        }
        if (x > image.back()) {
            image.push_back(x);
            result[x] ++;
            return;
        }
        // for (int i = 0; i < image.size(); i++) {
        //     if (x <= image[i]) {
        //         if (list[image[i]] > list[image[i - 1]]) {
        //             image.at(i - 1) = x;
        //             return;
        //         } else {
        //             image.at(i) = x;
        //             return;
        //         }
        //     }
        // }
        int index = -1;
        binarySearch(x, 0, image.size() - 1, index);
        if (list[image[index]] > list[image[index - 1]]) {
            image[index - 1] = x;
        } else {
            image[index] = x;
        }
    }

    void binarySearch(int x, int left, int right, int& index) {
        if (left > right) {
            return;
        }
        int mid = (left + right) / 2;
        if ( x <= image[mid]) {
            index = mid;
            return binarySearch(x, left, mid - 1, index);
        } else {
            return binarySearch(x, mid + 1, right, index);
        }
    }

    void output() {
        for (int i = 0; i < result.size(); i++) {
            while (result[i] > 0) {
                cout << i << " ";
                result[i]--;
            }
        }
    }

};

int main() {
    ImageTree tree;
    tree.input();
    tree.output();
    return 0;
}