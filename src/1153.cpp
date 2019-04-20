#include <cstdio>

using namespace std;

void work(int s) {
    int circuit[64] = {
         1, 11,  5, 20, 30, 36, 46, 31,
        16, 22,  7, 13,  3,  9, 26, 41, 
        58, 52, 62, 56, 39, 24, 14,  8, 
        23, 40, 55, 61, 51, 57, 42, 25,
        10,  4, 19, 29, 35, 45, 28, 43, 
        37, 27, 44, 38, 48, 63, 53, 59, 
        49, 34, 17,  2, 12,  6, 21, 15, 
        32, 47, 64, 54, 60, 50, 33, 18
    };
    int sidx;
    for (sidx = 0; circuit[sidx] != s; sidx++);
    printf("%d", circuit[sidx]);
    for (int i = 1; i < 64; i++) {
        printf(" %d", circuit[(sidx + i) % 64]);
    }
    printf("\n");
}

int main() {
    int s;
    scanf("%d", &s);
    while (s != -1) {
        work(s);
        scanf("%d", &s);
    }
    return 0;
}