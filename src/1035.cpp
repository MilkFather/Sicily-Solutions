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

using namespace std;

bool isComplementary(string a, string b) {
    if (a.length() != b.length())
        return false;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == 'A' && b[i] != 'T') return false;
        if (a[i] == 'G' && b[i] != 'C') return false;
        if (a[i] == 'T' && b[i] != 'A') return false;
        if (a[i] == 'C' && b[i] != 'G') return false;
    }
    return true;
}

int work() {
    int strands;
    cin >> strands;
    vector<string> DNAstrands;
    
    int pairs = 0;
    
    for (int i = 0; i < strands; i++) {
        string dna;
        bool flag = false;
        cin >> dna;
        vector<string>::iterator it;
        for (it = DNAstrands.begin(); it != DNAstrands.end(); it++) {
            if (isComplementary(*it, dna)) {
                flag = true;
                pairs++;
                DNAstrands.erase(it);
                break;
            }
        }
        if (!flag)
            DNAstrands.push_back(dna);
    }
    
    return pairs;
}

int main(int argc, char *argv[]) {
    int kase;
    cin >> kase;
    
    for (int i = 0; i < kase; i++) {
        cout << work() << endl;
    }
    return 0;
}