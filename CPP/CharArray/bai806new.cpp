#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

int myStrcmp(char s1[], char s2[]);
int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);
void StringReverse(char st[]);

int main()
{
	char s[MAX];

        fgets(s,MAX,stdin);
        if (myStrcmp(s, "") == 0)
            cout << "Chuoi rong." << endl;
        else
        {
            StringReverse(s);
            cout << s << endl;
        }

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
    return length;
}

void coutTieng(char *p)
{
    int i = 0;
    while (p[i] != ' ' and p[i] != '\n')
    {
        i++;
    }
    p[i] = '\0';
}

int myStrcmp(char s1[MAX], char s2[MAX])
{
    if (myStrlen(s1,0)-1 == 0)
        return 0;
    else return 1;
}


void StringReverse(char st[])
{
    
    char *pointer[2*MAX];
    char s[2*MAX];
    for (int i = 0; i < myStrlen(st,0);i++)
    {
        s[i] = st[i];
    }
    int i = 0, i_ptr = 0;
    // gan pointer vao cac tieng cua mang
    while (s[i] != '\n')
    {
        if ((s[i-1] == ' ' or i == 0) and s[i] != ' ' )
        {
            pointer[i_ptr] = &s[i];
            i_ptr ++;
        }

        i++; 
    }

    int j = 0, p_length = 0;
    for (int i = 0; i < i_ptr; i++)
    {
        coutTieng(pointer[i]);
        p_length += myStrlen(pointer[i],0);
        
        for(int k = 0; k < myStrlen(pointer[i],0); k++)
        {
            st[j] = s[p_length -1-k];
            j++;

        }  
        j++;
        p_length ++;

        
    }
    


}
