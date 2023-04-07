#include <iostream>
using namespace std;

void nhapMaTran(int a[][100], int n, int m)
{
    for (int cot = 0; cot < m; cot ++)
        for (int hang = 0; hang < n; hang ++)
        {
            cin >> a[hang][cot];
        }
}

void xuatMaTran(int a[][100], int n, int m)
{
    cout << "Ma tran A(" << n << "x" << m <<") da nhap:" << '\n';
    for (int hang = 0; hang < n; hang ++)
    {
        for (int cot = 0; cot < m; cot ++)
        {
            cout << a[hang][cot] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    int a[100][100], n, m;
    cin>>n>>m; //n: so dong, m: so cot
    nhapMaTran(a,n,m); //nhap theo thu tu tung cot: nhap cot 0 truoc, roi den cot 1, 2, ...
    xuatMaTran(a,n,m);
    return 0;
}

