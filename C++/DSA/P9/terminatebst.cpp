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
    Node* newNode = new Node;
    newNode->info = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool insert(Tree &t, int x) {
    if (t) {
        if (x == t->info) {
            cout<<"Bi trung gia tri, ket thuc qua trinh tao cay"<<endl;
            return 0;
        }
        if (x < t->info)
            return insert(t->left, x);
        if (x > t->info)
            return insert(t->right, x);
    } else {
        t = getNode(x);
    }
    return 1;
}

void inputTree(Tree &t) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (!insert(t, x))
            return;
    }
}

void NLR(Tree t) {
    if (t) {
        cout << t->info << ' ';
        NLR(t->left);
        NLR(t->right);
    }
}



int main()
{
	Tree T = NULL;
	inputTree(T); //Khi bi trung gia tri thi ket thuc qua trinh tao cay, khong nhap tiep nua
	cout<<"NLR: "; NLR(T);
	return 0;
}



