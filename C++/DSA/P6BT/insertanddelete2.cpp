/*
Trên cùng một danh sách L rỗng ban đầu, liên tiếp thực hiện các thao tác được định nghĩa bởi chuỗi các thao tác như sau:

- Dòng đầu tiên là số nguyên n (0 < 0 < 10000000) là số lượng thao tác

- n dòng tiếp theo, mỗi dòng định nghĩa cho thao tác thứ i, mỗi dòng là tổ hợp của 3 yếu tố, và có format như sau: x y z

x: có giá trị '+' hoặc '-'. Trong đó, '+': thêm phần tử; '-': xóa phần tử.

y: có giá trị 'H' hoặc 'T'. Trong đó, 'H': đầu danh sách; 'T': cuối danh sách.

z: có giá trị là một số nguyên. Trong trường hợp x = '-', ta không cần quan tâm giá trị của z (z thường chỉ là một số 0). Trong trường hợp x = '+', z là giá trị sử dụng để chèn vào danh sách.

Ví dụ:

+ H 123 // chèn 123 vào đầu danh sách.

+ T -21 // chèn -21 vào cuối danh sách.

- H 0 // xóa phần tử đầu tiên khỏi danh sách.

- T 0 // xóa phần tử cuối cùng ra khỏi danh sách.

Sau khi thực hiện đầy đủ n thao thác, chương trình xuất trạng thái hiện tại của L trên cùng một dòng, mỗi phần tử cách nhau bởi một khoảng trắng và không được có khoảng trắng thừa.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
};

Node* getNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void initList(List &l) {
    l.head = l.tail = NULL;
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

void addTail(List &l, int x) {
    Node* new_node = getNode(x);
    // trường hợp danh sách rỗng
    if (l.head == NULL) {
        l.head = l.tail = new_node;
    }
    else {
    // trường hợp danh sách không rỗng
        l.tail->next = new_node;
        l.tail = new_node;
    }
}

void deleteHead(List &l) {
    // trường hợp danh sách rỗng
    if (l.head == NULL)
        return;
    Node* this_node = l.head;
    l.head = l.head->next;
    this_node->next = NULL;
    delete this_node;
    // trường hợp danh sách có 1 phần tử
    if (l.head == NULL)
        l.tail = NULL;
}

void deleteTail(List &l) {
    // trường hợp danh sách rỗng
    if (l.head == NULL)
        return;
    // trường hợp danh sách có 1 phần tử
    if (l.head == l.tail) {
        deleteHead(l);
        return;
    }
    // trường hợp danh sách có nhiều phần tử
    Node* this_node = l.head;
    while (this_node->next != l.tail) {
        this_node = this_node->next;
    }
    this_node->next = NULL;
    delete l.tail;
    l.tail = this_node;
}

void output(List l) {
    Node* this_node = l.head;
    while (this_node->next != NULL) {
        cout << this_node->data << " ";
        this_node = this_node->next;
    }
    cout << this_node->data;
}

int main() {
    int n; cin >> n;
    List l; initList(l);
    for (int i = 0; i < n; i++) {
        char x; cin >> x;
        if (x == '+') {
            char y; cin >> y;
            int z; cin >> z;
            if (y == 'H') {
                addHead(l, z);
            }
            else {
                addTail(l, z);
            }
        }
        else {
            char y; cin >> y;
            int z; cin >> z;
            if (y == 'H') {
                deleteHead(l);
            }
            else {
                deleteTail(l);
            }
        }
    }   
    output(l);
    return 0;
}