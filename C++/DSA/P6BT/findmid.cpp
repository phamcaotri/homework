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

node* findMiddle(List &l) {
    // trường hợp danh sách rỗng
    if (l.pHead == NULL) {
        return NULL;
    }
    node* this_node = l.pHead;
    // đếm từ 1
    int count = 0;
    while (count < l.size/2) {
        count++;
        this_node = this_node->next;
    }
    return this_node;
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

    node *p=findMiddle(L); //Neu so phan tu chan thi co 2 phan tu chinh giua, chi xuat phan tu chinh giua thu 2
    if(p)cout<<"The middle element is "<<p->info;

    return 0;
}
