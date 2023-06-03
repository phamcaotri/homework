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

void insert(Tree& t, int x) {
    if (t) {
        if (t->info == x) 
            return;
        if (x < t->info)
            return insert(t->left, x);
        else
            return insert(t->right, x);
    }
    t = getNode(x);
}

void inputTree(Tree& t) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        insert(t, x);
    }
}

void LNR(Tree t) {
    if (t) {
        LNR(t->left);
        cout << t->info << ' ';
        LNR(t->right);
    }
}

int isFullBinaryTree(Tree t) {
    if (t) {
        if (t->left != NULL xor t->right != NULL)
            return 0;
        int full = isFullBinaryTree(t->left);
        if (!full)
            return 0;
        return isFullBinaryTree(t->right);
    } else {
        return 1;
    }
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T);
	int i=isFullBinaryTree (T);
	if(i==0) cout<<"\nThe tree is not a Full Binary Tree";
    else cout<<"\nThe tree is a Full Binary Tree";
	return 0;
}

