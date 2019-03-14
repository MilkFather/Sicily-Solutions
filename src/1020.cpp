#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getmod(string verylongint, int modular) {
    int res = 0;
    for (int i = 0; i < verylongint.length(); i++) {
        res *= 10;
        res %= modular;
        res += ((verylongint[i] - '0') % modular);
        res %= modular;
    }
    return res;
}

void work() {
    int n;
    cin >> n;
    vector<int> mods;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        mods.push_back(m);
    }
    string vli;
    cin >> vli;
    cout << '(';
    for (int i = 0; i < n; i++) {
        cout << getmod(vli, mods[i]) << (i == n - 1 ? "" : ",");
    }
    cout << ')' << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        work();
    }
}