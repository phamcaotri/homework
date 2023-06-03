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
    p->left = p->right = NULL;
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
        cout<<"Node khong ton tai\n";
        return;
    }
    if (node->left) {
        cout << "Da co node con ben trai\n";
        return;
    }
    node->left = getNode(x);

}

void SetRight(Node* node, int x) {
    if (!node) {
        cout<<"Node khong ton tai\n";
        return;
    }
    if (node->right) {
        cout << "Da co node con ben phai\n";
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

bool isBST(Tree t) {
    if (t) {
        if (t->left) {
            if (t->left->info >= t->info)
                return 0;
        }
        if (t->right) {
            if (t->right->info <= t->info)
                return 0;
        }
        bool x = isBST(t->left);
        if (!x) {
            return 0;
        }
        bool y = isBST(t->right);
        return y;
        
    } else {
        return 1;
    }
}

int main()
{
	Tree T = NULL;
	int x,b,c; char a;
	cin>>x;	T=getNode(x); // tao nut goc
	while(true)
    {
        cin>>a; // Ky tu cho biet chen vao trai hay phai
        if(a!='L'&& a!='R') break; // Neu khong phai L hoac R thi ket thuc viec tao cay
        cin>>b>>c;
        if(a=='L') SetLeft(Search(T,b),c); // chen c vao ben trai b
        else if (a=='R') SetRight(Search(T,b),c); // chen c vao ben phai b
    }
	cout<<"\nLNR: "; LNR(T); cout<<endl;
    if(isBST(T)) cout<<"\Cay vua tao la cay BST";
    else cout<<"\Cay vua tao khong phai la cay BST";

	return 0;
}
