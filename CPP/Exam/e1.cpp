

#include <iostream>
using namespace std;

void nhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void xuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
}

void viTriSoAm(int a[], int n)
{
    int index1 = 0, index2 = 0, min = a[0];
    bool have_found_index1 = false, have_found_index2 = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0 and not have_found_index1)
        {
            index1 = i;
            have_found_index1 = true;
        }
        if (a[n-i-1] < 0 and not have_found_index2)
        {
            index2 = n-i-1;
            have_found_index2 = true;
        }
        if (a[i] < min)
        {
            min = a[i];
        }
    }

    if (min >= 0)
    {
        cout << "Mang khong co so am";
        return;
    }
    cout << "Vi tri so am dau tien: " << index1 << '\n';
    cout << "Vi tri so am cuoi cung: " << index2 << '\n';
    cout << "So am nho nhat: " << min ;
    
}
int main()
{
    int n, a[10000];
    cin>>n;
    nhapMang(a,n);
    cout<<"Mang vua nhap:"<<endl;
    xuatMang(a,n);
    cout<<endl;
    viTriSoAm(a,n);

    return 0;
}


