/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *pLeft;
    Node *pRight;
};
typedef struct Node* Tree;
Node *getNode(int x);
void insertNode(Tree & T, int x);
void inputTree(Tree &T);
void NLR(Tree T);
int nodesWithLevel(Tree T, int k, int c);

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout<<"\nNLR: "; NLR(T);
    int k; cout<<"\nEnter k: "; cin >>k;
    cout<<nodesWithLevel(T,k,0); //neu tham so thu 3 khong can dung thi trong ham khong can xu ly

    return 0;
}
//###INSERT CODE HERE -

Node* getNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->pLeft = p->pRight = NULL;
    return p;

}

void insertNode(Tree& t, int x) {
    if (t) {
        if (t->info == x) 
            return;
        if (x < t->info)
            return insertNode(t->pLeft, x);
        else
            return insertNode(t->pRight, x);
    }
    t = getNode(x);
}

void inputTree(Tree& t) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        insertNode(t, x);
    }
}

void NLR(Tree t) {
    if (t) {
        cout << t->info << ' ';
        NLR(t->pLeft);
        NLR(t->pRight);
    }
}

void printNode(Tree t, int k, int& num) {
    if (t) {
        if (k == 0) {
            cout << t->info << ' ';
            num ++;
        }
        --k;
        printNode(t->pRight, k, num);
        printNode(t->pLeft, k, num);
    } else {
        return;
    }
}

int nodesWithLevel(Tree t, int k, int x) {

    cout << "\nList of nodes with level " << k << " (R->L): ";
    int num = 0;
    printNode(t, k, num);
    cout << "\nNumber of nodes with level " << k << ": ";
    return num;


}