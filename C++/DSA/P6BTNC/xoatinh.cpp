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
    if (l.head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
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

node* searchTinh(List &l, string name) {
    node *this_node = l.head;
    while (this_node != NULL) {
        if (this_node->info.name == name) {
            return this_node;
        }
        this_node = this_node->next;
    }
    return NULL;
}


int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);
    if (L.head == NULL) {
        return 0;
    }

    // cout<<"Enter the name to search:"<<endl;
    // string name;
    // cin.ignore();
    // getline(cin, name);
    // node* tinh_duoc_search = searchTinh(L,name);
    // if (tinh_duoc_search == NULL) {
    //     cout<<"Not found"<<endl;
    // }
    // else {
    //     cout<<"Input a new province:"<<endl;
    //     inputOneProvinceAfterNode(L, tinh_duoc_search);
    //     cout<<"Updated List:"<<endl;
    //     cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    //     outputListProvinces(L);
    // }
    cout << "Enter the name of the province you want to delete:" << endl;
    string name;
    cin.ignore();
    getline(cin, name);
    node* tinh_duoc_search = searchTinh(L, name);
    if (tinh_duoc_search == NULL) {
        cout << "Not found" << endl;
        return 0;
    }
    else {
        node* this_node = L.head;
        while (this_node != NULL) {
            if (this_node->next == tinh_duoc_search) {
                this_node->next = tinh_duoc_search->next;
                if (tinh_duoc_search == L.tail) {
                    L.tail = this_node;
                }
                delete tinh_duoc_search;
                break;
            }
            this_node = this_node->next;
        }
        if (tinh_duoc_search == L.head) {
            L.head = L.head->next;
            delete tinh_duoc_search;
        }
        if (L.head == NULL) {
            L.tail = NULL;
        }
        cout << "Updated List:" << endl;
        cout << "ID\t|Province\t|Population\t|Area" << endl;
        outputListProvinces(L);
    }



    return 0;
}