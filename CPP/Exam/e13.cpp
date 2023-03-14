/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
string
###End banned keyword*/
#include <iostream>
#include<cstring>
using namespace std;

void transformString(char s1[], char s2[])
{
    int i = 0;
    do
    {
        s2[i] = s1[i];
        i++;
    } while (s1[i] != '\0');
    s2[i] = s1[i];
    i = 0;
    
    while (s2[i] != '\0')
    {
        if (s2[i] == tolower(s2[i]))
            s2[i] = toupper(s2[i]);
        else
            s2[i] = tolower(s2[i]);

        if ((tolower(s2[i]) < 'a' or tolower(s2[i]) > 'z') and (s2[i] < '0' or s2[i] > '9') and (s2[i] != ' '))
        {
            s2[i] = '*';
        }
        i++;
    }
}
int main()
{
    char s1[200], s2[200];
    cout<<"Nhap chuoi = ";
    cin.getline(s1, 199);
    transformString(s1, s2); //khong dung duoc ham toupper, tolower
    cout<<"\ns1="<<s1<<endl;
    cout<<"s2="<<s2;

    return 0;
}

