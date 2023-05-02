#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::chrono;


struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head = NULL;
    Node* tail = NULL;
};

Node* getNode(int x) {
    Node* new_node = new Node;
    new_node->data = x;
    new_node->next = NULL;
    return new_node;
}

void addHead(List &l, int x) {
    Node* new_node = getNode(x);
    // trường hợp danh sách rỗng
    if (l.head == NULL) {
        l.head = l.tail = new_node;
    }
    else {
    // trường hợp danh sách không rỗng
        new_node->next = l.head;
        l.head = new_node;
    }
}

void addTail(List &l, int x) {
    Node* new_node = getNode(x);
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

void deleteHead(List &l) {
    // trường hợp danh sách rỗng
    if (l.head == NULL) {
        return;
    }
    else {
        Node* this_node = l.head;
        l.head = l.head->next;
        delete this_node;
    }
    // trường hợp danh sách có 1 phần tử
    if (l.head == NULL) {
        l.tail = NULL;
    }
}

void inputList(List &l, vector<int> v) {

    for (int i = 0; i < v.size(); i++) {

        addTail(l, v[i]);
    }
}

void outputList(List &l) {
    if (l.head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* this_node = l.head;
    while (this_node != NULL) {
        cout << this_node->data << " ";
        this_node = this_node->next;
    }
    cout << endl;
}

void SortList(List &l) {
    Node* this_node = l.head;
    while (this_node != NULL) {
        Node* next_node = this_node->next;
        while (next_node != NULL) {
            if (this_node->data > next_node->data) {
                int temp = this_node->data;
                this_node->data = next_node->data;
                next_node->data = temp;
            }
            next_node = next_node->next;
        }
        this_node = this_node->next;
    }
}

void SortList2(List &old_list) {
    // lặp lại cho đến khi không còn xảy ra trường hợp addHead
    // bước 1: xem head như là một danh sách mới
    // bước 2: nếu head của danh sách cũ lớn hơn tail của danh sách mới, thì addTail, ngược lại thì addHead
    bool isSorted = false;
    do {
        isSorted = true;
        List new_list;
        new_list.head = new_list.tail = old_list.head;
        old_list.head = old_list.head->next;
        new_list.tail->next = NULL;
        while (old_list.head != NULL) {
            if (old_list.head->data >= new_list.tail->data) {
                new_list.tail->next = old_list.head;
                new_list.tail = old_list.head;
                old_list.head = old_list.head->next;
                new_list.tail->next = NULL;
            }
            else {
                Node* temp = old_list.head;
                old_list.head = old_list.head->next;
                temp->next = new_list.head;
                new_list.head = temp;
                isSorted = false;
            }
        }
        old_list = new_list;
    } while (!isSorted);
    

}

int main() {
    List l1, l2;
    int n; cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }
    random_shuffle(v.begin(), v.end());
    inputList(l1, v);
    //outputList(l1);
    // time in nano seconds
    auto start = high_resolution_clock::now();
    SortList(l1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    //outputList(l1);
    cout << "Time taken by sort 1: "
        << duration.count() << " microseconds" << endl;

    inputList(l2, v);
    auto start2 = high_resolution_clock::now();
    SortList2(l2);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    //outputList(l2);
    cout << "Time taken by sort 2: "
        << duration2.count() << " microseconds" << endl;
    return 0;
}