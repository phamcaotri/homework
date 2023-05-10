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
int dem = 0;
void Nhap(DATHUC& b, double heso, int somu){
    if (dem == 0){
        b.head = b.tail = NULL;
        dem++;
    }
    dem++;
    DONTHUC* x = new DONTHUC;
    x->heso = heso;
    x->somu = somu;
    addTail(b, x);
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

double pow(double x, int n) {
    if (n == 0) {
        return 1.0;
    } else if (n == 1) {
        return x;
    } else if (n < 0) {
        return pow(1.0 / x, -n);
    } else if (n % 2 == 0) {
        double y = pow(x, n / 2);
        return y * y;
    } else {
        double y = pow(x, (n - 1) / 2);
        return x * y * y;
    }
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

int main() {
    DATHUC B;
    int n; cin >> n;
    double heso; int somu;
    for (int i = 0; i < n; i++)
    {
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
