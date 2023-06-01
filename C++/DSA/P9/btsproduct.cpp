/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;

//###INSERT CODE HERE -


struct SanPham {
    int maSP;
    string tenSP;
    string chungLoai;
    int namSX;
    int soNamBaoHanh;

    void Nhap() {
        cin >> maSP;
        cin.ignore();
        getline(cin, tenSP);
        getline(cin, chungLoai);
        cin >> namSX;
        cin >> soNamBaoHanh;
    }

    void Xuat() {
        cout << maSP << ' ' << tenSP << ' '
        << chungLoai << ' ' << namSX << ' '
        << soNamBaoHanh << endl;
    }
    bool operator==(SanPham b) {
        return maSP == b.maSP;
    }
    bool operator>(SanPham b) {
        return maSP > b.maSP;
    }
    bool operator<(SanPham b) {
        return maSP < b.maSP;
    }
};

struct Node {
    SanPham info;
    Node* left, *right;
};
typedef Node* Tree;

Node* getNode(SanPham x) {
    Node* newNode = new Node;
    newNode->info = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool insert(Tree &t, SanPham x) {
    if (t) {
        if (x == t->info) {
            return 0;
        }
        if (x < t->info)
            return insert(t->left, x);
        if (x > t->info)
            return insert(t->right, x);
    } else {
        t = getNode(x);
    }
    return 1;
}

void inputTree(Tree &t) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        SanPham x;
        x.Nhap();
        if (!insert(t, x))
            return;
    }
}

void NLR(Tree t, string type) {
    if (t) {
        if (type == t->info.chungLoai)
            t->info.Xuat();
        NLR(t->left, type);
        NLR(t->right, type);
    }
}

void NLRForYear(Tree t, int year, int& count) {
    if (t) {
        if (t->info.soNamBaoHanh > year)
            count ++;
        NLRForYear(t->left, year, count);
        NLRForYear(t->right, year, count);
    }
}


void listProduct(Tree t, string type) {
    NLR(t, type);
}

int countProduct(Tree t, int year) {
    int count = 0;
    NLRForYear(t, year, count);
    return count;
}

int main()
{
    Tree T = NULL;
    inputTree(T);

    string type;  cin.ignore(); getline(cin,type);
    cout<<"List of products whose type is  "<<type<<": ";
    cout<<"\nID\tName\tType\tYear\tWarranty\n";
    listProduct(T,type);

    int year;cin>>year;
    cout<<"Number of products with more than "<<year<<" years of warranty: "<<countProduct(T,year)<<endl;


	return 0;
}

