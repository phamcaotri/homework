#include <iostream>
#include <string.h>
using namespace std;

struct POINT
{
    int x;
    int y;
    int z;
};

struct POLYGON
{
    POINT a[100];
};

void input(POLYGON &p, int &n)
{
    cin >> n;
    for (int i = 0; i < n ; i++)
    {
        cin >> p.a[i].x >> p.a[i].y >> p.a[i].z;
    }
}
int main()
{
    
    POLYGON p;
    int n;
    input(p, n);
    for (int i = 0; i < n ; i++)
    {
        cout << p.a[i].x << ' ' << p.a[i].y << ' ' << p.a[i].z << '\n';
    }
return 0;
}