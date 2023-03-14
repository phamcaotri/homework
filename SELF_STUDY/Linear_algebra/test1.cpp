
#include <iostream>
using namespace std;
int main()
{
    int n = 0, m = 0, x = 0;
    bool is_find = false;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == x)
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




    return 0;
}
