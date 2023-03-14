
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
#define MAX 255

int myStrlen(char s[]);
bool myStrcat(char s1[], char s2[]);

int main()
{
	char s1[MAX], s2[MAX];
	 
         fgets(s1,MAX,stdin);
	 fgets(s2,MAX,stdin);
	bool kt = myStrcat(s1, s2);
    if (kt)
    {
        for (int i = 0; i < myStrlen(s1)-1; i++)
            cout << s1[i];
        cout << s2;
    }
    else cout << "Khong noi duoc. Khong du bo nho.";
    return 0;
}

int myStrlen(char s[])
{
    int length = 0, i = 0;
    while (s[i] != '\0')
    {
        length ++;
        i ++;
    }
    return length;
}

bool myStrcat(char s1[], char s2[])
{
    char *s = new char[2*MAX];
    int i = 0;
    for (; i < myStrlen(s1); i++)
        s[i] = s1[i];
    for (int j = 0; j < myStrlen(s2); j++)
        s[j+i] = s2[j];    
    if (myStrlen(s1) > 255 or myStrlen(s2) > 255 or myStrlen(s) > 255)
        return false;
    return true;
}





