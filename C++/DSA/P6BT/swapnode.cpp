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

node* findFirstNodeEqual2(List &l, int x, node* &prev) {
    node *this_node = l.pHead;
    prev = NULL;
    while (this_node != NULL) {
        if (this_node->info == x) {
            return this_node;
        }
        prev = this_node;
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

node* swapNode(List &L, int x, int y) {
    node* prev_x = NULL;
    node* prev_y = NULL;
    node* node_x = findFirstNodeEqual2(L,x, prev_x);
    node* node_y = findFirstNodeEqual2(L,y, prev_y);
    if (node_x == NULL or node_y == NULL) {
        return NULL;
    }
    if (node_x == node_y) {
        return node_x;
    }
    bool flag1 = false;
    if (node_x == L.pHead) {
        L.pHead = node_y;
        flag1 = true;
    } else {
        prev_x->next = node_y;
    }
    if (node_y == L.pHead and flag1 == false) {
        L.pHead = node_x;
    } else {
        prev_y->next = node_x;
    }
    bool flag2 = false;
    if (node_x == L.pTail) {
        L.pTail = node_y;
        flag2 = true;
    }
    if (node_y == L.pTail and flag2 == false) {
        L.pTail = node_x;
    }
    node* temp_x_next = node_x->next;
    node_x->next = node_y->next;
    node_y->next = temp_x_next;


    return node_x;
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

    int x, y; cin>>x>>y;
    node *p = swapNode(L,x,y); // Tim 2 node chua x va y, Hoan vi 2 node, thay doi cac moi lien ket giua cac node
    /* Tim 2 node chua x va y,
    Hoan vi 2 node do,
    nghia la: Thay doi moi lien ket giua cac node co lien quan, doi cho cac node, gia tri chua trong cac node khong thay doi
    Ham return node chua x ban dau, luc chua hoan vi*/

    cout<<"Updated List after swapping "<<x<<" and "<<y<<": "<<endl;
    outputList(L);
    cout<<endl;

    /* Kiem tra xem co that su hoan vi 2 node khong
    Neu hoan vi node thi node chua x ban dau cung van chua x, gia tri cua node khong thay doi*/
    if(p) // co doi cho
    {
        cout<<"At the address of "<<x<< ": ";
        cout<<p->info;
    }
    else cout<<"Can not swap";
    return 0;
}
