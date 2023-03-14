
#include <iostream>

using namespace std;
//Goi y: SV co the viet cac ham sau

long long Factorial (int n); // tinh n!
int isFactorial (int n); // kiem tra n co phai la 1 so giai thua hay khong, nghia la co 1 con so i sao cho i!=n
int isTotalFactorial(int a[], int n); //kiem tra mang co phai chua toan so giai thua hay khong

void inputArray(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void outputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
}

long long Factorial (int n)
{
    if (n == 0)
        return 1;
    long long Factor = 1;
    for (int i = 1; i <= n; i++)
    {
        Factor *= i;
    }
    return Factor;
}

int isFactorial (int n)
{
    if (n == 1 or n == 2)
        return 1;
    int i = 2, j = 1;
    while (i < n and n/j >= 1)
    {
        if (n / j == 1)
        {
            return 1;
        }
        
        
        j *= i;
        i ++;
    }
    
    return 0;

}

int isTotalFactorial(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (isFactorial(a[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}

int maxFactorial(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}
int main()
{
    int n, a[100];
    inputArray(a,n);
    cout<<"Array:"<<endl;
    outputArray(a,n);
    cout<<endl;

    if (isTotalFactorial (a,n)==1)
    {
        cout <<"Mang toan so giai thua"<<endl;
        cout << "So giai thua lon nhat: "<<maxFactorial (a,n);
    }
    else cout<<"Mang khong phai chua toan cac so giai thua";

    return 0;
}

