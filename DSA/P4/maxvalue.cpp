
#include <iostream>
#include <cstring>
#include <string>
using namespace std;


struct node {
    int info;
    node* next;
};

struct List {
    node* head = NULL;
    node* tail = NULL;
};

node* getnode(int x) {
    node *new_node = new node;
    // trường hợp cấp phát không thành công
    if (new_node == NULL) {
        cout << "Memory allocation failed";
        return NULL;
    }
    // trường hợp cấp phát thành công
    new_node->info = x;
    new_node->next = NULL;
    return new_node;
}

void addHead(List &l, int x) {
    node *new_node = getnode(x);
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
    node *new_node = getnode(x);
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

void addAfter(List &l, node *this_node, int x) {
    node *new_node = getnode(x);
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
    node *this_node = l.head;
    l.head = l.head->next;
    this_node->next = NULL;
    delete this_node;
    // trường hợp danh sách có 1 phần tử
    if (l.head == NULL)
        l.tail == NULL;
}

node* findX(List &l, int x) {
    node* p = l.head;
    while (p != NULL) {
        if (p->info == x) {
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
    node *this_node = l.head, *node_before = NULL;
    while (this_node != NULL) {
        if (this_node->info == x)
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
    node* p = l.head;
    while (p != NULL) {
    cout << p->info << ' ';
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
        node *p = L.head;
        while (p != NULL) {
            cout << p->info << ' ';
            p = p->next;
        }
    }
}

node* findMax(List L) {
    if (L.head == NULL) {
        cout << "List is empty";
        return NULL;
    }
    else {
        node *p = L.head;
        node *max = L.head;
        while (p != NULL) {
            if (p->info > max->info) {
                max = p;
            }
            p = p->next;
        }
        return max;
    }
}

int main()
{
    List L;
    Init(L);
    int n; cout<<"Enter a number: "; cin>>n;
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n);
    cout<<"\nThe created Linked List: ";
    outputList(L);


    cout<<"\nThe maximum value: ";
    node *p = findMax(L);
    if(p) cout<<p->info;

    return 0;
}
