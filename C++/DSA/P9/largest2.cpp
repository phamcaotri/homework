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

void RNL(Tree t, int& n) {
    if (t) {
        RNL(t->right, n);
        n--;
        if (n == 0) {
            cout << "2nd largest value is " <<  t->info;
            return;
        }
        RNL(t->left, n);
    }
}

void secondLargest(Tree t) {
    
    int n = 2;
    RNL(t, n);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
    secondLargest(T);
	return 0;
}
