#include <iostream>
#include <vector>
using namespace std;

bool canDivide(vector<int>& pages, int k, int limit) {
    int numTapes = 1;
    int tapeSum = 0;
    for (int i = 0; i < pages.size(); i++) {
        if (pages[i] > limit) {
            return false;
        }
        if (tapeSum + pages[i] > limit) {
            numTapes++;
            tapeSum = 0;
        }
        tapeSum += pages[i];
    }
    return numTapes <= k;
}

int findMaxPages(vector<int>& pages, int k) {
    int total = 0;
    int maxPage = 0;
    for (int i = 0; i < pages.size(); i++) {
        total += pages[i];
        maxPage = max(maxPage, pages[i]);
    }
    int left = maxPage, right = total;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canDivide(pages, k, mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> pages(n);
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    int maxPages = findMaxPages(pages, k);
    cout << maxPages << endl;
    return 0;
}