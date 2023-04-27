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
    {" ", 0}
};

class MyString {
    private:
        string str;
    public:
        MyString() {
            str = "";
        }
        MyString(string s) {
            str = s;
        }
        MyString(char c) {
            str = c;
        }
        MyString(const char* c) {
            str = c;
        }
        bool is_digits() const {
            for (auto i : str) {
                if (!isdigit(i) )
                    return false;
            }
            return true;
        }
        bool is_operator() const {
            return OPERATOR.find(str) != OPERATOR.end();
        }
        bool is_empty() const {
            return str == "";
        }
        int get_priority() const {
            return OPERATOR.at(str);
        }
        void clear() {
            str = "";
        }
        int length() const {
            return str.length();
        }
        int to_int() const {
            return stoi(str);
        }
        char& operator[](int i) {
            return str[i];
        }
        friend istream& operator>>(istream& is, MyString& s) {
            getline(is, s.str, '\n');
            return is;
        }
        MyString& operator=(MyString s) {
            str = s.str;
            return *this;
        }
        MyString& operator+=(char c) {
            str += c;
            return *this;
        }
        bool operator==(string s) {
            return str == s;
        }
        bool operator!=(string s) {
            return str != s;
        }

};

class StringCal {
    private:
        vector<MyString> input_string;
        queue<MyString> main_line;
        stack<MyString> temp_line;
    public:
        void input() {
            MyString str;
            MyString temp;
            cin >> str;
            for (int i = 0; i < str.length(); i++) {
                if (str[i] == ' ') {
                    if (!temp.is_empty()) {
                        input_string.push_back(temp);
                        temp.clear();
                    }
                    continue;
                }
                if (isdigit(str[i]) ) {
                    temp += str[i];
                    if (i == str.length() - 1) {
                        input_string.push_back(temp);
                        continue;
                    } else
                        continue;
                }
                if (!temp.is_empty()) {
                    input_string.push_back(temp);
                    temp.clear();
                }
                input_string.push_back(str[i]);
            }

        }
        void temp_to_main(MyString s) {
            while (!temp_line.empty() and temp_line.top() != "(" and temp_line.top().get_priority() >= s.get_priority() ) {
                main_line.push(temp_line.top());
                temp_line.pop();
            }
        }
        void to_main() {
            for (MyString s : input_string) {
                // if (s == " ") // bước 1: bỏ qua khoảng trắng. note: không cần thiết vì đã xử lý ở hàm input()
                //     continue;
                if (s == "(") { // bước 2: nếu là dấu mở ngoặc thì đẩy vào temp_line
                    temp_line.push("(");
                    continue;
                }
                if (s == ")") { // bước 3: nếu là dấu đóng ngoặc thì đẩy tất cả từ temp_line vào main_line cho đến khi gặp dấu mở ngoặc
                    temp_to_main(s);
                    temp_line.pop(); // pop "("
                    continue;
                }
                if (s.is_digits()) { // bước 4: nếu là toán hạng thì đẩy vào main_line
                    main_line.push(s);
                    continue;
                }
                if (s.is_operator()) { // bước 5: nếu là toán tử thì đẩy vào temp_line
                    if (temp_line.empty() ) { // nếu temp_line rỗng thì đẩy vào
                        temp_line.push(s);
                        continue;
                    }
                    if (s.get_priority() > temp_line.top().get_priority() ) { // nếu toán tử đang xét có độ ưu tiên cao hơn tử trên đỉnh temp_line thì đẩy vào
                        temp_line.push(s);
                        continue;
                    } else { // nếu toán tử đang xét có độ ưu tiên thấp hơn hoặc bằng toán tử trên đỉnh temp_line thì đẩy tất cả từ temp_line vào main_line cho đến khi gặp toán tử có độ ưu tiên thấp hơn
                        temp_to_main(s);
                        temp_line.push(s);
                        continue;
                    }
                }

            }
            temp_to_main(" "); // bước 6: đẩy tất cả từ temp_line vào main_line
        }

        bool is_valid_input() {
            bool have_number = false;
            MyString temp_syntax;
            for (MyString s : input_string) {
                //input không nằm trong danh sách cho phép
                if (!s.is_digits() and !s.is_operator())
                    return false;
                if (s.is_digits())
                    have_number = true;
                // input có 2 toán tử liên tiếp
                if (s.is_operator() and s != "(" and s != ")") {
                    if (temp_syntax.is_operator() ) {
                        return false;
                    }
                    temp_syntax = s;
                } else {
                    temp_syntax.clear();
                }
            }
            // input không có số
            if (!have_number)
                return false;
            return true;
        }

