#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> divide(string s) {
    vector<string> pts;
    bool zeromode = false;
    string buf;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            if (zeromode == false) {
                if (buf != "") pts.push_back(buf);
                zeromode = true;
                buf = "0";
            } else {
                buf += "0";
            }
        } else {
            if (zeromode == true) {
                if (buf != "") pts.push_back(buf);
                zeromode = false;
                buf = ""; buf += s[i];
            } else {
                buf += s[i];
            }
        }
    }
    if (buf != "") pts.push_back(buf);
    return pts;
}

void work() {
    string all;
    cin >> all;
    // divide all into non-0 and 0 parts
    vector<string> pts = divide(all);
    for (int i = 0; i < pts.size(); i++) {
        sort(pts[i].begin(), pts[i].end(), greater<char>());
        cout << pts[i];
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = T; i --> 0;) {
        work();
    }
}