#include <iostream>
using namespace std;
#define MAX 300

int str_length(char str[])
{
    int length = 0, i = 0;
    while (str[i] != '\0')
    {
        length ++;
        i ++;
    }
    return length;
}  

int main()
{
    char str[MAX];
    cin.getline(str, MAX);
    for (int i = 0; i < str_length(str) ; i++ )
    {
        if (str[i] == '0' or str[i] == '1' or str[i] == '2' or str[i] == '3' or str[i] == '4' or str[i] == '5' or str[i] == '6' or str[i] == '7' or str[i] == '8' or str[i] == '9')
            {
                cout << "CHUOI KHONG HOP LE.";
                return 0;
            }
    }
    for (int i = 0; i < str_length(str) ; i++)
        cout << str[i];
    return 0;
}