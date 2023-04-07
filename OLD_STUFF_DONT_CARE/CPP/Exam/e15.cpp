
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

void mahoa(char str)
{
    str = tolower(str);
    cout << str - 96;
}

void MaHoaMatThu(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i+1] == ' ')
        {
            mahoa(s[i]);
            cout << '-';
            i++;
        }
        else if (s[i+1] == '\0')
        {
            mahoa(s[i]);        
        }
        else
        {
            mahoa(s[i]);
            cout << '.';
        }
        i++;
    }
}



int main()
{
    char s[100];
    cin.getline(s,99);
    cout<<"Chuoi vua nhap: "<<s;
    cout<<"\nChuoi sau khi duoc ma hoa: ";
    MaHoaMatThu(s);

    return 0;
}
