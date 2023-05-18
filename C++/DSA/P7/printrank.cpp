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

void LNR(Tree t) {
    if (t) {
        LNR(t->left);
        cout << t->info << " ";
        LNR(t->right);
    }
}



void nodesWithLevel(Tree t, int k) {
    if (!t) return;
    if (k == 0) cout << t->info << " ";
    else {
        nodesWithLevel(t->right, k-1);
        nodesWithLevel(t->left, k-1);
    }
}

int main()
{
	Tree T = NULL;
	inputTree(T);
    int k; cout<<"Enter k: "; cin >>k;
    cout<<"\nList of nodes with level "<<k<<" (R->L) : ";
    nodesWithLevel(T, k);

	return 0;
}
