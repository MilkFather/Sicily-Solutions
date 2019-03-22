#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int UNDEFINED = -10000000;

long long dp[11][2001];

long long find(int cnt, int len) {
    if (dp[cnt][len] != UNDEFINED) return dp[cnt][len];
    
    if (pow(2, (cnt - 1)) > len) {
        dp[cnt][len] = 0;
    } else if (cnt == 1) {
        dp[cnt][len] = len;
    } else {
        dp[cnt][len] = 0;
        for (int i = (int)pow(2, cnt - 1); i <= len; i++) {
            dp[cnt][len] += find(cnt - 1, i / 2);
        }
    }
    return dp[cnt][len];
}

void work(int idx) {
    int n, m;
    cin >> n >> m;
    cout << "Case " << idx << ": n = " << n << ", m = " << m << ", # lists = " << find(n, m) << endl;
}

int main() {
    // init
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 2000; j++) {
            dp[i][j] = UNDEFINED;
        }
    }

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        work(i);
    }
    return 0;
}