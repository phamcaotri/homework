#include <iostream>
using namespace std;

void inputMatrix(int a[][50], int &n, int &m)
{
    cin >> n >> m;
    for (int hang = 0; hang < n; hang ++)
    {
        for (int cot = 0; cot < m; cot ++)
        {
            cin >> a[hang][cot];
        }
    }
}


void outputMatrix(int a[][50], int n, int m)
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

void uniqueElements(int a[][50], int n, int m)
{

    int max = a[0][0];
    for (int hang = 0; hang < n; hang ++)
    {
        for (int cot = 0; cot < m; cot ++)
        {
            if (max < a[hang][cot])
                max = a[hang][cot];
        }
    }
    int unique_num_array[max+1] = {};
    int count = 0;
    for (int hang = 0; hang < n; hang ++)
    {
        for (int cot = 0; cot < m; cot ++)
        {
            unique_num_array[a[hang][cot]]++;
        }
    }
    for (int i = 0; i <= max; i++)
    {
        if (unique_num_array[i] == 1)
            count ++;
    }
    if (count == 0)
    {
        cout << "No unique element in the matrix";
        return;
    }
    else
    {
        cout << "Unique elements in the matrix:" << '\n';
        for (int i = 0; i <= max; i++)
        {
            if (unique_num_array[i] == 1)
                cout << i << ' ';
        }
    }



}

int main()
{
    int m,n,a[50][50];
    inputMatrix(a,n,m);
    cout<<"Matrix:\n";
    outputMatrix(a,n,m);
    uniqueElements(a,n,m);
    return 0;
}