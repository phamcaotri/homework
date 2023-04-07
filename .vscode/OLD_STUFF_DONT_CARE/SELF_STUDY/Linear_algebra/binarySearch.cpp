binarySearch(int a[], int n, int x)
{
    int l = 0, r = n-1, mid = (l+r)/2;

while (l <= r)
{
    if (a[mid] == x) return mid;
    else if (a[mid] < mid) l = mid +1;
    else r = mid -1;
}
return -1;

}