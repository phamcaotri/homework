/*
# định nghĩa: struct
# nhập cây
    # tìm vị trí phù hợp
    - tìm trên toàn bộ cây
    - so sánh với nút gốc
    - nếu nhỏ hơn nút gốc, tìm bên nhánh trái của cây, nếu lớn hơn thì tìm bên nhánh phải của cây

# xuất cây

*/

#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* left, *right;
};

typedef Node* Tree;


Node* getNode(int x) {
    Node* new_node = new Node;
    new_node->info = x;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void insert(Tree &t, int x) {
    if (t) {
        if (x == t->info)
            return;
        if (x < t->info)
            insert(t->left,x);
        if (x > t->info)    
            insert(t->right, x);
    } else {
        t = getNode(x);
    }

}

void inputTree(Tree &t) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(t, x);
    }
}



void LNR(Tree t, int &c) {
    if (t) {
        LNR(t->left, c);
        c ++;
        LNR(t->right, c);
    }
}

int countNodes(Tree t) {
    int c = 0;
    LNR(t, c);
    return c;
}

bool isLeafs(Tree t) {
    if (t->left == NULL and t->right == NULL)
        return true;
    return false;
}

void listLeafs(Tree t, int &c) {
    if (t) {
        if (isLeafs(t))
            c++;
        listLeafs(t->left, c);
        listLeafs(t->right, c);
    }
}

int countLeafs(Tree t) {
    int c = 0;
    listLeafs(t, c);
    return c;
}

bool isInternalNodes(Tree t, int &n) {
    if (n) {
        if (t->left != NULL or t->right != NULL)
            return true;
        return false;
    } else {
        n++;
        return false;
    }

}

void listInternalNodes(Tree t, int n, int &c) {
    if (t) {
        if (isInternalNodes(t, n))
            c++;
        listInternalNodes(t->left, n, c);
        listInternalNodes(t->right, n, c);
    }
}

int countInternalNodes(Tree t) {
    int c = 0, n = 0;
    listInternalNodes(t, n, c);
    return c;
}

bool haveOneChild(Tree t) {
    if ((t->left and !t->right) or (!t->left and t->right))
        return true;
    return false;
}

void listNodesWithOneChild(Tree t, int &c) {
    if (t) {
        if (haveOneChild(t))
            c++;
        listNodesWithOneChild(t->left, c);
        listNodesWithOneChild(t->right, c);
    }
}

int countOneChild(Tree t) {
    int c = 0;
    listNodesWithOneChild(t, c);
    return c;
}
bool haveTwoChild(Tree t) {
    if (t->left and t->right)
        return true;
    return false;
}

void listNodesWithTwoChildren(Tree t, int &c) {
    if (t) {
        if (haveTwoChild(t))
            c++;
        listNodesWithTwoChildren(t->left, c);
        listNodesWithTwoChildren(t->right, c);
    }
}

int countTwoChildren(Tree t) {
    int c = 0;
    listNodesWithTwoChildren(t, c);
    return c;
}

void LNR_L(Tree t, int x, int &c) {
    if (t) {
        LNR_L(t->left, x, c);
        if (t->info < x)
            c ++;
        LNR_L(t->right, x, c);
    }
}

void LNR_R(Tree t, int x, int y, int &c) {
    if (t) {
        LNR_R(t->left, x, y, c);
        if (t->info > x and t->info < y)
            c ++;
        LNR_R(t->right, x, y, c);
    }
}
int countLess(Tree t, int x) {
    int c = 0;
    LNR_L(t, x, c);
    return c;
}

int countBetweenValues(Tree t, int x, int y) {
    int c = 0;
    LNR_R(t, x, y, c);
    return c;
}

int main()
{
	Tree T = NULL;
	inputTree(T);

    cout<<"Number of nodes: " << countNodes(T)<<endl;
	cout<<"Number of leaf nodes: " << countLeafs(T)<<endl;
	cout<<"Number of internal nodes: "<< countInternalNodes(T)<<endl;
	cout<<"Number of nodes with one child: "<< countOneChild(T)<<endl;
	cout<<"Number of nodes with two children: "<< countTwoChildren(T)<<endl;

	int x;cout<<"Enter x: ";cin>>x;
	cout<<"\nNumber of nodes less than "<<x<<": "<< countLess(T,x)<<endl;
	int y; cout<<"Enter x,y: ";cin>>x>>y;
	cout<<"\nNumber of nodes greater than "<<x<<" and less than "<<y<<": "<< countBetweenValues(T,x,y)<<endl;

	return 0;
}

