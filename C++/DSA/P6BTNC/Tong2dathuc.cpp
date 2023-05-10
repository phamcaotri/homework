/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
[
]
define
include
###End banned keyword*/
#include<iostream>
#include <iomanip>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
};


struct Node{
	DONTHUC* data;
	Node* next;

};

typedef struct DATHUC{
	Node* head;
	Node* tail;
}List;


//###INSERT CODE HERE -

void addNode(List& l, DONTHUC* x){
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    if (l.head == NULL){
        l.head = l.tail = p;
    }
    else{
        l.tail->next = p;
        l.tail = p;
    }
}

void addTail(List& l, DONTHUC* x){
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    if (l.head == NULL){
        l.head = l.tail = p;
    }
    else{
        l.tail->next = p;
        l.tail = p;
    }
}

void Nhap(DATHUC& b){
    b.head = b.tail = NULL;
    int n; cin >> n;
    double heso; int somu;
    for (int i = 0; i < n; i++)
    {
		cin >> heso >> somu;
        DONTHUC* x = new DONTHUC;
        x->heso = heso;
        x->somu = somu;
        addTail(b, x);
    }

}

void Xuat(DATHUC b) {
    Node* p = b.head;
    bool flag = false;
    while(p != NULL){
        if (p->data->heso == 0){
            if (p->next != NULL){
                if (p->next->data->heso > 0 and flag == true){
                    cout << "+";
                }
            }
            p = p->next;
            continue;
        }
        if (p->data->somu == 0){
            cout << p->data->heso;
            flag = true;
            if (p->next != NULL){
                if (p->next->data->heso > 0 and flag == true){
                    cout << "+";
                }
            }
            p = p->next;
            continue;
        }
        else if (p->data->heso == 1){
            cout << "x";
            flag = true;
        }
        else if (p->data->heso == -1){
            cout << "-x";
            flag = true;
        }
        else{
            cout << p->data->heso << "x";
            flag = true;
        }
        if (p->data->somu == 1){
            if (p->next != NULL){
                if (p->next->data->heso > 0 and flag == true){
                    cout << "+";

                }
            }
            p = p->next;
            continue;
        }
        else {
            cout << "^" << p->data->somu;
            flag = true;
        }
        if (p->next != NULL){
            if (p->next->data->heso > 0 and flag == true){
                cout << "+";
                flag = true;
            }
        }
        p = p->next;

    }
    if (flag == false){
        cout << "0";
    }
}

double pow(double x, int n){
    double sum = 1;
    for (int i = 0; i < n; i++){
        sum *= x;
    }
    return sum;
}

double TinhDaThuc(DATHUC b, double x){
    double sum = 0;
    Node* p = b.head;
    while(p != NULL){
        sum += p->data->heso * pow(x, p->data->somu);
        p = p->next;
    }
    return sum;
}

DATHUC Tong2DaThuc(DATHUC a, DATHUC b){
    DATHUC c;
    c.head = c.tail = NULL;
    Node* p = a.head;
    Node* q = b.head;
    if (p == NULL){
        return b;
    }
    if (q == NULL){
        return a;
    }
    while(p != NULL and q != NULL){
        if (p->data->somu == q->data->somu){
            DONTHUC* x = new DONTHUC;
            x->heso = p->data->heso + q->data->heso;
            x->somu = p->data->somu;
            addTail(c, x);
            p = p->next;
            q = q->next;
        }
        else if (p->data->somu > q->data->somu){
            DONTHUC* x = new DONTHUC;
            x->heso = p->data->heso;
            x->somu = p->data->somu;
            addTail(c, x);
            p = p->next;
        }
        else{
            DONTHUC* x = new DONTHUC;
            x->heso = q->data->heso;
            x->somu = q->data->somu;
            addTail(c, x);
            q = q->next;
        }
    }
    while(p != NULL){
        DONTHUC* x = new DONTHUC;
        x->heso = p->data->heso;
        x->somu = p->data->somu;
        addTail(c, x);
        p = p->next;
    }
    while(q != NULL){
        DONTHUC* x = new DONTHUC;
        x->heso = q->data->heso;
        x->somu = q->data->somu;
        addTail(c, x);
        q = q->next;
    }
    return c;
}

int main() {
    DATHUC A, B;
    Nhap(A);
    Nhap(B);
    cout << "Da thuc A: "; Xuat(A);
    cout << "\nDa thuc B: "; Xuat(B);
    cout << "\nA+B = "; Xuat(Tong2DaThuc(A, B));
    return 0;
}
