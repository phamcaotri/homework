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


// một số hàm hỗ trợ khác

void deleteList(List &l) {
    while (l.head != NULL) {
        deleteHead(l);
    }
}

void addList(List &l1, List &l2) {
    l1.tail->next = l2.head;
    l1.tail = l2.tail;
}

// danh sách liên kết đôi

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

struct DList {
    DNode* head = NULL;
    DNode* tail = NULL;
};

DNode* getDNode(int x) {
    DNode* new_node = new DNode;
    new_node->data = x;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void addHead(DList &l, int x) {
    DNode* new_node = getDNode(x);
    // trường hợp danh sách rỗng
    if (l.head == NULL) {
        l.head = l.tail = new_node;
    }
    else {
        new_node->next = l.head;
        l.head->prev = new_node;
        l.head = new_node;
    }
}

void addTail(DList &l, int x) {
    DNode* new_node = getDNode(x);
    // trường hợp danh sách rỗng
    if (l.head == NULL) {
        l.head = l.tail = new_node;
    }
    else {
        new_node->prev = l.tail;
        l.tail->next = new_node;
        l.tail = new_node;
    }
}

void addAfterNode(DList &l, DNode* this_node, int x) {
    DNode* new_node = getDNode(x);
    // trường hợp danh sách rỗng
    if (l.head == NULL) {
        l.head = l.tail = new_node;
    }
    else {
        new_node->next = this_node->next;
        new_node->prev = this_node;
        this_node->next = new_node;
        // gắn node sau nút này vào node mới
        if (new_node->next != NULL) {
            new_node->next->prev = new_node;
        }
        if (this_node == l.tail) {
            l.tail = new_node;
        }
    }
}

void addBeforeNode(DList &l, DNode* this_node, int x) {
    DNode* new_node = getDNode(x);
    // trường hợp danh sách rỗng
    if (l.head == NULL) {
        l.head = l.tail = new_node;
    }
    else {
        new_node->next = this_node;
        new_node->prev = this_node->prev;
        this_node->prev = new_node;
        // gắn node trước nút này vào node mới
        if (new_node->prev != NULL) {
            new_node->prev->next = new_node;
        }
        if (this_node == l.head) {
            l.head = new_node;
        }
    }
}

void deleteHead(DList &l) {
    // trường hợp danh sách rỗng
    if (l.head == NULL) {
        return;
    }
    // trường hợp danh sách có 1 phần tử
    if (l.head == l.tail) {
        delete l.head;
        l.head = l.tail = NULL;
        return;
    }
    // trường hợp danh sách có nhiều hơn 1 phần tử
    DNode* this_node = l.head;
    l.head = l.head->next;
    l.head->prev = NULL;
    this_node->next = NULL;
    delete this_node;
}

void deleteTail(DList &l) {
    // trường hợp danh sách rỗng
    if (l.head == NULL) {
        return;
    }
    // trường hợp danh sách có 1 phần tử
    if (l.head == l.tail) {
        delete l.head;
        l.head = l.tail = NULL;
        return;
    }
    // trường hợp danh sách có nhiều hơn 1 phần tử
    DNode* this_node = l.tail;
    l.tail = l.tail->prev;
    l.tail->next = NULL;
    this_node->prev = NULL;
    delete this_node;
}

void deleteAfterNode(DList &l, DNode* this_node) {
    // trường hợp danh sách rỗng
    if (l.head == NULL) {
        return;
    }
    // trường hợp danh sách có 1 phần tử
    if (l.head == l.tail) {
        delete l.head;
        l.head = l.tail = NULL;
        return;
    }
    // trường hợp danh sách có nhiều hơn 1 phần tử
    DNode* node_after = this_node->next;
    this_node->next = node_after->next;
    if (node_after == l.tail) {
        l.tail = this_node;
    }
    else {
        node_after->next->prev = this_node;
    }
    node_after->next = NULL;
    node_after->prev = NULL;
    delete node_after;
}

void deleteBeforeNode(DList &l, DNode* this_node) {
    // trường hợp danh sách rỗng
    if (l.head == NULL) {
        return;
    }
    // trường hợp danh sách có 1 phần tử
    if (l.head == l.tail) {
        delete l.head;
        l.head = l.tail = NULL;
        return;
    }
    // trường hợp danh sách có nhiều hơn 1 phần tử
    DNode* node_before = this_node->prev;
    this_node->prev = node_before->prev;
    if (node_before == l.head) {
        l.head = this_node;
    }
    else {
        node_before->prev->next = this_node;
    }
    node_before->next = NULL;
    node_before->prev = NULL;
    delete node_before;
}

void deleteList(DList &l) {
    while (l.head != NULL) {
        deleteHead(l);
    }
}

void printList(DList l) {
    DNode* this_node = l.head;
    while (this_node != NULL) {
        cout << this_node->data << " ";
        this_node = this_node->next;
    }
    cout << endl;
}


