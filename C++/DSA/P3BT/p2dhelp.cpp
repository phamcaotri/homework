#include <iostream>
#include <vector>
#include <utility>
using namespace std;
struct Point
{
    int x, y;
    bool operator<(const Point &p) const
    {
        if (x == p.x)
            return y > p.y;
        return x < p.x;
    }
    bool operator>(const Point &p) const
    {
        if (x == p.x)
            return y < p.y;
        return x > p.x;
    }
    bool operator==(const Point &p) const
    {
        return x == p.x and y == p.y;
    }
};
void nhap(vector<Point> &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
}
void xuat(vector<Point> a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i].x << " " << a[i].y << endl;
    }
}
void merge(vector<Point> &a, int l, int mid, int r)
{
    int i = l, j = mid + 1, k = 0;
    Point temp[r - l + 1];
    while (i <= mid and j <= r)
    {
        if (a[i] < a[j] or a[i] == a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }
    while (j <= r)
    {
        temp[k] = a[j];
        k++;
        j++;
    }
    for (int t = 0; t < k; t++)
    {
        a[l + t] = temp[t];
    }
}

void mergesort(vector<Point> &a, int l, int r)
{

    int mid = (l + r) / 2;
    if (l < mid)
        mergesort(a, l, mid); // mang con 1
    if (r > mid + 1)
        mergesort(a, mid + 1, r); // mang con 2
    merge(a, l, mid, r);
}
int main()
{
    int n;
    cin >> n;
    vector<Point> a(n);
    nhap(a, n);
    mergesort(a, 0, n - 1);
    xuat(a, n);
}