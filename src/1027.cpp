#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

struct MaJia {
    string main_ID = "";
    string MJ_ID = "";
    bool operator< (const MaJia& rhs) const {
        return this->main_ID < rhs.main_ID;
    }
};

bool cmp (const MaJia* lhs, const MaJia* rhs) {
    return (*lhs) < (*rhs);
}

void work(int n) {
    vector<MaJia*> majias;
    map<string, MaJia*> iptable;
    for (int i = 0; i < n; i++) {
        string id, ip;
        cin >> id >> ip;
        if (iptable.count(ip) > 0) {
            // main found, register MaJia
            iptable[ip] -> MJ_ID = id;
        } else {
            // mew ip, register main_ID
            MaJia* newmajia = new MaJia;
            newmajia -> main_ID = id;
            majias.push_back(newmajia);
            iptable[ip] = newmajia;
        }
    }
    // sort
    sort(majias.begin(), majias.end(), cmp);
    for (int i = 0; i < majias.size(); i++) {
        cout << majias[i] -> MJ_ID << " is the MaJia of " << majias[i] -> main_ID << endl;
        delete majias[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while (n != 0) {
        work(n);
        cin >> n;
    }
    return 0;
}