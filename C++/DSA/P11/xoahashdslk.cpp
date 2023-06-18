/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
#define MAX 1000
using namespace std;

//###INSERT CODE HERE -

struct node {
    int key;
    node* next;
};

node* getNode(int x) {
    node* p = new node;
    p->key = x;
    p->next =  NULL;
    return p;
}

void insert(node*& p, int x) {
    if (p) {
        if (p->key > x) {
            node* q = getNode(x);
            q->next = p;
            p = q;
        } else {
            insert(p->next, x);
        }

    }
    else {
        p = getNode(x);
    }
}

bool deleteHead(node*& p, int b) {
    if (p) {
        if (p->key == b) {
            node* q = p;
            p = p->next;
            delete q;
            return true;
        } else {
            return deleteHead(p->next, b);
        }
    }
    return false;
}

void print(node* p) {
    while (p != NULL) {
        cout << p->key << " ";
        p = p->next;
    }
    cout << endl;
}

struct Hash {
    node* bucket[MAX];
    int m;
};

void initHash(Hash& h) {
    for (int i = 0; i < h.m; i++) {
        h.bucket[i] = NULL;
    }
}

void insertHash(Hash& h, int x) {
    int key = x % h.m;
    insert(h.bucket[key], x);
}

void traverseAllHash(Hash h) {
    for (int i = 0; i < h.m; i++) {
        cout <<  "Bucket " << i << ": ";
        print(h.bucket[i]);
    }
}

bool deleteHash(Hash& h, int b) {
    int key = b % h.m;
    return deleteHead(h.bucket[key], b);

}

int main()
{
    Hash H;
    cin>>H.m; // m la so dia chi co trong bang bam
    initHash(H); //khoi tao cac bucket

    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;
        insertHash(H,x); // them 1 gia tri du lieu vao bang bam
    }
    cout<<"Created Hash:"<<endl;
    traverseAllHash(H); // Xuat toan bo cac bucket cua Bang bam
    int a, b;
    while (true) {
        cin >> a;
        if (a != 1 and a != 2) {
            break;
        }
        cin >> b;
        if (a == 1) {
            cout<<"\nInsert "<<b;
            insertHash(H, b);
        } else {
            cout<<"\nDelete "<<b;
            bool thanhcong = deleteHash(H, b);
            if (!thanhcong) {
                cout<<"\nKhong co phan tu co khoa "<< b;
            }

        }

    }
    cout << "\nUpdated Hash:" << endl;
    traverseAllHash(H);
    return 0;
}

