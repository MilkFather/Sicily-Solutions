#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct keyint {
    int col;
    char k;

    bool operator< (const keyint &rhs) const {
        return this->k < rhs.k;
    }
};

void work(string key) {
    string enc;
    cin >> enc;
    int row = enc.length() / key.length();
    // struct the key
    vector <keyint> keys;
    for (int i = 0; i < key.length(); i++) {
        keyint ki;
        ki.k = key[i];
        ki.col = i;
        keys.push_back(ki);
    }
    stable_sort(keys.begin(), keys.end());
    int encidx = 0;
    char matrix[row][key.length()];
    for (int i = 0; i < keys.size(); i++) {
        int idx = keys[i].col;
        for (int j = 0; j < row; j++) {
            matrix[j][idx] = enc[encidx++];
        }
    }

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < key.size(); c++) {
            cout << matrix[r][c];
        }
    }
    cout << endl;
}

int main() {
    string k;
    cin >> k;
    while (k != "THEEND") {
        work(k);
        cin >> k;
    }
    return 0;
}