/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct Node {
    int info;
    Node* left;
    Node* right;
};

typedef Node* Tree;

Node* getNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->left =  p->right = NULL;
    return p;
}

Node* Search(Tree& t, int b) {
    if (!t) {
        return NULL;
    }
    if (t->info == b) {
        return t;
    }
    Node* p = Search(t->left, b);
    if (p) {
        return p;
    }
    return Search(t->right, b);
}

void SetLeft(Node* node, int x) {
    if (!node) {
        return;
    }
    if (node->left) {
        return;
    }
    node->left = getNode(x);

}

void SetRight(Node* node, int x) {
    if (!node) {
        return;
    }
    if (node->right) {
        return;
    }
    node->right = getNode(x);

}

void LNR(Tree t) {
    if (t) {
        LNR(t->left);
        cout << t->info << ' ';
        LNR(t->right);
    }
}

void DeleteLeft(Node* node) {
    if (!node) {
        cout<<"Node khong ton tai\n";
        return;
    }
    if (!node->left) {
        cout << "Khong co node ben trai\n";
        return;
    }
    if (node->left->left or node->left->right) {
        cout << "Khong la node la nen khong xoa duoc\n";
        return;
    }
    Node* p = node->left;
    node->left = NULL;
    delete p;
}

void DeleteRight(Node* node) {
    if (!node) {
        cout<<"Node khong ton tai\n";
        return;
    }
    if (!node->right) {
        cout << "Khong co node ben phai\n";
        return;
    }
    if (node->right->left or node->right->right) {
        cout << "Khong la node la nen khong xoa duoc\n";
        return;
    }
    Node* p = node->right;
    node->right = NULL;
    delete p;
}

int main()
{
	Tree T = NULL;
	int x,b,c; char a;
	cin>>x;	T=getNode(x); // tao nut goc
	while(true)
    {
        cin>>a; // Ky tu cho biet chen vao trai hay phai
        if(a!='L'&& a!='R') break;
        cin>>b>>c;
        if(a=='L') SetLeft(Search(T,b),c);
        else if (a=='R') SetRight(Search(T,b),c);

    }
	cout<<"LNR: "; LNR(T);
	cout<<"\nDelete some nodes:\n";
	string s;
	while(true)
    {
        cin>>s; // Chuoi cho biet xoa ben trai hay ben phai
        if(s!="DL"&& s!="DR") break;
        cin>>b;
        if(s=="DL") DeleteLeft(Search(T,b));
        else if(s=="DR") DeleteRight(Search(T,b));

    }
    cout<<"\nLNR: "; LNR(T);

	return 0;
}
