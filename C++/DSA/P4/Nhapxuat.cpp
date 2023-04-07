
#include <iostream>
#include <cstring>
#include <string>
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

void addHead(List &l, int x) {
    Node *new_node = getNode(x);
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
    Node *new_node = getNode(x);
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

void addAfter(List &l, Node *this_node, int x) {
    Node *new_node = getNode(x);
    // trường hợp danh sách rỗng
    if (this_node == NULL) {
        l.head = l.tail = new_node;
    }
    else {
    // trường hợp danh sách không rỗng
        new_node->next = this_node->next;
        this_node->next = new_node;
    // trường hợp thêm vào cuối danh sách
        if (this_node == l.tail) {
            l.tail = new_node;
        }
    }
}


void deleteHead(List &l) {
    // trường hợp danh sách rỗng
    if (l.head == NULL)
        return;
    Node *this_node = l.head;
    l.head = l.head->next;
    this_node->next = NULL;
    delete this_node;
    // trường hợp danh sách có 1 phần tử
    if (l.head == NULL)
        l.tail == NULL;
}

Node* findX(List &l, int x) {
    Node* p = l.head;
    while (p != NULL) {
        if (p->data == x) {
            return p;
        }
    p = p->next;
    }
    return NULL;     
}


void deleteAt(List &l, int x) {
    // trường hợp danh sách rỗng
    if (l.head == NULL)
        return;
    // trường hợp xoá đầu
    if (l.head->next == NULL) {
        deleteHead(l);
        return;
    }
    Node *this_node = l.head, *node_before = NULL;
    while (this_node != NULL) {
        if (this_node->data == x)
            break;
        node_before = this_node;
        this_node = this_node->next;
    }  
    node_before->next = this_node->next;
    this_node->next = NULL;
    // trường hợp xoá cuối
    if (this_node == l.tail)
        l.tail = node_before;
    delete this_node;
}

void printList(List &l) {
    Node* p = l.head;
    while (p != NULL) {
    cout << p->data << ' ';
    p = p->next;
    } 
    

}

void Init(List &L) {
    L.head = NULL;
    L.tail = NULL;
}

void inputList(List &L, int n) {
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        addTail(L, x);
    }
}

void outputList(List L) {
    if (L.head == NULL) {
        cout << "List is empty";
    }
    else {
        Node *p = L.head;
        while (p != NULL) {
            cout << p->data << ' ';
            p = p->next;
        }
    }
}

void outputGreaterThan(List L, int m) {
    bool check = false;
    if (L.head == NULL) {
        cout << "List is empty";
    }
    else {
        Node *p = L.head;
        while (p != NULL) {
            if (p->data > m) {
                cout << p->data << ' ';
                check = true;
            }
            p = p->next;
        }
        if (check == false) {
            cout << "None";
        }
    }

}

int main()
{
    List L; // Khai bao 1 danh sach
    Init(L); // Khoi tao danh sach
    int n; cout<<"Enter a number: "; cin>>n; // Nhap so luong phan tu cua ds
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n); // Nhap 1 day gom n so va luu vao ds. Phan tu moi duoc them vao cuoi ds
    cout<<"\nThe created Linked List: ";
    outputList(L); // Xuat ds. Neu ds rong thi xuat thong bao "List is empty"


    cout<<"\nEnter a number: "; int m; cin>>m;
    cout<<"\nValues greater than "<<m<<": ";
    outputGreaterThan(L,m);
    /*Xuat tat ca cac gia tri duoc luu trong ds lon hon m.
     Neu ds rong thi xuat thong bao "List is empty".
     Neu ds khong rong nhung khong co gia tri thoa yeu cau thi xuat "None"*/

    return 0;
}
