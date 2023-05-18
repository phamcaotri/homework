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
void NLR(Tree t) {
    if (t) {
        cout << t->info << " ";
        NLR(t->left);
        NLR(t->right);
    }
}
//cout<< "\nKhong the xoay vi cay rong";

void XoayTrai(Tree& t) {
    if (t == NULL) {
        cout << "\nKhong the xoay vi cay rong";
        return;
    }
    if (t->right == NULL) {
        cout<< "\nKhong the xoay trai vi khong co nut con ben phai";
        return;
    }
    Node* nhanhTraimoi = t;
    t = t->right;
    nhanhTraimoi->right = t->left;
    t->left = nhanhTraimoi;
}
int main()
{
	Tree T = NULL;
	inputTree(T);
    cout << "NLR: "; NLR(T);
    XoayTrai(T);
    cout << "\nNLR: "; NLR(T); cout << endl;

	return 0;
}