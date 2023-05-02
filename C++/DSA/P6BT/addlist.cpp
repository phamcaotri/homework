/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
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
void Init(List &l) {
    l.head = NULL;
    l.tail = NULL;
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
void inputList(List &l, int n) {
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        addTail(l, x);
    }
}
void outputList(List &l) {
    if (l.head == NULL) {
        cout << "List is empty";
        return;
    }
    Node* this_node = l.head;
    while (this_node != NULL) {
        cout << this_node->data << " ";
        this_node = this_node->next;
    }
    cout << endl;
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

void addList(List &l, int n) {
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        addHead(l, x);
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

    cout<<"\nEnter a number: "; int m; cin>>m; // Nhap so luong phan tu them vao dau ds
    cout<<"\nEnter a sequence of "<<m<<" numbers: ";
    addList(L,m); // Nhap 1 day gom m so va them phan tu moi vao dau ds
    cout<<"\nThe updated Linked List: ";
    outputList(L); // Xuat ds. Neu ds rong thi xuat thong bao "List is empty"

    return 0;
}
