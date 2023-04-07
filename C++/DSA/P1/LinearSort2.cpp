
#include <iostream>
using namespace std;

void inputArray(int *&a,int &n)
{
    
    cin >> n;
    int *b = new int[n];
    a = b;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
}


void findElements(int a[], int n, int m)
{
    bool is_find = false;
    cin >> m;
    int *x = new int[m];
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j] == x[i])
            {
                cout << j << '\n';
                is_find = true;
                break;
            } 
               
             
        }
        if (not is_find)
            cout << -1 << '\n';
        else
            is_find = false;
    }
}

int main()
{
    int n,m;
    int *a=NULL;
    inputArray(a,n);
    findElements(a,n,m);

    return 0;
}
