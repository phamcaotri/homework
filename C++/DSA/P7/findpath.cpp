#include <iostream>
#include <vector>
using namespace std;

//###INSERT CODE HERE -

struct Node {
    int info;
    Node* left, *right;
};

typedef Node* Tree;


Node* getNode(int x) {
    Node* new_node = new Node;
    new_node->info = x;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void insert(Tree &t, int x) {
    if (t) {
        if (x == t->info)
            return;
        if (x < t->info)
            insert(t->left,x);
        if (x > t->info)    
            insert(t->right, x);
    } else {
        t = getNode(x);
    }

}

void inputTree(Tree &t) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(t, x);
    }
}

void LNR(Tree t) {
    if (t) {
        LNR(t->left);
        cout << t->info << " ";
        LNR(t->right);
    }
}

void Search(Tree t, int x, vector<int>& path) {
    if (t) {
        if (x == t->info) {
            path.push_back(t->info);
            return;
        }
        if (x < t->info) {
            path.push_back(t->info);
            return Search(t->left, x, path);
        }
        if (x > t->info) {
            path.push_back(t->info);
            return Search(t->right, x, path);
        }
    }
    path = {};
    return;
    
}

int main() {
    Tree t = NULL;
    inputTree(t);
    int x;
    cin >> x;
    vector<int> path;
    Search(t, x, path);
    if (path.size() > 0) {
        cout << "Found. Path: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
    } else {
        cout << "Not found";
    }
    return 0;
}