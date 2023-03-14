#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300
/*
void Chuanhoa(char *s);

int main()
{
	char *s;
	s = new char[MAX];
	//gets(s);	//Nhap chuoi s	
	cin.getline(s,MAX-1);
	Chuanhoa(s);
	cout << s << endl;
	return 0;
}
*/
void move_left(char *s, int n)
{
    int i = 0;
    while (s[i+n] != '\0')
    {
        s[i+n] = s[i+n+1];
        i++;
    }
}

void Chuanhoa(char *s)
{
    // make all char lowwercase
    for (int i = 0; i < strlen(s); i++)
        s[i] = tolower(s[i]);
    // if there is no blank at the first word, make it upper
    s[0] = toupper(s[0]);
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
        // remove duplicate blank
            if (s[i+1] == ' ')
            {
                move_left(s, i+1);
                i--;
                continue;
            }
        // make first word uppercase
            s[i+1] = toupper(s[i+1]);
        // remove the first blank
            if (i == 0)
            {
                move_left(s, 0);
            }
        // remove the last blank
            if (s[i+1] == '\0')
            {
                move_left(s,i);
            }
        }
    }
}

int main()
{
    char *s;
    s = new char[MAX];
    cin.getline(s, MAX-1);
    Chuanhoa(s);
    cout << s << "\n";
    return 0;
}
