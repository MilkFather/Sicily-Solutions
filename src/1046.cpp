#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct span {
    int start, end, total;
    span(int _s, int _e, vector<int> pl): start(_s), end(_e){
        total = 0;
        for (int i = _s; i <= _e; i++) {
            total += pl[i];
        }
    };
    bool operator<(const span& rhs) const {
        if ((double)total / (end - start + 1) > (double)rhs.total / (rhs.end - rhs.start + 1)) return true;
        else if ((double)total / (end - start + 1) < (double)rhs.total / (rhs.end - rhs.start + 1)) return false;
        else if (end - start > rhs.end - rhs.start) return true;
        else if (end - start < rhs.end - rhs.start) return false;
        else return end < rhs.end;
    }
};

void work(int no) {
    int nquarters, nrequests, nminimum;
    cin >> nquarters >> nrequests >> nminimum;
    vector<int> planes;
    for (int i = 0; i < nquarters; i++) {
        int np;
        cin >> np;
        planes.push_back(np);
    }
    vector<span> sps;
    for (int i = nminimum; i <= nquarters; i++) {
        for (int j = 0; j <= nquarters - i; j++) {
            span newspan(j, j + i - 1, planes);
            sps.push_back(newspan);
        }
    }
    sort(sps.begin(), sps.end());
    cout << "Result for run " << no << ":" << endl;
    for (int i = 0; i < min(nrequests, (int)sps.size()); i++) {
        cout << sps[i].start + 1 << "-" << sps[i].end + 1 << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        work(i);
    }
    return 0;
}