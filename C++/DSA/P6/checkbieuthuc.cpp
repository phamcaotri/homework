#include <stack>
#include <iostream>
#include <string>
using namespace std;

bool isValid(stack<char> S, string str) {
    for (int i = 0; i < str.size(); i ++) {
        if (str[i] == '(' or str[i] == '[' or str[i] == '{')
            S.push(str[i]);
        else if (str[i] != ')' and str[i] != ']' and str[i] != '}')
            continue;
        else {
            if (S.empty())
                return false;
            else if (str[i] == ')' and S.top() != '(')
                return false;
            else if (str[i] == ']' and S.top() != '[')
                return false;
            else if (str[i] == '}' and S.top() != '{')
                return false;
            else
                S.pop();
        }
    }
    return S.empty();
}


int main() {
    stack<char> S;
    string str;
    cin >> str;
    if (isValid(S,str))
        cout << "1";
    else
        cout << "0";
    return 0;
}