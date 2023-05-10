/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

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

int listSize(List &l) {
    int count = 0;
    Node* this_node = l.head;
    while (this_node != NULL) {
        count++;
        this_node = this_node->next;
    }
    return count;
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
    if (l.tail == NULL) {
        l.head = l.tail = new_node;
    }
    else {
    // trường hợp danh sách không rỗng
        l.tail->next = new_node;
        l.tail = new_node;
    }
}

Node* findFirstNodeEqual(List &l, int x) {
    Node *this_node = l.head;
    while (this_node != NULL) {
        if (this_node->data == x) {
            return this_node;
        }
        this_node = this_node->next;
    }
    return NULL;
}

Node* findNodeIth(List &l, int i) {
    // nếu đếm từ 1 thì sửa lại dòng này thành if (i < 1 or i > listSize(l))
    if (i < 0 or i >= listSize(l)) {
        // in ra lỗi
        return NULL;
    }
    Node* this_node = l.head;
    // đếm từ 0
    int count = 0;
    while (this_node != NULL) {
        if (count == i) {
            return this_node;
        }
        count++;
        this_node = this_node->next;
    }
    return NULL;
}

void addAfterNode(List &l, Node* this_node, int x) {
    Node* new_node = getNode(x);
    // trường hợp danh sách rỗng
    if (this_node == NULL) {
        l.head = l.tail = new_node;
    }
    else {
    // trường hợp danh sách không rỗng
        new_node->next = this_node->next;
        this_node->next = new_node;
        if (this_node == l.tail) {
            l.tail = new_node;
        }
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

void deleteFirstNodeEqual(List &l, int x) {
    // trường hợp danh sách rỗng
    if (l.head == NULL) {
        return;
    }
    // trường hợp xoá đầu danh sách
    if (l.head->data == x) {
        deleteHead(l);
        return;
    }
    // trường hợp danh sách có nhiều hơn 1 phần tử
    Node* this_node = l.head, *node_before = NULL;
    while (this_node != NULL) {
        if (this_node->data == x) {
            node_before->next = this_node->next;
            this_node->next = NULL;
            // trường hợp xoá cuối danh sách
            if (this_node == l.tail) {
                l.tail = node_before;
            }
            delete this_node;
            return; // thoát khỏi hàm
        }
        else {
            node_before = this_node;
            this_node = this_node->next;
        }
    }

}

void deleteAllNodeEqual(List &l, int x) {
    // trường hợp danh sách rỗng
    if (l.head == NULL) {
        return;
    }
    // trường hợp xoá đầu danh sách
    while (l.head != NULL && l.head->data == x) {
        deleteHead(l);
    }
    // trường hợp danh sách có nhiều hơn 1 phần tử
    Node* this_node = l.head, *node_before = NULL;
    while (this_node != NULL) {
        if (this_node->data == x) {
            node_before->next = this_node->next;
            this_node->next = NULL;
            // trường hợp xoá cuối danh sách
            if (this_node == l.tail) {
                l.tail = node_before;
            }
            delete this_node;
            this_node = node_before->next; // cập nhật lại this_node
        }
        else {
            node_before = this_node;
            this_node = this_node->next;
        }
    }
}

void inputList(List &l) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        addTail(l, x);
    }
}

void outputList(List &l) {
    Node* this_node = l.head;
    while (this_node != NULL) {
        cout << this_node->data << " ";
        this_node = this_node->next;
    }
    cout << endl;
}

Node* maxValueNode(List &l) {
    Node* this_node = l.head, *max_node = l.head;
    while (this_node != NULL) {
        if (this_node->data > max_node->data) {
            max_node = this_node;
        }
        this_node = this_node->next;
    }
    return max_node;
}

Node* minValueNode(List &l) {
    Node* this_node = l.head, *min_node = l.head;
    while (this_node != NULL) {
        if (this_node->data < min_node->data) {
            min_node = this_node;
        }
        this_node = this_node->next;
    }
    return min_node;
}