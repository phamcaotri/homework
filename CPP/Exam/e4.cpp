
#include <iostream>

using namespace std;

void inputArray(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';
}

int mid(int n)
{
    if (n % 2 == 0)
        return n/2;
    else
        return (n+1)/2;
}

void reverseArray(int a[], int n)
{
    int middle = a[mid(n) -1];
    int i = 0, j = n-1;
    while (i < j)
    {
        while (a[i] < middle)
        {
            i++;
        }
        while (a[j] > middle)
        {
            j--;
        }
        swap(a[i], a[j]);
        if (a[i] == a[j])
        {
            i++;
            j--;
        }
    }
}

int main()
{
    int a[100],n;
    inputArray(a,n);

    // In mang ban dau
    printArray(a, n);

    //Dao mang
    reverseArray(a, n);

    // In mang sau khi dao
    cout << "Reversed array is" << endl;
    printArray(a, n);

    return 0;
}
