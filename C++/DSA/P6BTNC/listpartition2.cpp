/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
struct
using
###End banned keyword*/

#include <iostream>
#include <utility>
using std::cin;
using std::cout;
using std::endl;
using std::pair;

struct Node{
    int val;
    Node* next;
};

struct List{
    Node *head, *tail;
};

void list_initializing(List &l){
    l.head = l.tail = NULL;
}
void add_tail(List &l, int x){
    Node*p = new Node;
    p->val = x;
    p->next = NULL;

    if (l.head == NULL){
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}

void xuat(List &l){
    for(Node *p = l.head; p != NULL; p = p->next){
        cout << p->val << " ";
    }
    cout << endl;
}

//###INSERT CODE HERE -

pair<List, List> split(List &l) {
    
    pair<List, List> ls;
    list_initializing(std::get<0>(ls));
    list_initializing(std::get<1>(ls));

    Node* p = l.head;
    bool odd = true;
    while (p != NULL) {
        if (odd) {
            add_tail(std::get<0>(ls), p->val);
            odd = false;
        } else {
            add_tail(std::get<1>(ls), p->val);
            odd = true;
        }
        p = p->next;
        delete l.head;
        l.head = p;
    }
    
    list_initializing(l);
    return ls;
    // tạo một tuple List để lưu trữ

    // cho con trỏ p bắt đầu từ head

    // điều kiện dừng: p == NULL

    // kt dk
    // gắn vào tuple

    // xuất tuple
}

int main()
{
    List l; list_initializing(l);
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int x;
    do{
        cin >> x;
        if (x != 0) add_tail(l, x);
        else break;
    } while(true);


    pair<List, List> ls = split(l);

    xuat(ls.first);
    xuat(ls.second);

    return 0;
}
