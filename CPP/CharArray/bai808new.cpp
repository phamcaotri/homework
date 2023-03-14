
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);
void ChenChuoiTaiVitriK(char s[], char s1[], int k);

int main()
{
	char s[MAX], s1[MAX];
	fgets(s,MAX,stdin);
	fgets(s1,MAX,stdin);
	int k;
	cin >> k;
	if (k < 0 || k>myStrlen(s, 0))
		cout << "Vi tri " << k << " khong thoa dieu kien." << endl;
	else
	{
    for (int i = 0; i < k ; i++ )
        {
           cout << s[i];
      }
      for (int i = 0; i < myStrlen(s1, 0) ; i++ )
       {
            cout << s1[i];
        }
      for (int i = k; i < myStrlen(s, 0) ; i++ )
       {
           cout << s[i];
       }
           

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
    return length-1;
}