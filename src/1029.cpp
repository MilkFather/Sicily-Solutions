#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string getSum(string a, string b) {
    if (a.length() > b.length()) {
        swap(a, b);
    }
    string res = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;
    for (int i = 0; i < a.length(); i++) {
        int sum = a[i] - '0' + b[i] - '0' + carry;
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    for (int i = a.length(); i < b.length(); i++) {
        int sum = b[i] - '0' + carry;
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    if (carry > 0) {
        res.push_back(carry + '0');
    }
    while (res.back() == '0' && res.length() > 1) {
        res.pop_back();
    }
    reverse(res.begin(), res.end());
    return res;
}

void work(int m, int d) {
    vector<string> dp;
    dp.push_back("1");
    for (int i = 1; i <= d; i++) {
        dp.push_back(getSum(dp[i - 1], (i - m < 0) ? dp[0] : dp[i - m]));
    }
    cout << dp[d] << endl;
}

int main() {
    int m, d;
    scanf("%d %d", &m, &d);
    while (m != 0 || d != 0) {
        work(m, d);
        scanf("%d %d", &m, &d);
    }
    return 0;
}