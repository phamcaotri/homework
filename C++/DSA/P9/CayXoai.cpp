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
        if (x <= t->info)
            return insert(t->right, x, --position, ++step);
    }
    t = getNode(x);
}

void insert2(Tree& t, int x, int& position, int& step) {
    Node* p = getNode(x);
    Node* current = t;
    Node* parent = NULL;
    while (current) {
        parent = current;
        if (x > current->info) {
            current = current->left;
            position++;
            step++;
        } else {
            current = current->right;
            position--;
            step++;
        }
    }
    if (!parent) {
        t = p;
    } else {
        if (x > parent->info) {
            parent->left = p;
        } else {
            parent->right = p;
        }
    }
}




int main() {
    Tree t = NULL;
    vector<tuple<int,int,int>> list_position_step_x;
    
    int n;
    cin >> n;
    int x;
    int min = 0, max = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        int position = 0;
        int step = 0;
        insert2(t, x, position, step);
        list_position_step_x.push_back({position, step, x});
        if (position < min) {
            min = position;
        }
        if (position > max) {
            max = position;
        }
    }
    vector<int> listResult;
    auto sortByStep = [](const tuple<int,int,int>& a, const tuple<int,int,int>& b) {
        return get<1>(a) < get<1>(b);
    };
    sort(list_position_step_x.begin(), list_position_step_x.end(), sortByStep);
    for (int i = min; i <= max; i++) {
        for (int j = 0; j < list_position_step_x.size(); j++) {
            if (get<0>(list_position_step_x[j]) == i) {
                listResult.push_back(get<2>(list_position_step_x[j]));
                break;
            }
        }
    }
    sort(listResult.begin(), listResult.end());
    for (auto i : listResult) {
        cout << i << ' ';
    }

    return 0;
}