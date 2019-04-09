#include <iostream>
#include <string>
#include <stack>

using namespace std;

double work() {
    string input;
    cin >> input;
    stack<double> nums;
    for (int i = 0; i < input.length(); i++) {
        double x, y;
        switch (input[i]) {
            case '+':
                y = nums.top(); nums.pop();
                x = nums.top(); nums.pop();
                nums.push(x + y);
                break;
            case '-':
                y = nums.top(); nums.pop();
                x = nums.top(); nums.pop();
                nums.push(x - y);
                break;
            case '*':
                y = nums.top(); nums.pop();
                x = nums.top(); nums.pop();
                nums.push(x * y);
                break;
            case '/':
                y = nums.top(); nums.pop();
                x = nums.top(); nums.pop();
                nums.push(x / y);
                break;
                
            default:
                nums.push((double)input[i] - 'a' + 1);
                break;
        }
    }
    return nums.top();
}

int main(int argc, const char * argv[]) {
    int kase;
    cin >> kase;
    for (int i = 0; i < kase; i++)
        printf("%.2lf\n", work());
    return 0;
}