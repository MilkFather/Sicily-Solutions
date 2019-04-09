#include <iostream>
#include <string>
#include <stack>

using namespace std;

string work() {
    string input;
    cin >> input;
    stack<char> op;
    string output = "";
    for (int i = 0; i < input.length(); i++) {
        switch (input[i]) {
            case '+':
            case '-':
                while (!op.empty()) {
                    char c = op.top();
                    output += c;
                    op.pop();
                }
                op.push(input[i]);
                break;
                
            case '*':
            case '/':
            case '%':
                while (!op.empty() && (op.top() == '*' || op.top() == '/' || op.top() == '%')) {
                    char c = op.top();
                    output += c;
                    op.pop();
                }
                op.push(input[i]);
                break;
                
            default:
                output += input[i];
                break;
        }
    }
    while (!op.empty()) {
        char c = op.top();
        output += c;
        op.pop();
    }
    return output;
}

int main(int argc, const char * argv[]) {
    cout << work();
    return 0;
}