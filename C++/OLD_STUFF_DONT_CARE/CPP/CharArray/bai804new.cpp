#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

void DemKyTu(char s[]);
int myStrcmp(char s1[MAX], char s2[MAX]);
int myStrlen(char s[], int k);

int main()
{
	char s[MAX];
	fgets(s,MAX,stdin);	//Nhap chuoi s	
	if (myStrcmp(s, "") == 0)
		cout << "Chuoi rong." << endl;
	else
		DemKyTu(s);

	return 0;
}

int myStrlen(char s[], int k)
{
    int length = 0, i = 0;
    while (s[i] != '\0')
    {
        length ++;
        i ++;
    }
    return length-1;
}

int myStrcmp(char s1[MAX], char s2[MAX])
{
    if (myStrlen(s1,0) == 0)
        return 0;
    else return 1;
}
int TanSoXuatHien(char s_i, char *s)
{
    int tan_so = 0, i = 0;
    while (s[i] != '\n')
    {
        if (s[i] == s_i)
        {
            tan_so ++;
            s[i] = '\1';
        }    
        i++;
    }
    return tan_so;
}
void DemKyTu(char s[])
{
    int i = 0;
    while (s[i] != '\n')
    {
        if (s[i] != '\1')
            cout << s[i] << ": " << TanSoXuatHien(s[i], s) << "\n";
        i++;
    }
}

