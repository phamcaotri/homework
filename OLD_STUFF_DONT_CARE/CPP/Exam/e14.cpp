
#include <iostream>
#include<cstring>

using namespace std;

int SoSanhBangNhauCongSo(char s[],char t[])
{
    if(strlen(s) != strlen(t))
        return 0;
    int i = 0;
    while (s[i] != '\0')
    {
        if (isdigit(s[i]) and not isdigit(t[i]))
           return 0;
        if (not isdigit(s[i]) and isdigit(t[i]))
           return 0;
        if ((isdigit(s[i]) and isdigit(t[i])) and not ((s[i]-48) + (t[i]-48) == 10))
           return 0;
        if ((tolower(s[i]) >= 'a' and tolower(s[i]) <= 'z') and not (tolower(t[i]) >= 'a' and tolower(t[i]) <= 'z'))
            return 0;
        if (not (tolower(s[i]) >= 'a' and tolower(s[i]) <= 'z') and (tolower(t[i]) >= 'a' and tolower(t[i]) <= 'z'))
            return 0;
        i++;
    }

    return 1;
}
int main()
{
    char s[256], t[256];
    cin.getline(s,256);
    cin.getline(t,256);
    cout<<SoSanhBangNhauCongSo(s,t);//cung la so va cong lai bang 10, cung la chu cai

    return 0;
}
