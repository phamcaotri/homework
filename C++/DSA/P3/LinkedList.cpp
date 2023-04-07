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
    if (l->head == NULL)
        return;
    Node *this_node = l->head;
    l->head = l->head->next;
    this_node->next = NULL;
    delete this_node;
    // trường hợp danh sách có 1 phần tử
    if (l->head == NULL)
        l->tail == NULL;
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


void deleteAt(List *l, int x) {
    // trường hợp danh sách rỗng
    if (l->head == NULL)
        return;
    // trường hợp xoá đầu
    if (l->head->next == NULL) {
        deleteHead(l);
        return;
    }
    Node *this_node = l->head, *node_before = NULL;
    while (this_node != NULL) {
        if (this_node->data == x)
            break;
        node_before = this_node;
        this_node = this_node->next;
    }  
    node_before->next = this_node->next;
    this_node->next = NULL;
    // trường hợp xoá cuối
    if (this_node == l->tail)
        l->tail = node_before;
    delete this_node;
}

void printList(List* l) {
    Node* p = l->head;
    while (p != NULL) {
    cout << p->data << ' ';
    p = p->next;
    } 
    

}

int main() {
    List l;
    int n; cin >> n;

}