#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct JOB {
    int piority;
    int index;
    JOB(int p, int i): piority(p), index(i) {};
} job;

int work() {
    int n, index;
    cin >> n >> index;
    queue<job> jbs;
    priority_queue<int> priorities;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        job j(p, i);
        jbs.push(j);
        priorities.push(p);
    }
    int time = 0;
    // why not simulate, given the data size..
    while (true) {
        job j = jbs.front();
        jbs.pop();
        if (j.piority < priorities.top())
            jbs.push(j);
        else {
            time++;
            priorities.pop();
            if (j.index == index)
                break;
        }
    }
    return time;
}

int main(int argc, const char * argv[]) {
    int kase;
    cin >> kase;
    for (int i = 0; i < kase; i++)
        cout << work() << endl;
    return 0;
}