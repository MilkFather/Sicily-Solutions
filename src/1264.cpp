#include <cstdio>
#include <vector>

using namespace std;

const double UNDEFINED = 900000000;

vector<double> dp;
vector<double> dtime;

void calctime(const int totallen, const int r, const double v, const double e, const double f) {
    // assume a new tyre at start
    dtime.push_back(0);
    for (int i = 0; i < totallen; i++) {
        double t;
        if (i >= r) 
            t = 1 / (v - e * (i - r));
        else 
            t = 1 / (v - f * (r - i));
        dtime.push_back(dtime[i] + t);
    }
}

double find(const vector<int> &at, const int idx, const double b) {
    // find the shortest time to arrive at "at"
    // the time is min(every possible last retyre at some previous checkpoint + time to retyre + time to here)
    if (dp[idx] != UNDEFINED) return dp[idx];

    double mintime = dtime[at[idx]]; // no checkpoint
    for (int i = 0; i < idx; i++) {
        double t = find(at, i, b) + b + dtime[at[idx] - at[i]];
        if (t < mintime)
            mintime = t;
    }
    dp[idx] = mintime;
    return dp[idx];
}

void work(int n) {
    int r;
    double b, v, e, f;
    vector<int> checkpoints;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        checkpoints.push_back(a);
    }
    scanf("%lf %d %lf %lf %lf", &b, &r, &v, &e, &f);
    dp.clear();
    dtime.clear();
    for (int i = 0; i < n; i++) dp.push_back(UNDEFINED);
    calctime(checkpoints[n - 1], r, v, e, f);
    printf("%.6lf\n", find(checkpoints, n - 1, b));
}

int main() {
    int n;
    scanf("%d", &n);
    while (n != 0) {
        work(n);
        scanf("%d", &n);
    }
    return 0;
}