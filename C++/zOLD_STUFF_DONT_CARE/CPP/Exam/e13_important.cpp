
extern "C" {int printf(const char * fmt,...);
            int scanf(const char * fmt,...);
            int tolower(int);
            int toupper(int);
            };
int main()
{
    char str[200];
    scanf("%[^\n]", str);
    printf("Nhap chuoi = \n");
    printf("s1 =%s\n", str);
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == tolower(str[i]))
            str[i] = toupper(str[i]);
        else
            str[i] = tolower(str[i]);

        if ((tolower(str[i]) < 'a' or tolower(str[i]) > 'z') and (str[i] < '0' or str[i] > '9') and (str[i] != ' '))
        {
            str[i] = '*';
        }
        i++;
    }
    printf("s2 =%s", str);

    return 0;
}