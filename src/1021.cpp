#include <iostream>
#include <stack>

using namespace std;

void work(int n) {
    int cpls[2 * n];
    for (int j = 0; j < n; j++) {
        int pos;
        cin >> pos;
        cpls[pos - 1] = j;
        cin >> pos;
        cpls[pos - 1] = j;
    }
    stack<int> stk;
    for (int i = 0; i < 2 * n; i++) {
        if (stk.empty() || stk.top() != cpls[i]) {
            stk.push(cpls[i]);
        } else {
            stk.pop();
        }
    }
    cout << (stk.empty() ? "Yes" : "No") << endl;
}

int main() {
    int i;
    cin >> i;
    while (i != 0) {
        work(i);
        cin >> i;
    }
    return 0;
}