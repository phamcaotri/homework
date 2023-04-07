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


int main() {
    int a;
    List l;
    while (cin >> a) {
        

        if (a == 0) {
            int x;
            cin >> x;
            addHead(l, x);

        } else
        if (a == 1) {
            int x;
            cin >> x;
            addTail(l, x);
            continue;
        } else
        if (a == 2) {
            int c, b;
            cin >> c >> b;
            Node *this_node = findFirstNodeEqual(l, c);
            if (this_node == NULL) {
                addHead(l, b);
                continue;
            }
            addAfterNode(l, this_node, b);
            continue;
        } else
        if (a == 3) {
            int n;
            cin >> n;
            deleteFirstNodeEqual(l, n);
            continue;
        } else
        if (a == 5) {
            deleteHead(l);
            continue;

        } else
        if (a == 6) {
            break;
        }
            
    //printList(l);   
    }
    if (l.head == NULL) {
        cout << "blank";
    } else
        outputList(l);
    return 0;
}