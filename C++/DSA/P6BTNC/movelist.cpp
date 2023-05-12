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

// struct pairNode
// {
//     Node* left;
//     Node* right;
// };

// pairNode findFirstNodeEqual(List l, int x) {
//     Node* this_node = l.head;
//     Node* before_node = NULL;
//     while (this_node != NULL) {
//         if (this_node->data == x) {
//             return {before_node, this_node};
//         }
//         before_node = this_node;
//         this_node = this_node->next;
//     }
//     return {NULL, NULL};
// }

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

Node* findNodeIth(List l, int i) {
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


void inputList(List &l) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        addTail(l, x);
    }
}

void outputList(List l) {
    Node* this_node = l.head;
    while (this_node != NULL) {
        cout << this_node->data << " ";
        this_node = this_node->next;
    }
    cout << endl;
}

// void cutToHead(List &l, int a) {
//     auto [left, right] = findFirstNodeEqual(l, a);
//     if (right == NULL or left == NULL) return;
//     left->next = right->next;
//     right->next = l.head;
//     l.head = right;
// }

// void cutToTail(List &l, int a) {
//     auto [left, right] = findFirstNodeEqual(l, a);
//     if (right == NULL) return;
//     if (left == NULL) {
//         l.head = l.head->next;
//         right->next == NULL;
//         l.tail->next = right;
//         l.tail = right;
//     }
//     left->next = right->next;
//     right->next = NULL;
//     l.tail->next = right;
//     l.tail = right;
// }

// void cutToNode(List &l, int a, int b) {
//     auto [left, right] = findFirstNodeEqual(l, a);
//     if (right == NULL) {
//         cutToHead(l, b);
//         return;
//     }
//     Node* new_node = getNode(b);
//     new_node->next = right->next;
//     if (left != NULL) {
//         left->next = new_node;
//     }

// }

void moveHeadToTail(List &l, int k) {
    for (int i = 0; i < k; i++) {
        Node* temp = l.head;
        l.head = l.head->next;
        temp->next = NULL;
        l.tail->next = temp;
        l.tail = temp;
    }
}

int main() {
    List l;
    bool check = true;
    while (check) {
        int x; cin >> x;
        int a;
        switch (x)
        {
        case 0:
            {cin >> a;
            addHead(l, a);
            break;}
        case 1:
            {cin >> a;
            addTail(l, a);
            break;}
        case 2:
            {int b; cin >> a >> b;
            Node* this_node = findFirstNodeEqual(l, a);
            if (this_node == NULL) {
                addHead(l, b);
            } else {
                addAfterNode(l, this_node, b);
            }
            break;}
        case 3:
            {int k; cin >> k;
            moveHeadToTail(l, k);
            break;}
        default:
        check = false;
            break;
        }
    }

    outputList(l);
    return 0;
}