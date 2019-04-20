#include <cstdio>

using namespace std;

void work(long long n) {
    // convert into array of numbers
    int arr[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int idx = 8;
    long long nbk = n;
    while (nbk > 0) {
        arr[idx] = nbk % 10;
        if (arr[idx] > 3) arr[idx]--;
        idx--; 
        nbk /= 10;
    }
    // do the work
    long long actual = 0;
    for (int i = 0; i < 9; i++) {
        actual *= 9;
        actual += arr[i];
    }
    printf("%lld: %lld\n", n, actual);
}

int main() {
    long long odo;
    scanf("%lld", &odo);
    while (odo > 0) {
        work(odo);
        scanf("%lld", &odo);
    }
    return 0;
}