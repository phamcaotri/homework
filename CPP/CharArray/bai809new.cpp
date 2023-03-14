
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 255

int myStrcmp(char s1[], char s2[]);

int main()
{
	char s1[MAX], s2[MAX];
	fgets(s1,MAX,stdin);
	fgets(s2,MAX,stdin);
	int kt = myStrcmp(s1, s2);
	cout << kt << endl;
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

int myStrcmp(char s1[], char s2[])
{
    if  (myStrlen(s1) < myStrlen(s2))
        return -1;
    if (myStrlen(s1) > myStrlen(s2))
        return 1;
    for (int i = 0; i < myStrlen(s1); i++)
    {
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return 1;
    }
    return 0;
}