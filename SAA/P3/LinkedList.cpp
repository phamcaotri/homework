// basic cpp program to implement linked list
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


Node* getNode(int x) {
    Node *p = new Node;
    if (p == NULL) {
        cout << "Memory allocation failed";
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    return p;
}

// function to add a new node at the head
void addHead(List &l, int x) {
    // bước 1: tạo node mới
    Node *p = getNode(x);
    if (l.head == NULL) { //danh sách rỗng
        l.head = l.tail = p;
    }
    else {
        p->next = l.head;
        l.head = p;
    }
}
// function to add a new node at the tail
void addTail(List &l, int x) {
    // bước 1: tạo node mới
    Node *p = getNode(x);
    if (l.tail == NULL) { //danh sách rỗng
        l.head = l.tail = p;
    }
    else {
        l.tail->next = p;
        l.tail = p;
    }
}
// A linked list node


int main() {
    List l;
    int n; cin >> n;

}