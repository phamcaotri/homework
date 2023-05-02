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
struct node {
    int info;
    node* next;
};

struct List {
    node* pHead = NULL;
    node* pTail = NULL;
    int size = 0;
};

node* getnode(int x) {
    node* new_node = new node;
    new_node->info = x;
    new_node->next = NULL;
    return new_node;
}


void addTail(List &l, int x) {
    node* new_node = getnode(x);
    // trường hợp danh sách rỗng
    if (l.pTail == NULL) {
        l.pHead = l.pTail = new_node;
    }
    else {
    // trường hợp danh sách không rỗng
        l.pTail->next = new_node;
        l.pTail = new_node;
    }
}

void inputList(List &l, int n) {
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        addTail(l, x);
    }
    l.size = n;
}

void outputList(List &l) {
    if (l.pHead == NULL) {
        cout << "List is empty";
        return;
    }
    node* this_node = l.pHead;
    while (this_node != NULL) {
        cout << this_node->info << " ";
        this_node = this_node->next;
    }
    cout << endl;
}

void addHead(List &l, int x) {
    node* new_node = getnode(x);
    // trường hợp danh sách rỗng
    if (l.pHead == NULL) {
        l.pHead = l.pTail = new_node;
    }
    else {
    // trường hợp danh sách không rỗng
        new_node->next = l.pHead;
        l.pHead = new_node;
    }
}

void moveLastToFront(List &l) {
    if(l.pHead == NULL or l.pHead->next == NULL) return;
    node* this_node = l.pHead;
    while (this_node->next != l.pTail) {
        this_node = this_node->next;
    }
    addHead(l, l.pTail->info);
    l.pTail = this_node;
    this_node->next = NULL;
}
int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L);
    cout<<endl;

    moveLastToFront(L); //di chuyen node cuoi ve dau danh sach
    cout<<"Updated List after moving the last element to front of L: "<<endl;
    outputList(L);
    return 0;
}
