#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long UNDEFINED = -1;
long long dp[201][201];
vector<long long> slots;

long long find(int first, int second) {
    if (dp[first][second] != UNDEFINED) return dp[first][second];
    if (first + 1 == second) {
        dp[first][second] = 0; // no merge, release 0
    } else {
        long long mmax = find(first, first + 1) + slots[first] * slots[first + 1] * slots[second] + find(first + 1, second);
        for (int i = first + 2; i <= second - 1; i++) {
            mmax = max(mmax,
            find(first, i) + slots[first] * slots[i] * slots[second] + find(i, second));
        }
        dp[first][second] = mmax;
    }
    return dp[first][second];
}

void work(int n) {
    // init dp
    for (int i = 0; i < 201; i++) for (int j = 0; j < 201; j++) dp[i][j] = UNDEFINED;
    slots.clear();
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        slots.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        slots.push_back(slots[i]); // repeat once
    }
    find(0, 2 * n - 1);
    long long res = find(0, n);
    for (int i = 1; i < n; i++) {
        res = max(res, find(i, n  + i));
    }
    cout << res << endl;
}

int main(int argc, char* argv[]) {
    int N;
    while (cin >> N) {
        work(N);
    }
    return 0;
}