#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n = 0;
    cin >> n;
    char s[300];
    int alphabet[26] = {};
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < n; i ++)
    {
        if (isalpha(s[i]))
        {
            alphabet[tolower(s[i])-97]++;
        }
    }
    int count = 26;
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] > 0)
            count --;
    }
    cout << count;
    return 0;
}
