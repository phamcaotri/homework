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

struct Tinh {
    int id;
    string name;
    int pop;
    float area;
};

struct node{
    Tinh info;
    node *next;
};

struct List{
    node *pHead;
    node *tail;
};

void Init(List &L){
    L.pHead = L.tail = NULL;
}

void inputTinh(Tinh &x){
    cin >> x.id;
    cin.ignore();
    getline(cin, x.name);
    cin >> x.pop;
    cin >> x.area;
}

void outputProvince(Tinh x){
    cout << x.id << "\t";
    cout << x.name << "\t";
    cout << x.pop << "\t";
    cout << x.area << "\t";
    cout << endl;
}

node* getNode(Tinh x) {
    node* new_node = new node;
    new_node->info = x;
    new_node->next = NULL;
    return new_node;
}

void addTail(List &l, Tinh x) {
    node* new_node = getNode(x);
    // trường hợp danh sách rỗng
    if (l.tail == NULL) {
        l.pHead = l.tail = new_node;
    }
    else {
    // trường hợp danh sách không rỗng
        l.tail->next = new_node;
        l.tail = new_node;
    }
}


void inputListProvinces(List &l) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Tinh x;
        inputTinh(x);
        addTail(l, x);
    }
}

void inputOneProvinceAfterNode(List &l, node* this_node) {
    Tinh x;
    inputTinh(x);
    node* new_node = getNode(x);
    // trường hợp danh sách rỗng
    if (this_node == NULL) {
        l.pHead = l.tail = new_node;
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


void outputListProvinces(List l) {
    if (l.pHead == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    node* this_node = l.pHead;
    while (this_node != NULL) {
        outputProvince(this_node->info);
        this_node = this_node->next;
    }
    cout << endl;
}

node* findProMaxArea(List l) {
    node* this_node = l.pHead, *max_node = l.pHead;
    while (this_node != NULL) {
        if (this_node->info.area > max_node->info.area) {
            max_node = this_node;
        }
        this_node = this_node->next;
    }
    return max_node;
}

void outputProvincesMore1MillionPop(List l) {
    node* this_node = l.pHead;
    while (this_node != NULL) {
        if (this_node->info.pop > 1000) {
            outputProvince(this_node->info);
        }
        this_node = this_node->next;
    }
}

node* searchTinh(List &l, string name) {
    node *this_node = l.pHead;
    while (this_node != NULL) {
        if (this_node->info.name.find(name) != string::npos) {
            return this_node;
        }
        this_node = this_node->next;
    }
    return NULL;
}

void deleteAllNodeEqual(List &l, string x) {
    // trường hợp danh sách rỗng
    if (l.pHead == NULL) {
        return;
    }
    // trường hợp xoá đầu danh sách
    while (l.pHead != NULL && l.pHead->info.name.find(x) != string::npos) {
        node* temp = l.pHead;
        l.pHead = l.pHead->next;
        temp->next = NULL;
        delete temp;
    }
    // trường hợp danh sách có nhiều hơn 1 phần tử
    node* this_node = l.pHead, *node_before = NULL;
    while (this_node != NULL) {
        if (this_node->info.name.find(x) != string::npos) {
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


void removeList(List &l) {
    node* this_node = l.pHead;
    while (this_node != NULL) {
        node* temp = this_node;
        this_node = this_node->next;
        temp->next = NULL;
        delete temp;
    }
    l.pHead = l.tail = NULL;
}

int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);

    if(L.pHead)
    {
        cout<<"Delete all:"<<endl;
        removeList(L);
        outputListProvinces(L);
    }
    return 0;
}




