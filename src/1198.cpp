#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &lhs, const string& rhs) {
    if (lhs + rhs < rhs + lhs) return true;
    else return false;
}

void work() {
    int n;
    vector<string> strings;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        strings.push_back(s);
    }
    sort(strings.begin(), strings.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << strings[i];
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = T; T --> 0;) {
        work();
    }
}