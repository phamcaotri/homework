/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
struct
###End banned keyword*/

#include <iostream>
using namespace std;

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

void reverse_list(List &l){
//###INSERT CODE HERE -

// tạo 3 biến q p r là 3 con trỏ trỏ vào 3 nốt kế nhau
Node* left = l.head;
Node *mid = l.head->next;
if (mid == NULL) {
    return;
}
Node* right = l.head->next->next;
left->next = NULL;
mid->next = left;
l.head = l.tail;
l.tail = left;
if (right == NULL) {
    return;
} else {
    left = mid;
    mid = right;
    right = right->next;
}
do {
    mid->next = left;
    left = mid;
    mid = right;
    right = right->next;

} while (right != NULL);
mid->next = left;

// bắt đầu từ head, q.next = NULL, p.next = q

// sau đó, không đá động gì đến q nữa (nếu NULL tiếp thì pay danh sách)

// chỉ cần p.next = q là đủ
// dời q p r đi như sau: q = p, p = r, r=r.next;

// điều kiện dừng: khi r = NULL, thì thực hiện lần cuối rồi dừng
// tức là do while (r != NULL)

// sau đó hoán con trỏ một lần cuối

// lưu ý: nhớ update head tail

// ngoại lệ: chỉ có 2 phần tử: đơn giản chỉ cần q.next = NULL, p.next = q

// ngoại lệ: chỉ có 1 phần tử: giữ nguyên

//
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

    for(int i = 0; i < 51; i++) reverse_list(l);

    xuat(l);

    return 0;
}
