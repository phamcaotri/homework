
#include <iostream>
using namespace std;

int input(int a[], int &m)
{
    int i = 0;
    do
    {
        cin >> a[i];
        i++;
    }
    while (a[i-1] != -1);
    cin >> m;
    return i-1;
}

void output(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
}

int count_even(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
            count ++;
    }
    return count;
}

void delete_even(int a[], int n, int m)
{
    bool have_cout = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0 and m > 0)
        {
            m--;
            continue;   
        }
        cout << a[i] << ' ';
        have_cout = true;
    }
    if (have_cout == false)
        cout << "Empty";
}
int main()
{
    int a[100], m = 0;
    int n = input(a, m);
    cout << "Before:";
    output(a,n);
    cout << '\n';
    if (m == 0)
    {
        cout << "No deletion required";
        return 0;
    }
    if (count_even(a,n) == 0)
    {
        cout << "There are no even numbers in the array";
        return 0;
    }
    if (count_even(a,n) < m)
    {
        cout << "Not enough " << m << " even numbers but still delete" << '\n' << "After:";
        delete_even(a,n,count_even(a,n));
        return 0;
    }
    if (count_even(a,n) >= m)
    {
        cout << "After:";
        delete_even(a,n,m);
        return 0;
    }



}

