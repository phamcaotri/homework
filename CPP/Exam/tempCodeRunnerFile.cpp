bool is_special_word(string s,int begin, int end)
{
    if (begin >= end and not isalpha(s[begin]))
        return false;
    if (not isdigit(s[begin]) and not isdigit(s[end]))
        return true;
    return false;
}