#include <cstdio>
#include <algorithm>

using namespace std;

struct blockinfo {
    int a;
    int b;
};

bool cmp(const blockinfo &lhs, const blockinfo &rhs) {
    return lhs.b < rhs.b;
}

void work(int n, int s) {
    long long has = s;
    blockinfo kodomodachi[10000];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &kodomodachi[i].a, &kodomodachi[i].b);
    }
    sort(kodomodachi, kodomodachi + n, cmp);
    for (int i = 0; i < n; i++) {
        if (has < kodomodachi[i].b) {
            printf("NO\n");
            return;
        } else {
            has += kodomodachi[i].a;
        }
    }
    printf("YES\n");
}

int main() {
    int n, s;
    scanf("%d %d", &n, &s);
    while (n != 0) {
        work(n, s);
        scanf("%d %d", &n, &s);
    }
    return 0;
}