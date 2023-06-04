/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
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

void RNL(Tree t, int x, bool &flag) {
    if (t) {
        RNL(t->right, x, flag);
        if (t->info <= x and !flag) {
            cout << t->info;
            flag = true;
            return;
        }
        RNL(t->left, x, flag);
    }
}

void floor(Tree t) {
    int x; cin >> x;
    bool flag = false;
    RNL(t, x, flag);
    if (!flag)
        cout << 201;
}

int main() {
    Tree t = NULL;
    inputTree(t);
    bool flag = false;
    floor(t);


    return 0;
}