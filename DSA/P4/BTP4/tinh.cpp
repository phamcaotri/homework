/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

/*
struct Tinh:
id - int
name - string
pop - int
area - float

1. nhập xuất thông tin n tỉnh, thêm vào cuối danh sách
2. xuất các tỉnh có dân số > 1 triệu
3. tìm tỉnh có diện tích lớn nhất
*/

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

void outputListProvinces(List l) {
    node* this_node = l.head;
    while (this_node != NULL) {
        outputProvince(this_node->info);
        this_node = this_node->next;
    }
    cout << endl;
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

void outputProvincesMore1MillionPop(List l) {
    node* this_node = l.head;
    while (this_node != NULL) {
        if (this_node->info.pop > 1000) {
            outputProvince(this_node->info);
        }
        this_node = this_node->next;
    }
}



int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);

    cout<<"Provinces with a population of more than 1 million:"<<endl;
    outputProvincesMore1MillionPop(L);

    cout<<"The largest province:"<<endl;
    node *p = findProMaxArea(L);
    if(p) outputProvince(p->info);

    return 0;
}