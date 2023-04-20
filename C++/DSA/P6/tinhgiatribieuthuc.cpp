#include <stack>
#include <queue>
#include <iostream>
#include <string>
using namespace std;

int main() {
    queue<string> queue;
    stack<string> s, s3;
    stack<float> s2;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i ++) {
        if (isdigit(str[i]))
            queue.push(string(1, str[i]));
        else {
            while (!s.empty()) {
                if ((str[i] == '+' or str[i] == '-') and (s.top() == "*" or s.top() == ":")) {
                    queue.push(s.top());
                    s.pop();
                } else {
                    break;
                }
            }
            s.push(string(1, str[i]));

            // while (!s3.empty()) {
            //     s.push(s3.top());
            //     s3.pop();
            // }
        }
    }
    while (!s.empty()) {
        queue.push(s.top());
        s.pop();
    }

    while (!queue.empty()) {
        while (!queue.empty() and (queue.front() != "+" and queue.front() != "-" and queue.front() != "*" and queue.front() != ":")) {
            
            s2.push(stof(queue.front()));
            queue.pop();

        }
        float temp1 = s2.top();
        s2.pop();
        float temp2 = s2.top();
        s2.pop();
        if (queue.front() == "+") {
            s2.push(temp1 + temp2);
        }
        if (queue.front() == "-") {
            s2.push(temp2 - temp1);
        }
        if (queue.front() == "*") {
            s2.push(temp1 * temp2);
        }
        if (queue.front() == ":") {
            s2.push(temp2 / temp1);
        }
        queue.pop();
    }


    cout <<s2.top();
    
    return 0;
}
