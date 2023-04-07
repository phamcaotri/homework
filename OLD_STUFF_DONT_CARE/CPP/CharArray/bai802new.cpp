
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

void ChenChuoiTaiVitriK(char s[], char s1[], int k);
void Chuanhoa(char s[]);
int myStrlen(char s[], int k);
bool myStrcat(char s[], char s1[], char s2[]);
void myStrcpy(char s[], int vt, char s1[], int k);
int myStrstr(char s[], char s1[]);


int main()
{
	char s[MAX];

	fflush(stdin);
	fgets(s,MAX,stdin);

	char s1[MAX];
	myStrcpy(s1, 0, s, 0);
	Chuanhoa(s1);
	cout << s << endl << s1 << endl;
	return 0;
}

void myStrcpy(char s[], int vt, char s1[], int k)
{
    for (int i = 0; i < 300; i++)
        s[i] = s1[i];
}

void move_left(char s[], int n)
{
    int i = 0;
    while (s[i+n] != '\0')
    {
        s[i+n] = s[i+n+1];
        i++;
    }

}
void insert(char *s, int n)
{
    char s_temp1[MAX];
    int i = 0;
    while (s[i+n] != '\0')
    {
        s_temp1[i] = s[i+n+1];
        i++;
    }
    s[n+1] = ' ';
    i = 0;
    do
    {
        s[i+n+2] = s_temp1[i];
        i++;
    }while (s_temp1[i-1] != '\0');
    

}

void Chuanhoa(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        {
            if (s[i] == '.')
            {
                

                while (s[i-1] == ' ')
                {
                    move_left(s, i-1);
                    i--;
                    
                }
                if (s[i+1] != '\0')
                {
                    insert(s,i);
                }
                i++;

            }
        }
        i ++;
    }
    
    bool check = true;
    i = 0;
    while (check)
    {
        if (s[300-i] != '.')
        {
            s[300-i] = '\0';
            i++;
            
        }
        else check = false;
            
    }
}