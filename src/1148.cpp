#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, S, T, M;
int newL = 0;
vector<int> stones;
bool has[20000];

int special() {
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        if (stones[i] % T == 0) cnt++;
    }
    return cnt;
}

void compact() {
    const int MAXINTERVAL = 100;
    for (int i = 0; i < 20000; i++) has[i] = false;
    for (int i = 0, pre = 0; i < M; i++) {
        newL += min(stones[i] - pre, MAXINTERVAL);
        has[newL] = true;
        pre = stones[i];
    }
    newL += min(L - stones[M - 1], MAXINTERVAL);
}

int main() {
    cin >> L >> S >> T >> M;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        stones.push_back(x);
    }
    sort(stones.begin(), stones.end());
    if (S == T) {
        cout << special() << endl;
    } else {
        compact();
    }
    vector<int> dp(newL + T, -1);
    dp[0] = 0;
    // induction
    for (int i = 0; i < newL; i++) {
        if (dp[i] >= 0) {
            for (int j = S; j <= T; j++) {
                if (dp[i + j] < 0) dp[i + j] = dp[i] + (has[i + j] ? 1 : 0);
                else dp[i + j] = min(dp[i + j], dp[i] + (has[i + j] ? 1 : 0));
            }
        }
    }
    int res = 1000;
    for (int i = newL; i < newL + T; i++) res = min(res, dp[i]);
    cout << res << endl;

    //for (int i = 0; i < dp.size(); i++) cout << dp[i] << " ";
    return 0;
}