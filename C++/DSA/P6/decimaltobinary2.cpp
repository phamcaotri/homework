/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

/*Cach 1: Khi da cai dat List roi, dinh nghia Stack dua tren List
struct Stack
{
	List L;
};

Cach 2: Cai dat lai Stack tu dau, giong nhu List
struct node
{
    int info;
    node *next;
};
struct Stack
{
    node *pHead; // pTail khong co cung duoc

};*/

//###INSERT CODE HERE -

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head = NULL;
    Node* tail = NULL;
};

Node* getNode(int x) {
    Node* new_node = new Node;
    new_node->data = x;
    new_node->next = NULL;
    return new_node;
}


void addHead(List &l, int x) {
    Node* new_node = getNode(x);
    // trường hợp danh sách rỗng
    if (l.head == NULL) {
        l.head = l.tail = new_node;
    }
    else {
    // trường hợp danh sách không rỗng
        new_node->next = l.head;
        l.head = new_node;
    }
}

void deleteHead(List &l) {
    // trường hợp danh sách rỗng
    if (l.head == NULL) {
        return;
    }
    else {
        Node* this_node = l.head;
        l.head = l.head->next;
        delete this_node;
    }
    // trường hợp danh sách có 1 phần tử
    if (l.head == NULL) {
        l.tail = NULL;
    }
}

struct Stack
{
	List L;
    int n;
};

void Init(Stack &S) {
    S.n = 0;
}

void Push(Stack &S, int x) {
    addHead(S.L, x);
    S.n++;
}

void Pop(Stack &S) {
    deleteHead(S.L);
    S.n --;
}

void DecimaltoBinary1(int n, Stack &S) {
    while (n > 0) {
        Push(S, n%2);
        n/=2;
    }
}

bool isEmpty(Stack S)
{
    if (S.n==0) 
        return true;
    return false;
}

int Top(Stack S)
{   if (isEmpty(S)) 
        return 0;
    return S.L.head->data;
}

void printStack(Stack S)
{   
    if (isEmpty(S)) 
        cout<<0;
    else
        while (not isEmpty(S)) {
            cout << Top(S);
            Pop(S);
        }
            
}

int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    DecimaltoBinary1(n,S);
    printStack(S);
    return 0;
}

