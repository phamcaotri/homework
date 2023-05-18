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

void LNR(Tree t) {
    if (t) {
        LNR(t->left);
        cout << t->info << " ";
        LNR(t->right);
    }
}

void LNR(Tree t, int& c) {
    if (t) {
        LNR(t->left, c);
        c++;
        LNR(t->right, c);
    }
}


int countNodes(Tree t) {
    int c = 0;
    LNR(t, c);
    return c;
}

int depthOfTree(Tree t) {
    if (!t) return -1;
        return max(depthOfTree(t->left), depthOfTree(t->right))+1;
}

void countEven(Tree t, int& e) {
    if (t) {
        if (t->info % 2 == 0) {
            e++;
        }
        countEven(t->left, e);
        countEven(t->right, e);
    }
}

void countOdd(Tree t, int& o) {
    if (t) {
        if (t->info % 2 != 0) {
            o++;
        }
        countOdd(t->left, o);
        countOdd(t->right, o);
    }
}

void P(Tree t, int&c) {
    if (t) {
        if (t->info > 0) {
            c++;
        }
        P(t->left, c);
        P(t->right, c);
    }
}
int countPositive(Tree t) {
    int c = 0;
    P(t, c);
    return c;

}

void N(Tree t, int&c) {
    if (t) {
        if (t->info < 0) {
            c++;
        }
        N(t->left, c);
        N(t->right, c);
    }
}

int countNegative(Tree t) {
    int c = 0;
    N(t, c);
    return c;
}

bool is_prime(int x) {
    if (x <= 1) return false;
    if (x == 2) return true;
    for (int i = 2; i < x; i++) {
        if (x%i == 0) return false;
    }
    return true;
}

void Pr(Tree t, int& c) {
    if (t) {
        if (is_prime(t->info)) {
            c++;
        }
        Pr(t->left, c);
        Pr(t->right, c);
    }
}

int countPrime(Tree t){
    int c = 0;
    Pr(t, c);
    return c;
}

void listPrime(Tree t) {
        if (t) {
        if (is_prime(t->info))
            cout << t->info << " ";
        listPrime(t->left);

        listPrime(t->right);
    }
}
int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<"LNR: "; LNR(T); cout<<endl;

	cout<<"Number of nodes: " << countNodes(T)<<endl;
    cout<<"Depth of Tree: "<<depthOfTree(T)<<endl;

    int count_even = 0, count_odd =0;
    countEven(T, count_even);countOdd(T, count_odd);
    cout<<"Number of even nodes: "<<count_even<<endl;
    cout<<"Number of odd nodes: "<<count_odd<<endl;

    cout<<"Number of positive nodes: "<<countPositive(T)<<endl;
    cout<<"Number of negative nodes: "<<countNegative(T)<<endl;

    cout<<"Number of prime nodes: "<<countPrime(T)<<endl;
    cout<<"Prime numbers: "; listPrime(T);



	return 0;
}
