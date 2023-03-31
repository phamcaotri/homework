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
    Node *new_node = new Node;
    // trường hợp cấp phát không thành công
    if (new_node == NULL) {
        cout << "Memory allocation failed";
        return NULL;
    }
    // trường hợp cấp phát thành công
    new_node->data = x;
    new_node->next = NULL;
    return new_node;
}

void addHead(List *l, int x) {
    Node *new_node = getNode(x);
    // trường hợp danh sách rỗng
    if (l->head == NULL) {
        l->head = l->tail = new_node;
    }
    else {
    // trường hợp danh sách không rỗng
        new_node->next = l->head;
        l->head = new_node;
    }
}

void addTail(List *l, int x) {
    Node *new_node = getNode(x);
    // trường hợp danh sách rỗng
    if (l->tail == NULL) {
        l->head = l->tail = new_node;
    }
    else {
    // trường hợp danh sách không rỗng
        l->tail->next = new_node;
        l->tail = new_node;
    }
}

void addAfter(List *l, Node *this_node, int x) {
    Node *new_node = getNode(x);
    // trường hợp danh sách rỗng
    if (this_node == NULL) {
        l->head = l->tail = new_node;
    }
    else {
    // trường hợp danh sách không rỗng
        new_node->next = this_node->next;
        this_node->next = new_node;
    // trường hợp thêm vào cuối danh sách
        if (this_node == l->tail) {
            l->tail = new_node;
        }
    }
}

void deleteHead(List *l) {
    // trường hợp danh sách rỗng
    if (l->head == NULL) {
        return;
    }
    // trường hợp danh sách có 1 phần tử
    else if (l->head == l->tail) {
        delete l->head;
        l->head = l->tail = NULL;
    }
    // trường hợp danh sách có nhiều hơn 1 phần tử
    else {
        Node *temp = l->head;
        l->head = l->head->next;
        delete temp;
    }
}




int main() {
    List l;
    int n; cin >> n;

}