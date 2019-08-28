#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ranking {
    string rank;
    int diff(const ranking &rhs) const {
        int rankA[5];
        int rankB[5];
        for (int i = 0; i < 5; i++) {
            rankA[rank[i] - 'A'] = i;
            rankB[rhs.rank[i] - 'A'] = i;
        }
        int dif = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 5; j++) {
                if ((rankA[i] - rankA[j]) * (rankB[i] - rankB[j]) < 0)
                    dif++;
            }
        }
        return dif;
    }
    ranking(string r) {
        rank = r;
    }
};

void work(int rs) {
    vector<ranking> rk;
    for (int i = 0; i < rs; i++) {
        string r;
        cin >> r;
        ranking rkng(r);
        rk.push_back(r);
    }
    // generate permution
    int mindif = 10000000;
    string sol = "ABCDE";
    string ans;
    do {
        ranking candidate(sol);
        int dif = 0;
        for (int i = 0; i < rs; i++) dif += candidate.diff(rk[i]);
        if (mindif > dif) {
            mindif = dif;
            ans = sol;
        } 
    } while (next_permutation(sol.begin(), sol.end()));
    cout << ans << " is the median ranking with value " << mindif << ".\n";
}

int main() {
    int r;
    cin >> r;
    while (r > 0) {
        work(r);
        cin >> r;
    }
    return 0;
}