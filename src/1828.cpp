#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long MAX = 1000000000000;
const long long UNDEFINED = -1;
long long dp[501][501];
vector<long long> a, b;

long long find(int i, int j) {
    if (dp[i][j] != UNDEFINED) return dp[i][j];
    if (i > j) dp[i][j] = MAX;
    else if (i == 0) dp[i][j] = 0;
    else dp[i][j] = min(
        find(i - 1, j - 1) + abs(a[i - 1] - b[j - 1]),
        find(i, j - 1)
    );
    return dp[i][j];
}

void work() {
    a.clear();
    b.clear();
    for (int i = 0; i < 501; i++) for (int j = 0; j < 501; j++) dp[i][j] = UNDEFINED;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < M; i++) {
        long long x;
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << find(a.size(), b.size()) << endl;
}

int main(int argc, char* argv[]) {
    int kases;
    cin >> kases;
    for (int i = 0; i < kases; i++) {
        work();
    }
    return 0;
}