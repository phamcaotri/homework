#include <bits/stdc++.h>
using namespace std;

bool is_special_word(string s,int begin, int end)
{
    if (begin >= end and not isalpha(s[begin]))
        return false;
    if (not isdigit(s[begin]) and not isdigit(s[end]))
        return true;
    return false;
}

int main()
{
    char s[300];
    cin.getline(s,300);
    int begin = 0, count = 0;
    for (int end = 0; end <= strlen(s); end++)
    {

        if (s[end] == ' ' or end == strlen(s))
        {
            if (is_special_word(s,begin,end-1))
               count ++;
            end++;
            begin = end;
        }

    }
    cout << count;
    return 0;
}
