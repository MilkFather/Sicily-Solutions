#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool work() {
    string input;
    cin >> input;
    stack<char> brackets;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(' or input[i] == '[' or input[i] == '{')
            brackets.push(input[i]);
        else if (input[i] == ')' or input[i] == ']' or input[i] == '}') {
            if (brackets.empty())
                return false;
            char c = brackets.top();
            brackets.pop();
            if ((input[i] == ')' and c != '(') or (input[i] == ']' and c != '[') or (input[i] == '}' and c != '{'))
                return false;
        }
    }
    return brackets.empty();
}

int main(int argc, const char * argv[]) {
    int kase;
    cin >> kase;
    for (int i = 0; i < kase; i++)
        cout << (work() ? "Yes" : "No") << endl;
    return 0;
}