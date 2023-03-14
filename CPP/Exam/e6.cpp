#include <iostream>
using namespace std;

void inputArray(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

bool is_prime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    
    for (int i = 2 ; i < num; i ++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
    
}

void insertIntoArray(int a[],int n)
{
    bool is_inserted = false;
    for (int i = 0; i < n; i++)
    {
        if (is_prime(a[i]))
        {
            cout << a[i] + 1 << ' ' <<a[i] << ' ';
            is_inserted = true;
        }
        else
        {
            cout << a[i] << ' ';
        }
    }
    if (is_inserted)
    {
        cout << '\n';
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (is_prime(a[i]))
            {
                cout << i+j << ' ';
                j++;
            }

        }
    }
    

}

int main()
{
    int a[100],n;
    inputArray(a,n);
    insertIntoArray(a,n);

    return 0;
}


