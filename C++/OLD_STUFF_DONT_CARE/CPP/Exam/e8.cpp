#include <iostream>
using namespace std;

void inputMatrix(int a[][50], int &n)
{
    cin >> n;
    for (int hang = 0; hang < n; hang ++)
        for (int cot = 0; cot < n; cot ++)
        {
            cin >> a[hang][cot];
        }
}

void outputMatrix(int a[][50], int n)
{
    for (int hang = 0; hang < n; hang ++)
    {
        for (int cot = 0; cot < n; cot ++)
        {
            cout << a[hang][cot] << " ";
        }
        cout << '\n';
    }
}

int sum(int a[][50], int n)
{
    int Tong = 0;
    for (int hang = 0; hang < n; hang ++)
        for (int cot = 0; cot < n; cot ++)
        {
            if (hang + cot <= n-2)
                Tong += a[hang][cot];
        }
    return Tong;    
}



int main()
{
    int n,a[50][50];
    inputMatrix(a,n);
    cout<<"Matrix:\n";
    outputMatrix(a,n);
    cout<<"Sum = "<<sum(a,n);
    return 0;
}

