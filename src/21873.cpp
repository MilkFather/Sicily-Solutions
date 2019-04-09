#include <iostream>
#include <string>
#include <vector>

using namespace std;

string reverse(string s) {
    string news = "";
    for (int i = (int)s.length() - 1; i >= 0; i--) {
        news += s[i];
    }
    return news;
};

void work() {
    string input;
    cin >> input;
    // seperate input with "_"
    string s = "";
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '_') {
            cout << reverse(s) << '_';
            s = "";
        }
        else
            s += input[i];
    }
    cout << reverse(s) << endl;
}

int main(int argc, const char * argv[]) {
    int kase;
    cin >> kase;
    for (int i = 0; i < kase; i++)
        work();
    return 0;
}