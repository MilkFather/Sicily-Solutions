#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N, E;
bool root_candidate[101];
bool visited[101];
bool edge_matrix[101][101];
int level_count[101];

void init() {
    for (int i = 0; i <= N; i++) {
        root_candidate[i] = true;
        level_count[i] = 0;
        visited[i] = false;
        for (int j = 0; j <= N; j++) {
            edge_matrix[i][j] = false;
        }
    }
}

int count_roots() {
    int cnt = 0;
    for (int i = 1; i <= N; i++)
        if (root_candidate[i])
            cnt++;
    return cnt;
}

bool bfs(int rt) {
    pair<int, int> start = make_pair(rt, 0);
    visited[rt] = true;
    queue<pair<int, int> > bfsq;
    bfsq.push(start);
    while (!bfsq.empty()) {
        pair<int, int> node = bfsq.front();
        bfsq.pop();
        level_count[node.second]++;  // add count
        for (int i = 1; i <= N; i++) {
            if (edge_matrix[node.first][i] == true) {
                if (visited[i] == true) {
                    // FATAL ERROR
                    return false;
                } else {
                    visited[i] = true;
                    bfsq.push(make_pair(i, node.second + 1));
                }
            }
        }
    }
    // bfs successful
    return true;
}

void work() {
    init();
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        root_candidate[b] = false;
        edge_matrix[a][b] = true;
    }
    // judgement!
    if (count_roots() + E != N) {
        cout << "INVALID" << endl;
    } else {
        // do work now
        bool valid = true;
        for (int i = 1; i <= N; i++) {
            if (root_candidate[i] == true) {
                valid = bfs(i);
                if (!valid) {
                    cout << "INVALID" << endl;
                    return;
                }
            }
        }
        // final level of check
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                cout << "INVALID" << endl;
                return;
            }
        }
        // calculate all
        int max_width = level_count[0];
        int max_depth = 0;
        for (int i = 1; i <= N; i++) {
            if (level_count[i] > 0)
                max_depth = i;
            max_width = max(max_width, level_count[i]);
        }
        cout << max_depth << " " << max_width << endl;
    }
}

int main() {
    cin >> N >> E;
    while (N != 0) {
        work();
        cin >> N >> E;
    }
    return 0;
}