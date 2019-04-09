#include <cstdio>

using namespace std;

int main(int argc, const char * argv[]) {
    int in1[5], in2[5];
    for (int i = 0; i < 5; i++)
        scanf("%d", &in1[i]);
    for (int i = 0; i < 5; i++)
        scanf("%d", &in2[i]);
    int i1i = 0, i2i = 0;
    for (int i = 0; i < 10; i++) {
        if (i1i == 5) {
            printf("%d ", in2[i2i]);
            i2i++;
        } else if (i2i == 5) {
            printf("%d ", in1[i1i]);
            i1i++;
        } else if (in1[i1i] < in2[i2i]) {
            printf("%d ", in1[i1i]);
            i1i++;
        } else {
            printf("%d ", in2[i2i]);
            i2i++;
        }
    }
    return 0;
}