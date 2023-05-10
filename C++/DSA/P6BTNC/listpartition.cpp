/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
struct
using
###End banned keyword*/
#include <iostream>
#include <tuple>
#include <utility>
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::get;
using std::tuple;
using std::make_tuple;

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

tuple<List, List, List> partition(List &l, int x) {
    
    tuple<List, List, List> ls;
    list_initializing(get<0>(ls));
    list_initializing(get<1>(ls));
    list_initializing(get<2>(ls));

    Node* p = l.head;

    while (p != NULL) {
        if (p->val < x) {
            add_tail(get<0>(ls), p->val);
        } else if (p->val == x) {
            add_tail(get<1>(ls), p->val);
        } else {
            add_tail(get<2>(ls), p->val);
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

    // kiểm tra p->val xem nhỏ hơn, bằng, lớn hơn pivot

    // gắn vào tuple

    // xuất tuple
}

void join(List &l, List t) {
    if (t.head == NULL) {
        return;
    }
    if (l.head == NULL) {
        l.head = t.head;
        l.tail = t.tail;
    } else {
        l.tail->next = t.head;
        l.tail = t.tail;
    }
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


    do{
        cin >> x;
        if (x == 0) break;
        
        auto ls = partition(l, x);

        xuat(std::get<0>(ls));
        xuat(std::get<1>(ls));
        xuat(std::get<2>(ls));
        
        
        join(l, std::get<0>(ls));
        join(l, std::get<1>(ls));
        join(l, std::get<2>(ls));
        
    } while(true);

    return 0;
}