        bool have_valid_bracket() {
            int count = 0;
            for (MyString s : input_string) {
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
        double binary_cal(double a, double b, MyString s) {
            if (s == "+") {
                return a + b;
            }
            if (s == "-") {
                return b - a;
            }
            if (s == "*") {
                return a * b;
            }
            if (s == "/") {
                if (a == 0) {
                    cout << "Error: divide by zero" << endl;
                    return 0;
                }
                return b / a;
            }
            return 0;
        }
        double unary_cal(double a, MyString s) {
            if (s == "+") {
                return a;
            }
            if (s == "-") {
                return -a;
            }
            return 0;
        }

        double calculate() {
            // if (!is_valid_input() or !have_valid_bracket()) {
            //     cout << "Error: invalid input" << endl;
            //     return 0;
            // }
            to_main();
            stack<double> result;
            while (!main_line.empty() ) {
                temp_line.push(main_line.front());
                main_line.pop();
                double a = 0, b = 0;
                if (temp_line.top().is_digits()) {
                    result.push(temp_line.top().to_int());
                }
                if (temp_line.top().is_operator()) {
                    if (temp_line.top().get_priority() == 1) {
                        a = result.top();
                        result.pop();
                        result.push(unary_cal(a,temp_line.top()));
                    } else {
                        a = result.top();
                        result.pop();
                        b = result.top();
                        result.pop();
                        result.push(binary_cal(a,b,temp_line.top()));
                    }
                }
            }
            double temp = 0;
            while (!result.empty() ) {
                temp += result.top();
                result.pop();
            }
            return temp;
        }
        void print_format() {
            double x = calculate();
            if (int (x) == x) {
                cout << int (x) << endl;
            } else {
                cout << fixed << x << endl;
            }
        }
};

int main() {
    while (true) {
        StringCal cal;
        cal.input();
        cal.print_format();
    }
    return 0;
}
/*
"": empty input, should raise an error
"1 + 2": basic addition, level 1
"2-1": basic subtraction, level 1
"3*4": basic multiplication, level 1
"5/6": basic division, level 1
"2^3": basic exponentiation, level 1
"1 + 2 * 3": operator precedence, level 2
"(1 + 2) * 3": parentheses, level 2
"1 +++ 2": invalid operator, should raise an error, level 2
"1 + (2 * 3": mismatched parentheses, should raise an error, level 3
"1 + * 2": invalid syntax, should raise an error, level 3
"1 / 0": division by zero, should raise an error, level 3
"1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10": long addition, level 4
"1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10": long multiplication, level 4
"1 + 2 * 3 / (4 ^ 5 - 6)": complex expression, level 5
" 1 + 2 * 3 / 4 ^ 5 - 6 ": expression with whitespace, level 1
"1+2*3/4^5-6": expression without whitespace, level 1
"1 + 2 - -3": double negation, level 2

"1 + 2 * -3": negation with multiplication, level 2
"1 + 2 / -3": negation with division, level 2
"1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 * 100": long addition and multiplication, level 5
"100 / 10 / 2 / 5": long division, level 5
"2 ^ 3 ^ 2": exponentiation with multiple operators, level 5
"1 + 2 * 3 / (4 ^ 5 - 6) + (7 - 8) * 9": complex expression with parentheses, level 6
"1 + 2 * 3 / (4 ^ 5 - 6) + (7 - 8) * 9 + 10 / (11 + 12 - 13 * 14 / 15 ^ 16)": even more complex expression with multiple operators and parentheses, level 7
"1.5 + 2.3 * 4.7 / (8.2 ^ 3.1 - 6.4)": floating point numbers, level 8
"1 + 2i + 3 - 4i / 5 * (6 - 7i ^ 2)": complex numbers, level 9
"1000000000000000000000000000000000000000000000000000000000000000000 + 1": large integer addition, level 10
"1.23456789012345678901234567890123456789012345678901234567890123456789 + 0.00000000000000000000000000000000000000000000000000000000000000000001": large floating point addition, level 11
"1 + 2 * (3 + 4) / 5 - 6 + 7 * (8 + 9) - 10 / 11": complex expression with nested parentheses, level 12
"1 + 2 * 3 / (4 ^ 5 - 6) + (7 - 8) * 9 + 10 / (11 + 12 - 13 * 14 / 15 ^ 16) * (17 - 18 / (19 + 20))": even more complex expression with multiple nested parentheses, level 13
"1 + (2 * 3)": expression with a single nested parentheses, level 14
"1 + ((2 * 3) / (4 - 2))": expression with multiple nested parentheses, level 15
"1 ++ 2": invalid syntax with double plus sign, should raise an error, level 16
"1 + 2 + +3": invalid syntax with double plus sign, should raise an error, level 17
"1 + 2 * 3 / (4 ^ 5 - 6) + (7 - 8) * 9 + 10 / (11 + 12 - 13 * 14 / 15 ^ 16) * (17 - 18 / (19 + 20)) +": invalid syntax with trailing operator, should raise an error, level 18
"1 + 2 * 3 / (4 ^ 5 - 6) + (7 - 8) * 9 + 10 / (11 + 12 - 13 * 14 / 15 ^ 16) * (17 - 18 / (19 + 20)) + 21": valid expression with trailing number, level 19
"1 + 2 * 3 / (4 ^ 5 - 6) + (7 - 8) * 9 + 10 / (11 + 12 - 13 * 14 / 15 ^ 16) * (17 - 18 / (19 + 20)) + 21 *": invalid syntax with trailing operator, should raise an error, level 20
"(1 + 2) * (3 + 4) * (5 + 6)": multiple nested parentheses, level 20
"2 * 3 * 5 * 7 * 11 * 13 * 17 * 19": multiplication of large prime numbers, level 21
"1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/6 + 1/7 + 1/8 + 1/9 + 1/10": harmonic series, level 22
"1 + 1/2 + 1/4 + 1/8 + 1/16 + 1/32 + 1/64 + 1/128 + 1/256 + 1/512": sum of a geometric series, level 23
"sin(0) + cos(pi/2) + tan(pi/4)": trigonometric functions, level 24
"log(10) + ln(e) + log10(100) + ln(exp(1))": logarithmic functions, level 25
"sqrt(2) + cbrt(27) + sqrt(2 + sqrt(2)) + cbrt(27 + cbrt(27))": square and cube roots, level 26
"1 + 2i + 3 - 4i / 5 * (6 - 7i ^ 2) + conj(1 + 2i + 3 - 4i / 5 * (6 - 7i ^ 2))": complex numbers with conjugate, level 27
"integrate(x^2, x, 0, 1)": definite integral, level 28
"diff(sin(x), x)": derivative, level 29
"sum(n^2, n, 1, infinity)": infinite series, level 30
"lim(x^2 - 1, x, 1)": limit, level 31
"solve(x^2 - 2x + 1 = 0, x)": algebraic equation, level 32
"solve(sin(x) = 0, x)": trigonometric equation, level 33
"f(x) = x^2 + 2x + 1, g(x) = x - 1, f(g(x))": function composition, level 34
"f(x) = exp(x), f'(x)": derivative of a function, level 35
"f(x) = x^2, f''(x)": second derivative of a function, level 36
"f(x, y) = x^2 + y^2, grad(f)": gradient of a function, level 37
"f(x, y) = x^2 + y^2, hessian(f)": Hessian matrix of a function, level 38
"f(x, y, z) = x^2 + y^2 + z^2, Laplacian(f)": Laplacian of a function, level 39
"f(x, y) = x^2 + y^2, contour(f)": contour plot of a function, level 40
"f(x, y) = x^2 + y^2, surface(f)": surface plot of a function, level 41
"f(x, y, z) = x^2 + y^2 + z^2, volume(f)": volume integral of a function, level 42
"f(x, y, z) = x^2 + y^2 + z^2, surface(f)": surface integral of a function, level 43
"f(x, y, z) = x^2 + y^2 + z^2, flux(f)": flux integral of a function, level 44
"f(x, y, z) = x^2 + y^2 + z^2, divergence(f)": divergence of a vector field, level 45
"f(x, y, z) = x^2 + y^2 + z^2, curl(f)": curl of a vector field, level 46
"f(x, y, z) = x^2 + y^2 + z^2, laplacian(f)": Laplacian of a scalar field, level 47
"f(x, y, z) = (x, y, z), grad(f)": gradient of a vector field, level 48
"f(x, y, z) = (x, y, z), div(f)": divergence of a vector field, level 49
"f(x, y, z) = (x, y, z), curl(f)": curl of a vector field, level 50
*/