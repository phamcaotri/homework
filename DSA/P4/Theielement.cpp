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
    node* new_node = new node;
    new_node->info = x;
    new_node->next = NULL;
    return new_node;
}

void addHead(List &l, int x) {
    node* new_node = getnode(x);
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
    node* new_node = getnode(x);
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

node* findFirstnodeEqual(List &l, int x) {
    node *this_node = l.head;
    while (this_node != NULL) {
        if (this_node->info == x) {
            return this_node;
        }
        this_node = this_node->next;
    }
    return NULL;
}



void addAfternode(List &l, node* this_node, int x) {
    node* new_node = getnode(x);
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
        node* this_node = l.head;
        l.head = l.head->next;
        delete this_node;
    }
    // trường hợp danh sách có 1 phần tử
    if (l.head == NULL) {
        l.tail = NULL;
    }
}

void deleteFirstnodeEqual(List &l, int x) {
    // trường hợp danh sách rỗng
    if (l.head == NULL) {
        return;
    }
    // trường hợp xoá đầu danh sách
    if (l.head->info == x) {
        deleteHead(l);
        return;
    }
    // trường hợp danh sách có nhiều hơn 1 phần tử
    node* this_node = l.head, *node_before = NULL;
    while (this_node != NULL) {
        if (this_node->info == x) {
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

void deleteAllnodeEqual(List &l, int x) {
    // trường hợp danh sách rỗng
    if (l.head == NULL) {
        return;
    }
    // trường hợp xoá đầu danh sách
    while (l.head != NULL && l.head->info == x) {
        deleteHead(l);
    }
    // trường hợp danh sách có nhiều hơn 1 phần tử
    node* this_node = l.head, *node_before = NULL;
    while (this_node != NULL) {
        if (this_node->info == x) {
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
    node* this_node = l.head;
    while (this_node != NULL) {
        cout << this_node->info << " ";
        this_node = this_node->next;
    }
    cout << endl;
}

node* maxValuenode(List &l) {
    node* this_node = l.head, *max_node = l.head;
    while (this_node != NULL) {
        if (this_node->info > max_node->info) {
            max_node = this_node;
        }
        this_node = this_node->next;
    }
    return max_node;
}

node* minValuenode(List &l) {
    node* this_node = l.head, *min_node = l.head;
    while (this_node != NULL) {
        if (this_node->info < min_node->info) {
            min_node = this_node;
        }
        this_node = this_node->next;
    }
    return min_node;
}

int listSize(List &l) {
    int count = 0;
    node* this_node = l.head;
    while (this_node != NULL) {
        count++;
        this_node = this_node->next;
    }
    return count;
}

void Init(List &L)
{
    L.head = L.tail = NULL;
}

node* findElement(List &l, int i) {
    // trường hợp danh sách rỗng
    if (l.head == NULL) {
        cout << "List is empty";
        return NULL;
    }
    // trường hợp i không hợp lệ
    if (i < 1 or i > listSize(l)) {
        cout << "The index is invalid";
        return NULL;
    }
    node* this_node = l.head;
    // đếm từ 1
    int count = 1;
    while (this_node != NULL) {
        if (count == i) {
            return this_node;
        }
        count++;
        this_node = this_node->next;
    }
    return NULL;
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

    int i; cout<<"\nEnter a number: "; cin>>i;
    cout<<"\nThe element at index "<<i<<": ";
    node *p = findElement(L,i);
    if(p) cout<<p->info;


    return 0;
}