
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

void myStrcpy(char s[], int vt, char s1[], int k)
{
    s1[myStrlen(s1, 0)-1] = '\0';
    for (int i = 0; i < myStrlen(s1, 0); i++)
        s[i] = s1[i];
}

void move_left(char s[], int n)
{
    int i = 0;
    do
    {
        s[i+n] = s[i+n+1];
        i++;
    }while (s[i+n] != '\0');

}
void insert(char s[], int n, int &newstrlen)
{
    char s_temp1, s_temp2;
    int i = 0;

        s_temp1 = s[i+n+1];
        s[i+n+1] = ' ';
        do
        {   
            s_temp2 = s[i+n+2];
            s[i+n+2] = s_temp1;
            s_temp1 = s[i+n+3];
            i++;
        }while (s[i+n+2] != '\0');
        s_temp2 = s[i+n+2];
        s[i+n+2] = s_temp1;
        s[i+n+3] = s_temp2;
        newstrlen++;


}

void Chuanhoa(char s[])
{
    int newstrlen = myStrlen(s,0);
    int i = 0, n = 1;
    while (s[i] != '\0')
    {
        {
            if (s[i] == '.')
            {
                while (s[i+1] == ' ')
                {
                    move_left(s, i+1);

                }
                while (s[i-1] == ' ')
                {
                    move_left(s, i-1);
                }
            //insert(s, i, newstrlen);
                i++;

            }
        }
        i ++;
    }
}