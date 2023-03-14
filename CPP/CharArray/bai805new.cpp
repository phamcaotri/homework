#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

void DemTieng(char s1[]);
int myStrcmp(char s1[], char s2[]);
int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void myMemmove(char s[], int vt, int k);
int myStrstr(char s[], char s1[]);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);

int main()
{
	char s[MAX];
	fgets(s,MAX,stdin);
	if (myStrcmp(s, "") == 0)
		cout << "Chuoi rong." << endl;
	else
		DemTieng(s);
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

int myStrcmp(char s1[MAX], char s2[MAX])
{
    if (myStrlen(s1,0)-1 == 0)
        return 0;
    else return 1;
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
int compare(char s1[], char s2[])
{
    for(int i = 0; i < max(myStrlen(s1, 0), myStrlen(s2,0)); i++)
    {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}

void DemTieng(char s[])
{
    char *pointer_of_s[MAX];
    int i = 0, i_ptr = 0;
    while (s[i] != '\n')
    {
        if ((s[i-1] == ' ' or i == 0) and s[i] != ' ' )
        {
            pointer_of_s[i_ptr] = &s[i];
            i_ptr ++;
        }
        i++;

    }
    for (i = 0; i < i_ptr ; i++)
    {
        coutTieng(pointer_of_s[i]);
    }
    for (i = 0; i < i_ptr ; i++)
    {
        if (pointer_of_s[i] != NULL)
        {    
            char *p = pointer_of_s[i];
            int tan_so = 0;
            for (int j = 0; j < i_ptr; j++)
            {
                if (pointer_of_s[j] == NULL)
                    continue;

                if( compare(p ,pointer_of_s[j]) == 1)
                {
                    tan_so ++;
                    if (tan_so > 1)
                        pointer_of_s[j] = NULL;
                }
            }
            cout << p << ": " << tan_so << "\n";
        }
    }

}

