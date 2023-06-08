#include <bits/stdc++.h>
using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
};

typedef Node* Tree;

Node* getNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}

void insert(Tree& t, int x, int& position, int& step) {
    if (t) {
        if (x > t->info) {
            return insert(t->left, x, ++position, ++step);
        }
        else {
            return insert(t->right, x, --position, ++step);
        }
    }
    t = getNode(x);
}


int main() {
    Tree t = NULL;
    vector<tuple<int,int,int>> datalist;
    int n; cin >> n;
    int min = 0, max = 0;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        int position = 0;
        int step = 0;
        insert(t, x, position, step);
        datalist.push_back({position, step, x});
        if (position < min) {
            min = position;
        }
        if (position > max) {
            max = position;
        }
    }
    
    auto ByStepAndValue = [](const tuple<int,int,int>& a, const tuple<int,int,int>& b) {
        auto [position1, step1, x1] = a;
        auto [position2, step2, x2] = b;
        if (step1 == step2) {
            return x1 > x2;
        }
        return step1 < step2;
    };
    
    vector<int> resultlist;
    sort(datalist.begin(), datalist.end(), ByStepAndValue);
    for (int i = min; i <= max; i++) {
        for (auto j : datalist) {
            auto [position, step, x] = j;

            if (position == i) {
                resultlist.push_back(x);
                break;
            }
      }
    }

    sort(resultlist.begin(), resultlist.end());
    for (auto i : resultlist) {
        cout << i << ' ';
    }
    return 0;
}