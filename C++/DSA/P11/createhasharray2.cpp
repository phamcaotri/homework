/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
->
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
#define M 10		// M là số nút có trên bảng băm, đủ để chứa các nút nhập vào bảng băm
#define NULLKEY -1
using namespace std;

//###INSERT CODE HERE -

struct node {
    int key;
    int value;
};

struct Hash {
    int m = M;
    node* hashtable;
    int n;
};

bool isFull(Hash H) {
    return H.n == H.m;
}

int hashfunc(int k) {
    return k % M;
}

void insertHash(Hash& H, int k) {
    if (isFull(H)) {
        cout << "\nBang bam bi day, khong them duoc";
        return;
    }
    int i = hashfunc(k);
    int j = 0;
    while (H.hashtable[i].key != NULLKEY) {
        i = hashfunc(k);
        i = (i + j*j) % M;
        j++;
    }
    H.hashtable[i].key = k;
    H.n ++;
}

void initHash(Hash& H) {
    H.hashtable = new node[H.m];
    H.n = 0;
    for (int i = 0; i < H.m; i++) {
        H.hashtable[i].key = NULLKEY;
    }
}

void traverseAllHash(Hash H) {
    for (int i = 0; i < H.m; i++) {
        cout << i;
        if (H.hashtable[i].key == NULLKEY) {
            cout << endl;
            continue;
        }
        else
            cout << " --> " << H.hashtable[i].key << endl;
    }
}

int main()
{
    Hash H;
    initHash(H);

    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;
        cout<<"\nInsert "<<x;
        insertHash(H,x); // them 1 gia tri du lieu vao bang bam
    }
    cout<<"\nCreated Hash:"<<endl;
    traverseAllHash(H);

    return 0;
}

