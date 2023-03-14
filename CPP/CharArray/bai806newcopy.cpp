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
int myStrcmp(char s1[MAX], char s2[MAX])
{
    if (myStrlen(s1,0)-1 == 0)
        return 0;
    else return 1;
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

void StringReverse(char st[])
{
        string input;
		input = st;
		string output;
		int start = 0;
		for (int i = 0; i < input.length()-1; i++)
		{
			if (input[i] == ' ')
			{
				for (int j = i - 1; j >= start; j--)
				{
					output += input[j];
				}
				output += ' ';
				start = i + 1;
			}
			else if (i == input.length() - 2)
			{
				for (int j = i; j >= start; j--)
				{
					output += input[j];
				}
			}
		}
		for (int i = 0; i < output.length(); i++)
			st[i] = output[i];
}
