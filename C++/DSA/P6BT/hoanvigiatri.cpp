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
};

node* getNode(int x) {
    node* new_node = new node;
    new_node->info = x;
    new_node->next = NULL;
    return new_node;
}


void addHead(List &l, int x) {
    node* new_node = getNode(x);
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

void addTail(List &l, int x) {
    node* new_node = getNode(x);
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

node* findFirstNodeEqual2(List &l, int x) {
    node *this_node = l.pHead;
    while (this_node != NULL) {
        if (this_node->info == x) {
            return this_node;
        }

        this_node = this_node->next;
    }
    return NULL;
}


void addAfterNode(List &l, node* this_node, int x) {
    node* new_node = getNode(x);
    // trường hợp danh sách rỗng
    if (this_node == NULL) {
        l.pHead = l.pTail = new_node;
    }
    else {
    // trường hợp danh sách không rỗng
        new_node->next = this_node->next;
        this_node->next = new_node;
        if (this_node == l.pTail) {
            l.pTail = new_node;
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
    if (l.pHead == NULL) {
        cout << "List is empty" << '\n';
        return;
    }
    node* this_node = l.pHead;
    while (this_node != NULL) {
        cout << this_node->info << " ";
        this_node = this_node->next;
    }
    cout << endl;
}

node* swapData(List &L, int x, int y) {
    node* node_x = findFirstNodeEqual2(L,x);
    node* node_y = findFirstNodeEqual2(L,y);
    if (node_x == NULL or node_y == NULL) {
        return NULL;
    }
    if (node_x == node_y) {
        return node_x;
    }
    int temp = node_x->info;
    node_x->info =node_y->info;
    node_y->info = temp;

    return node_x;
}

int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L); // Neu ds rong thi xuat "List is empty"
    cout<<endl;

    int x, y; cin>>x>>y;
    node *p = swapData(L,x,y);
    /* Tim 2 node chua x va y,
    Hoan vi gia tri cua 2 node do,
    nghia la: Lien ket giua cac node khong thay doi, node ban dau chua x se doi lai la chua y
    Ham return node chua x ban dau, luc chua hoan vi*/

    cout<<"Updated List after swapping "<<x<<" and "<<y<<": "<<endl;
    outputList(L);
    cout<<endl;

    /* Kiem tra xem co that su hoan vi info cua 2 node khong
    Neu hoan vi info thi node chua x ban dau se doi lai chua y*/

    if(p) // co hoan vi
    {
        cout<<"At the address of "<<x<< ": ";
        cout<<p->info;
    }
    else cout<<"Can not swap";
    return 0;
}
