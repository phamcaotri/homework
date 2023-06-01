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
bool isSquare (int n);
void SearchStandFor(Node* &p, Node* &q); //Chon node phai nhat tren nhanh con ben trai
void deleteSquareNumbers(Tree &T);

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout<<"\nNLR: "; NLR(T);
    cout<<"\nDelete all square numbers:";
    deleteSquareNumbers(T);
    cout<<"\nNLR: "; NLR(T);

    return 0;
}
//###INSERT CODE HERE -
Node *getNode(int x) {
    Node* newNode = new Node;
    newNode->info = x;
    newNode->pLeft = newNode->pRight = NULL;
    return newNode;
}

void insertNode(Tree & t, int x) {
    if (t) {
        if (x == t->info)
            return;
        if (x < t->info)
            insertNode(t->pLeft,x);
        if (x > t->info)    
            insertNode(t->pRight, x);
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


bool isSquare (int n) {
    if (n == 1) return true;
    for (int i = 0; i < n; i++) {
        if (i*i == n)
            return true;
    }
    return false;
}
void SearchStandFor(Node* &leftBranch, Node* &nodeToDelete) {
    if (leftBranch->pRight) {
        SearchStandFor(leftBranch->pRight, nodeToDelete);

    } else {
        nodeToDelete->info = leftBranch->info;
        nodeToDelete = leftBranch;
        leftBranch = leftBranch->pLeft;
    }
}
void deleteSquareNumbers(Tree &t) {
    if (t) {
        if (isSquare(t->info)) {
            Node* nodeToDelete = t;
            if (t->pRight == NULL) {
                t = t->pLeft;
            } else if (t->pLeft == NULL) {
                t = t->pRight;
            } else {
                SearchStandFor(t->pLeft, nodeToDelete);
            }
            delete nodeToDelete;
            deleteSquareNumbers(t);
        } else {
            deleteSquareNumbers(t->pLeft);
            deleteSquareNumbers(t->pRight);
        }
    }
}
