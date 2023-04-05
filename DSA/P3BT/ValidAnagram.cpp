/*
điều kiện cần có để 2 chuỗi là anagram là:
2 chuỗi có cùng số lượng các ký tự, nhưng có thể có thứ tự khác nhau
ví dụ: "anagram" và "nagaram" là anagram
chương trình dưới đây sẽ sắp xếp 2 chuỗi theo thứ tự tăng dần theo bảng mã ASCII, 
sau đó so sánh 2 chuỗi đã sắp xếp này với nhau, 
nếu 2 chuỗi này bằng nhau thì 2 chuỗi là anagram, 
ngược lại thì không phải anagram
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t) {
        return true;
    }
    return false;
}

int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);
    if (isAnagram(s, t)) {
        cout << "IS ANAGRAM";
    }
    else {
        cout << "NOT ANAGRAM!!!";
    }
    return 0;
}