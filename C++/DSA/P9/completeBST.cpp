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

int checkComplete(Tree t, int rank) {
    if (t) {
        if (t->left == NULL and t->right == NULL) {
            if (rank != 1)
                return 0;
        }
        --rank;
        int complete = checkComplete(t->left, rank);
        if (!complete)
            return 0;
        return checkComplete(t->right, rank);
    } else {

        return 1;
    }
}

int isCompleteBinaryTree(Tree t) {
    if (!isFullBinaryTree(t))
        return 0;
    Node* p = t;
    int rank = 0;
    while (p) {
        p = p->left;
        rank ++;
    }
    return checkComplete(t, rank);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T);
	int i=isCompleteBinaryTree (T);
	if(i==0) cout<<"\nThe tree is not a Complete Binary Tree";
    else cout<<"\nThe tree is a Complete Binary Tree";
	return 0;
}


