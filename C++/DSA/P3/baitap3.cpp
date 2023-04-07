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

Node* findX(List* l, int x) {
    Node* p = l->head;
    while (p != NULL) {
        if (p->data == x) {
            return p;
        }
    p = p->next;
    }
    return NULL;     
}

void addAt(List* l, int x, Node* index) {
    Node* p = addNode(x);
    if (index == NULL) {
        l->head = l->tail = NULL;
    }
    p->next = index->next;
    index->next = p;
    if (p->next == NULL) {
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
    int a, b, c;
    while (true) {
        cin >> a;
        if (a == 3) break;
        cin >> b;
        if (a == 0) {
            addHead(l,b);
        } else if (a == 1) {
            addTail(l,b);
        } else {
            cin >> c;
            if (findX(l,b) == NULL) {
                addHead(l,c);
            } else {
                addAt(l,c,findX(l,b));
            }
        }


    }
    printList(l);
    
}
