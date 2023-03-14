#include <iostream>
#include <cstring>
using namespace std;

int DemSoKyTu(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

int DemSoKyTuNguyenAm(char s[])
{
    int i = 0, count = 0;
    while (s[i] != '\0')
    {
        
        if (tolower(s[i]) == 'a' or tolower(s[i]) == 'i' or tolower(s[i]) == 'e' or tolower(s[i]) == 'o' or tolower(s[i]) == 'u')
        {
            count ++;
        }
        i++;
    }
    return count;
}

int DemSoKyTuPhuAm(char s[])
{
    int i = 0, count = 0;
    while (s[i] != '\0')
    {
        
        if ((tolower(s[i]) >= 'a' and tolower(s[i]) <= 'z' ) and not (tolower(s[i]) == 'a' or tolower(s[i]) == 'i' or tolower(s[i]) == 'e' or tolower(s[i]) == 'o' or tolower(s[i]) == 'u'))
        {
            count ++;
        }
        i++;
    }
    return count;
}

int main()
{
    char s[100];
    cin.getline(s,99);
    cout<<"Chuoi vua nhap: "<<s;
    cout<<"\nSo ky tu trong chuoi (tru \'\\0\'): "<<DemSoKyTu(s);
    cout<<"\nSo ky tu nguyen am: "<<DemSoKyTuNguyenAm(s);
    cout<<"\nSo ky tu phu am: "<<DemSoKyTuPhuAm(s);
    return 0;
}
