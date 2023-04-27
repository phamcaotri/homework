#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

const unordered_map<string, int> OPERATOR = {
    {"+", 1},
    {"-", 1},
    {"*", 2},
    {"/", 2},
    {"^", 3},
    {"(", 0},
    {")", 0},
    {" ", 0},
    {"", 0}
};

class StringCal {
    private:
        vector<string> input_string;
        queue<string> main_line;
        stack<string> temp_line;
    public:
        void input() {
            string str;
            cin >> str;
            for (int i = 0; i < str.length(); i++) {
                if (isdigit(str[i]) ) {
                    string temp = "";
                    while (i < str.length() && isdigit(str[i])) {
                        temp += str[i];
                        i++;
                    }
                    input_string.push_back(temp);
                }
                input_string.push_back(string(1, str[i]) );
            }

        }
        bool is_digit(string s) {
            for (auto i : s) {
                if (!isdigit(i) )
                    return false;
            }
            return true;
        }
        void temp_to_main(string s) {
            while (!temp_line.empty() and temp_line.top() != "(" and OPERATOR.at(temp_line.top() ) >= OPERATOR.at(s) ) {
                main_line.push(temp_line.top());
                temp_line.pop();
            }
        }
        void to_main() {
            for (string s : input_string) {
                if (s == " " or s == "") // bước 1: bỏ qua khoảng trắng
                    continue;
                if (s == "(") { // bước 2: nếu là dấu mở ngoặc thì đẩy vào temp_line
                    temp_line.push("(");
                    continue;
                }
                if (s == ")") { // bước 3: nếu là dấu đóng ngoặc thì đẩy tất cả từ temp_line vào main_line cho đến khi gặp dấu mở ngoặc
                    temp_to_main(s);
                    temp_line.pop(); // pop "("
                    continue;
                }
                if (is_digit(s)) { // bước 4: nếu là toán hạng thì đẩy vào main_line
                    main_line.push(s);
                    continue;
                }
                if (OPERATOR.find(s) != OPERATOR.end() ) { // bước 5: nếu là toán tử thì đẩy vào temp_line
                    if (temp_line.empty() ) { // nếu temp_line rỗng thì đẩy vào
                        temp_line.push(s);
                        continue;
                    }
                    if (OPERATOR.at(s) > OPERATOR.at(temp_line.top() ) ) { // nếu toán tử đang xét có độ ưu tiên cao hơn toán tử trên đỉnh temp_line thì đẩy vào
                        temp_line.push(s);
                        continue;
                    }
                    if (OPERATOR.at(s) <= OPERATOR.at(temp_line.top() ) ) { // nếu toán tử đang xét có độ ưu tiên thấp hơn toán tử trên đỉnh temp_line thì đẩy tất cả từ temp_line vào main_line cho đến khi gặp toán tử có độ ưu tiên thấp hơn
                        temp_to_main(s);
                        temp_line.push(s);
                        continue;
                    }
                }

            }
            temp_to_main(" "); // bước 6: đẩy tất cả từ temp_line vào main_line
        }

        bool is_valid_input() {
            for (string s : input_string) {
                if (is_digit(s)) {
                    continue;
                }
                if (OPERATOR.find(s) != OPERATOR.end() ) {
                    continue;
                }
                return false;
            }
            return true;
        }

        bool have_valid_bracket() {
            int count = 0;
            for (string s : input_string) {
                if (s == "(") {
                    count++;
                }
                if (s == ")") {
                    count--;
                }
                if (count < 0) {
                    return false;
                }
            }
            if (count == 0) {
                return true;
            }
            return false;
        }
        double calculate() {
            if (!is_valid_input() or !have_valid_bracket()) {
                cout << "Error: invalid input" << endl;
                return 0;
            }
            to_main();
            stack<double> temp;
            while (!main_line.empty() ) {
                string s = main_line.front();
                main_line.pop();
                if (is_digit(s)) {
                    temp.push(stod(s));
                }
                if (OPERATOR.find(s) != OPERATOR.end() ) {
                    double a = temp.top();
                    temp.pop();
                    double b = temp.top();
                    temp.pop();
                    if (s == "+") {
                        temp.push(a + b);
                    }
                    if (s == "-") {
                        temp.push(b - a);
                    }
                    if (s == "*") {
                        temp.push(a * b);
                    }
                    if (s == "/") {
                        // xử lý ngoại lệ chia cho 0
                        if (a == 0) {
                            cout << "Error: divide by zero" << endl;
                            return 0;
                        }
                        temp.push(b / a);
                    }
                    if (s == "^") {
                        temp.push(pow(b, a) );
                    }
                }
            }
            return temp.top();
        }
};

int main() {
    while (true) {
        StringCal s;
        s.input();
        cout << fixed << s.calculate() << endl;
    }
    return 0;
}