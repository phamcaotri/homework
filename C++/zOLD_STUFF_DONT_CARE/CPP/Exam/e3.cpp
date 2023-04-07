
#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100

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

void NhapmangSNT(int a[],int &n)
{
    cin >> n;
    int i = 2, j = 0;
    while (j != n)
    {
        if (is_prime(i))
        {
            a[j] = i;
            j++;
        }
        i++;
    }
}

void Xuatmang(int a[], int n)
{
    for (int i = 0; i < n ; i++)
    {
        cout << a[i] << ' ';
    }
}

bool is_contain(int n, int y)
{
    while (n != 0)
    {
        if (n%10 == y)
            return true;
        n /=10;
    }
    return false;
}

int SoPhanTuChuaY(int a[], int n, int y)
{
    int count = 0;
    for (int i = 0; i < n ; i++)
    {
        if (is_contain(a[i],y))
            count ++;
    }
    return count;
}



int main()
{
	int a[MAX], n, y;
	cin >>y;
	NhapmangSNT(a,n);
	cout<<"Mang a gom " <<n<<" so nguyen to tang dan, bao gom: \n";
	Xuatmang(a,n);
	cout<<"\nSo phan tu chua chu so "<<y<<": "<<SoPhanTuChuaY(a, n, y);

	return 0;
}
