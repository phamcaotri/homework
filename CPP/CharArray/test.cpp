#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    getline(cin, s);

    if (s.empty()) {
        cout << "Chuoi rong." << endl;
        return 0;
    }

    string result;
    string word;
    for (char c : s) {
        if (c == ' ') {
            reverse(word.begin(), word.end());
            result += word + " ";
            word.clear();
        } else {
            word += c;
        }
    }
    reverse(word.begin(), word.end());
    result += word;

    cout << result << endl;
    return 0;
}