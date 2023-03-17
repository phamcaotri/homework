
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int  vitrung(int n) {
    if (n == 0)
        return 2;
    return 2*vitrung(n-1);
}
int goitien(int n) {
    if (n == 1)
        return 1120;
    return 1.12*goitien(n-1);
}

long long giaithua(int n) {
    if (n <= 1)
        return 1;
    return n*giaithua(n-1);
}

int fibo(int n) {
    if (n  <= 1)
        return 1;
    return fibo(n-1) + fibo(n-2);
}

double luythua(float x, int n) {
    if (n == 0)
        return 1;
    return x*luythua(x,n-1);
}

int ucln_tru(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a < b)
        return ucln_tru(a,b-a);
    else
        return ucln_tru(a-b,b);
}

int ucln_du(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    return ucln_du(b,a%b);
}

int tohop(int n, int k) {

    if (k == 0 or n == k)
        return 1;
    if (n < k or k < 0)
        return 0;

    return tohop(n-1,k) + tohop(n-1,k-1);
}
int main()
{

    int n;
    cout<<"Nhap n: "<<endl;
    cin>>n;
    cout<<"Sau "<<n<<" gio co "<<vitrung(n)<<" con vi trung"<<endl;
    cout<<"Sau "<<n<<" nam, so tien co duoc: "<<goitien(n)<<endl;
    cout<<n<<"!: "<<giaithua(n)<<endl;
    cout<<"Fibo("<<n<<"): "<<fibo(n)<<endl;

    cout<<"Nhap x: "<<endl;
    float x; cin>>x;
    cout<<x<<" luy thua "<<n<< ": "<<setprecision(15)<<luythua(x,n)<<endl;

    cout<<"Nhap a va b: "<<endl;
    int a, b; cin>>a>>b;
    cout<<"Uoc chung lon nhat cua "<<a<<" va "<<b<<": ";
    cout<<ucln_tru(a,b)<<" "<<ucln_du(a,b)<<endl; // Tim UCLN su dung phep chia du hoac phep tru


    cout<<"Nhap k: "<<endl;
    int k; cin>>k;
    cout<<"So luong to hop chap "<<k<<" cua "<<n<<" phan tu: "<<tohop(n,k);


    return 0;
}
