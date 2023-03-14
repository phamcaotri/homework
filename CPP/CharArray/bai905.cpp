#include <iostream>
#include <string.h>
using namespace std;
#define MAX 255

int myStrlen(char *s);
char* myStrcat(char *s1, char *s2);

int main()
{
	char *s1 = NULL, *s2 = NULL;
	s1 = new char[MAX];
	s2 = new char[MAX];
	//gets(s1);
	//gets(s2);
	cin.getline(s1, MAX-1);
	cin.getline(s2, MAX-1);	
	char *s = myStrcat(s1, s2);
	puts(s);
	return 0;
}

int myStrlen(char *s)
{
    int length = 0, i = 0;
    while (s[i] != '\0')
    {
        length ++;
        i ++;
    }
    return length;
}

char* myStrcat(char *s1, char *s2)
{
    char *s = new char[2*MAX];
    int i = 0;
    for (; i < myStrlen(s1); i++)
        s[i] = s1[i];
    for (int j = 0; j < myStrlen(s2); j++)
        s[j+i] = s2[j];    

    return s;
}