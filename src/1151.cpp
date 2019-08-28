#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

struct magic_board {
    string palette;
    int steps;
    string history;

    magic_board() {
        palette = "12348765";
        steps = 0;
        history = "";
    }

    magic_board(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) {
        palette = "00000000";
        palette[0] = a1 + '0'; palette[1] = a2 + '0'; palette[2] = a3 + '0'; palette[3] = a4 + '0';
        palette[4] = a5 + '0'; palette[5] = a6 + '0'; palette[6] = a7 + '0'; palette[7] = a8 + '0';
        steps = 0;
        history = "";
    }

    bool operator==(const magic_board &rhs) const {
        return this->palette == rhs.palette;
    }

    void A() {
        swap(palette[0], palette[4]); swap(palette[1], palette[5]); 
        swap(palette[2], palette[6]); swap(palette[3], palette[7]);
        steps++;
        history.push_back('A');
    }

    void B() {
        swap(palette[0], palette[3]); swap(palette[4], palette[7]); 
        swap(palette[3], palette[2]); swap(palette[7], palette[6]);
        swap(palette[2], palette[1]); swap(palette[6], palette[5]);
        steps++;
        history.push_back('B');
    }

    void C() {
        swap(palette[2], palette[1]); 
        swap(palette[1], palette[5]); 
        swap(palette[5], palette[6]); 
        steps++;
        history.push_back('C');
    }

    void print() const {
        cout << steps << " " << history << endl;
    }
};

void work(int N) {
    int a1, a2, a3, a4, a5, a6, a7, a8;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8;
    magic_board t(a1, a2, a3, a4, a5, a6, a7, a8);

    set<string> visited;

    queue<magic_board> bfsq;
    magic_board s;
    visited.insert(s.palette);
    bfsq.push(s);

    while (!bfsq.empty()) {
        magic_board m = bfsq.front();
        bfsq.pop();
        if (m == t) {
            m.print();
            return;
        } else {
            if (m.steps < N) {
                magic_board m1 = m; m1.A();
                magic_board m2 = m; m2.B();
                magic_board m3 = m; m3.C();
                if (m1 == t) {
                    m1.print();
                    return;
                } else {
                    if (visited.find(m1.palette) == visited.end()) {
                        visited.insert(m1.palette);
                        bfsq.push(m1);
                    }
                }
                if (m2 == t) {
                    m2.print();
                    return;
                } else {
                    if (visited.find(m2.palette) == visited.end()) {
                        visited.insert(m2.palette);
                        bfsq.push(m2);
                    }
                }
                if (m3 == t) {
                    m3.print();
                    return;
                } else {
                    if (visited.find(m3.palette) == visited.end()) {
                        visited.insert(m3.palette);
                        bfsq.push(m3);
                    }
                }
            }
            
        }
    }
    cout << -1 << endl;
}

int main() {
    int n;
    cin >> n;
    while (n != -1) {
        work(n);
        cin >> n;
    }
    return 0;
}