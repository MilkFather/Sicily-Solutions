#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void work() {
    int n;
    cin >> n;
    vector<int> goods;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        goods.push_back(x);
    }
    sort(goods.begin(), goods.end(), greater<int>());
    long long total = 0;
    for (int i = 0; 3 * i + 2 < n; i++) {
        total += goods[3 * i + 2];
    }
    cout << total << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = T; i --> 0;) {
        work();
    }
    return 0;
}