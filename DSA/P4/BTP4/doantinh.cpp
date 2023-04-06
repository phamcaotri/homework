#include <iostream>
#include <cstring>
#include <string>
using namespace std;

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
    node *head;
    node *tail;
};

void Init(List &L){
    L.head = L.tail = NULL;
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
        l.head = l.tail = new_node;
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


void outputListProvinces(List l) {
    node* this_node = l.head;
    while (this_node != NULL) {
        outputProvince(this_node->info);
        this_node = this_node->next;
    }
    cout << endl;
}

void outputProvincesMore1MillionPop(List l) {
    node* this_node = l.head;
    while (this_node != NULL) {
        if (this_node->info.pop > 1000) {
            outputProvince(this_node->info);
        }
        this_node = this_node->next;
    }
}

node* searchTinh(List &l, string name) {
    node *this_node = l.head;
    while (this_node != NULL) {
        if (this_node->info.name.find(name) != string::npos) {
            return this_node;
        }
        this_node = this_node->next;
    }
    return NULL;
}

node* findProMaxArea(List l) {
    node* this_node = l.head, *max_node = l.head;
    while (this_node != NULL) {
        if (this_node->info.area > max_node->info.area) {
            max_node = this_node;
        }
        this_node = this_node->next;
    }
    return max_node;
}

int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    node *TinhToNhat = findProMaxArea(L);
    if (TinhToNhat == NULL) {
        cout<<"NO"<<endl;
    }
    else {
        string name;
        cin.ignore();
        getline(cin, name);
        if (TinhToNhat->info.name.find(name) != string::npos) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }



    return 0;
}