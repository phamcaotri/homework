#include <bits/stdc++.h>
using namespace std;
#define MAX 300

int main()
{
    char s[MAX], s1[MAX];
    int position = 0;
    cin.getline(s, MAX);
    cin.getline(s1, MAX);
    cin >> position;
    if (position < 0 or position > strlen(s))
        {
            cout << "Vi tri " << position << " khong thoa dieu kien.";
            return 0;
        }
    for (int i = 0; i < position ; i++ )
    {
        cout << s[i];
    }
    for (int i = 0; i < strlen(s1) ; i++ )
    {
        cout << s1[i];
    }
    for (int i = position; i < strlen(s) ; i++ )
    {
        cout << s[i];
    }
        
    return 0;
}