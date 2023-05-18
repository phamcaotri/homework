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
    if (q->right) {
        replace(q->right, p);
    } else {
        p->info = q->info;
        p = q;
        q = q->left;
    }
}
void deleteNode(Tree& t, int x) {
    if (t == NULL) {
        cout << "Not found";
        return;
    }
    if (x < t->info) {
        deleteNode(t->left, x);
    } else if (x > t->info) {
        deleteNode(t->right, x);
    } else {
        cout<<"\nDo you want to delete "<<x<< "?(y/n):";
        char c; cin>>c;
        if (c=='n' or c == 'N') return;
        Node* p = t;
        if (t->left == NULL) {
            t = t->right;
        } else if (t->right == NULL) {
            t = t->left;
        } else {
            replace(t->left, p);
        }
        delete p;
    }
}


int main()
{
    Tree T = NULL;
    inputTree(T);
    cout<<"NLR: "; NLR(T);
    int x; cout<<"\nEnter the element you want to delete: ";cin>>x;
    deleteNode(T,x);
    cout<<"\nNLR: "; NLR(T);

    return 0;
}
