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

void NLR(Tree t) {
    if (t) {
        cout << t->info << " ";
        NLR(t->left);
        NLR(t->right);
    }
}

void replace(Node*& q, Node*& p) {
    if (q->left) {
        replace(q->left, p);
    } else {
        p->info = q->info;
        p = q;
        q = q->right;
    }
}
void deleteNode(Tree& t, int x) {
    if (t == NULL) {
        return;
    }
    if (x < t->info) {
        deleteNode(t->left, x);
    } else if (x > t->info) {
        deleteNode(t->right, x);
    } else {
        Node* p = t;
        if (t->left == NULL) {
            t = t->right;
        } else if (t->right == NULL) {
            t = t->left;
        } else {
            replace(t->right, p);
        }
        delete p;
    }
}

void deleteRoot(Tree& t, int m) {
    for (int i = 0; i < m; i++) {
        if (t == NULL) {
            return;
        }
        Node* p = t;
        if (t->left == NULL) {
            t = t->right;
        } else if (t->right == NULL) {
            t = t->left;
        } else {
            replace(t->right, p);
        }
        delete p;
    }

}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
	int m; cout<<"\nEnter m: ";cin>>m;
	deleteRoot(T,m);
	cout<<"\nNLR: "; NLR(T);

	return 0;
}
