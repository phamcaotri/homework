#include <iostream>
using namespace std;

void inputArray(int a[][100], int n, int m)
{
    for (int hang = 0; hang < n; hang ++)
    {
        for (int cot = 0; cot < m; cot ++)
        {
            cin >> a[hang][cot];
        }
    }
}

void outputArray(int a[][100], int n, int m)
{
    for (int hang = 0; hang < n; hang ++)
    {
        for (int cot = 0; cot < m; cot ++)
        {
            cout << a[hang][cot] << ' ';
        }
        cout << '\n';
    }
}

void horizontal_invert(int a[][100], int n, int m)
{
    for (int hang = 0; hang < n/2; hang ++)
    {
        for (int cot = 0; cot < m; cot ++)
        {
            swap(a[hang][cot],a[n - hang - 1][cot]);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int a[100][100];

    inputArray(a, n, m);

    horizontal_invert(a, n, m);

    outputArray(a, n, m);

    return 0;
}
