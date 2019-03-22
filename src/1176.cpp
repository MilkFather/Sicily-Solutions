#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int UNDEFINED = -2000000;
long dp[1001][1001];
vector<int> cards;

long find(int fst, int snd) {
    if (dp[fst][snd] != UNDEFINED) return dp[fst][snd];

    bool ll = cards[fst + 1] >= cards[snd];
    bool rr = cards[snd - 1] > cards[fst];

    dp[fst][snd] = max(
        cards[fst] - max(cards[fst + 1], cards[snd]) + (ll ? find(fst + 2, snd) : find(fst + 1, snd - 1)),
        cards[snd] - max(cards[fst], cards[snd - 1]) + (rr ? find(fst, snd - 2) : find(fst + 1, snd - 1))
    );
    return dp[fst][snd];
}

void work(int idx, int n) {
    cards.clear();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cards.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = UNDEFINED;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        dp[i][i + 1] = abs(cards[i] - cards[i + 1]);
    } // init

    // dp
    cout << "In game " << idx << ", the greedy strategy might lose by as many as " << find(0, n - 1) << " points." << endl;
}

int main() {
    int nc;
    cin >> nc;
    int i = 0;
    while (nc != 0) {
        work(++i, nc);
        cin >> nc;
    }
    return 0;
}