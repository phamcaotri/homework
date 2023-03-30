#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head = NULL;
    Node* tail = NULL;
};

Node* addNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void addHead(List* l, int x) {
    Node* p = addNode(x);
    if (l->head == NULL) {
        l->head = l->tail = p;
    }
    else {
        p->next = l->head;
        l->head = p;
    }
}

void addTail(List* l, int x) {
    Node* p = addNode(x);
    if (l->tail == NULL) {
        l->head = l->tail = p;
    }
    else {
        l->tail->next = p;
        l->tail = p;
    }
}

void printList(List* l) {
    Node* p = l->head;
    while (p != NULL) {
        cout << p->data << ' ';
        p = p->next;
    }
    

}

int main() {
    List* l = new List;
    int a, b;
    while (true) {
        cin >> a;
        if (a == 3) break;
        cin >> b;
        if (a == 0) {
            addHead(l,b);
        } else {
            addTail(l,b);
        }


    }
    printList(l);
    
}