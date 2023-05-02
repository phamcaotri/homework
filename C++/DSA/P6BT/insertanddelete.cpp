/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


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
    if (l.head == NULL) {
        cout << "List is empty";
        return;
    }
    Node* this_node = l.head;
    while (this_node->next != NULL) {
        cout << this_node->data << ' ';
        this_node = this_node->next;
    }
    cout << this_node->data;
}


void deleteTail(List &l) {
    if (l.head == NULL) {
        return;
    }
    else {
        Node* this_node = l.head;
        while (this_node->next != l.tail) {
            this_node = this_node->next;
        }
        l.tail = this_node;
        delete l.tail->next;
        l.tail->next = NULL;
    }
    if (l.tail == NULL) {
        l.head = NULL;
    }
}

int main() {
    List l;
    int n = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        cin.ignore();
        cin.ignore();
        string op = "", pos = ""; int x = 0;
        getline(cin, op, ' ');
        getline(cin, pos, ' ');
        cin >> x;
        
        if (op == "+") {
            if (pos == "H") {
                addHead(l, x);
            }
            if (pos == "T") {
                addTail(l, x);
            }
    
        }
        if (op == "-") {
            if (pos == "H") {
                deleteHead(l);
            }
            if (pos == "T") {
                deleteTail(l);
            }
        }
    }
    outputList(l);
    return 0;
}