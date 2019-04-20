#include <cstdio>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <array>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <stdexcept>

using namespace std;

struct token {
    bool isnum;
    string s;
    token(bool mode): isnum(mode){};
};

bool iszero(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '0') return false;
    }
    return true;
}

int compareint(string s1, string s2) {
    string temps1, temps2;
    if (isdigit(s1[0])) {
        temps1 = s1;
    } else {
        // extract the sign
        temps1 = s1.substr(1);
    }
    if (isdigit(s2[0])) {
        temps2 = s2;
    } else {
        // extract the sign
        temps2 = s2.substr(1);
    }
    
    if (iszero(temps1) && iszero(temps2)) return 0;
    
    int digit = (int)max(temps1.length(), temps2.length());
    string ss1, ss2;
    if (s1[0] == '-') {
        ss1 += '-';
    } else {
        ss1 += '+';
    }
    for (int i = 0; i < (digit - temps1.length()); i++)
        ss1 += '0';
    ss1 += temps1;
    
    if (s2[0] == '-') {
        ss2 += '-';
    } else {
        ss2 += '+';
    }
    for (int i = 0; i < (digit - temps2.length()); i++)
        ss2 += '0';
    ss2 += temps2;
    
    if (ss1[0] == '+' && ss2[0] == '-') return 1;
    if (ss1[0] == '-' && ss2[0] == '+') return -1;
    if (ss1[0] == '+' && ss2[0] == '+') {
        if (ss1.substr(1) > ss2.substr(1)) return 1;
        if (ss1.substr(1) == ss2.substr(1)) return 0;
        if (ss1.substr(1) < ss2.substr(1)) return -1;
    }
    if (ss1[0] == '-' && ss2[0] == '-') {
        if (ss1.substr(1) > ss2.substr(1)) return -1;
        if (ss1.substr(1) == ss2.substr(1)) return 0;
        if (ss1.substr(1) < ss2.substr(1)) return 1;
    }
    return 0;
}

vector<string> partialize(string s) {
    // status:
    // 0 - initial
    // 1 - string mode
    // 2 - number mode
    int status = 0;
    vector<string> parts;
    string buf = "";
    for (int i = 0; i < s.length(); i++) {
        switch (status) {
            case 0:
                if ((s[i] == '+' || s[i] == '-') && i < s.length() - 1 && isdigit(s[i + 1])) {
                    // a + or - preceeds a number
                    buf += s[i];
                    status = 2;
                } else if (isdigit(s[i])) {
                    // a number
                    buf += s[i];
                    status = 2;
                } else {
                    // string
                    buf += toupper(s[i]);
                    status = 1;
                }
                break;
                
            case 1:
                if ((s[i] == '+' || s[i] == '-') && i < s.length() - 1 && isdigit(s[i + 1])) {
                    // in string mode means it does not succeed a number
                    parts.push_back(buf);
                    buf = "";
                    buf += s[i];
                    status = 2;
                } else if (isdigit(s[i])) {
                    // start of a number
                    parts.push_back(buf);
                    buf = "";
                    buf += s[i];
                    status = 2;
                } else {
                    // don't change state
                    buf += toupper(s[i]);
                }
                break;
            
            case 2:
                if (s[i] == '+' || s[i] == '-') {
                    // in number mode means it succeeds a number
                    parts.push_back(buf);
                    buf = "";
                    buf += s[i];
                    status = 1;
                } else if (isdigit(s[i])) {
                    // still part of a number
                    buf += s[i];
                } else {
                    // change state, start of a string
                    parts.push_back(buf);
                    buf = "";
                    buf += toupper(s[i]);
                    status = 1;
                }
                break;
                
            default:
                break;
        }
    }
    if (buf != "") parts.push_back(buf);
    return parts;
}

vector<token> tokenize(vector<string> part) {
    vector<token> res;
    for (int i = 0; i < part.size(); i++) {
        if (isdigit(part[i][part[i].length() - 1])) {
            // the last char of the string is a digit --> a number
            token newtoken(true);
            newtoken.s = part[i];
            res.push_back(newtoken);
        } else {
            // a string
            token newtoken(false);
            newtoken.s = part[i];
            res.push_back(newtoken);
        }
    }
    return res;
}

int tokcompare(vector<token> tok1, vector<token> tok2) {
    for (int i = 0; i < min(tok1.size(), tok2.size()); i++) {
        if (tok1[i].isnum == true && tok2[i].isnum == false)
            return -1;
        else if (tok1[i].isnum == false && tok2[i].isnum == true)
            return 1;
        else {
            if (tok1[i].isnum == true) {
                int comres = compareint(tok1[i].s, tok2[i].s);
                if (comres != 0) return comres;
            } else {
                if (tok1[i].s < tok2[i].s)
                    return -1;
                else if (tok1[i].s > tok2[i].s)
                    return 1;
            }
        }
    }
    // when existing part compared same, compare the length
    if (tok1.size() < tok2.size())
        return -1;
    else if (tok1.size() > tok2.size())
        return 1;
    else
        return 0;
}

int compare(string s1, string s2) {
    return tokcompare(tokenize(partialize(s1)), tokenize(partialize(s2)));
}

void work() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << compare(s1, s2) << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << i << " ";
        work();
    }
    
    return 0;
}