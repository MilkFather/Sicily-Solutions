#include <iostream>

using namespace std;

int dp[105][105];

int find(int numcnt, int lesscnt) {
    if (lesscnt == 0 || lesscnt == numcnt - 1)
        return 1;
    if (lesscnt < 0 || lesscnt >= numcnt)
        return 0;
    if (dp[numcnt][lesscnt] == -1) {
        dp[numcnt][lesscnt] = ((numcnt - lesscnt) * find(numcnt - 1, lesscnt - 1) + (lesscnt + 1) * find(numcnt - 1, lesscnt)) % 2007;
    }
    return dp[numcnt][lesscnt];
}

void work(int a, int b) {
    for (int i = 0; i < a + 1; i++) {
        for (int j = 0; j < b + 1; j++) {
            dp[i][j] = -1;
        }
    }
    cout << find(a, b) << endl;
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        work(a, b);
    }
    return 0;
}