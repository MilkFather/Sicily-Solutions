#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct cord {
    double x;
    double y;
};

bool cmp(const cord &lhs, const cord &rhs) {
    return lhs.x < rhs.x;
}

void work(int btm) {
    cord r1[btm], r2[btm], r3[btm];
    // read first layer
    for (int i = 0; i < btm; i++) {
        double xcord;
        scanf("%lf", &xcord);
        r1[i].x = xcord;
        r1[i].y = 1;
    }
    sort(r1, r1 + btm, cmp);
    if (btm == 1) {
        printf("%.4lf %.4lf\n", r1[0].x, r1[0].y);
        return;
    }
    // has more than one layer, set up the second layer
    for (int i = 0; i < btm - 1; i++) {
        r2[i].x = (r1[i].x + r1[i + 1].x) / 2;
        r2[i].y = 1 + sqrt(4 - ((r1[i + 1].x - r1[i].x) / 2) * ((r1[i + 1].x - r1[i].x) / 2));
    }
    // use vector method to iterate to the top layer
    for (int i = 2; i < btm; i++) {
        for (int j = 0; j < btm - i; j++) {
            r3[j].x = r2[j].x + r2[j + 1].x - r1[j + 1].x;
            r3[j].y = r2[j].y + r2[j + 1].y - r1[j + 1].y;
        }
        // copy
        for (int j = 0; j < btm - i + 1; j++) {
            r1[j].x = r2[j].x;
            r1[j].y = r2[j].y;
        }
        for (int j = 0; j < btm - i; j++) {
            r2[j].x = r3[j].x;
            r2[j].y = r3[j].y;
        }
    }
    printf("%.4lf %.4lf\n", r2[0].x, r2[0].y);
}

int main() {
    int b;
    scanf("%d", &b);
    while (b > 0) {
        work(b);
        scanf("%d", &b);
    }
    return 0;
}