#include <cstdio>
#include <cmath>

using namespace std;

long long find(const long long x) {
    for (long long i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return i;
        }
    }
    return -1;
}

void work(int x) {
    long long t = (long long)pow(2, x) - 1;
    long long fac = find(t);
    if (fac == -1) return;
    long long afac = t / fac;
    printf("%lld", fac);
    fac = find(afac);
    while (fac != -1) {
        afac = afac / fac;
        printf(" * %lld", fac);
        fac = find(afac);
    }
    printf(" * %lld = %lld = ( 2 ^ %d ) - 1\n", afac, t, x);
}

int main() {
    long long primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 6661};
    int n;
    scanf("%d", &n);
    for (int i = 0; primes[i] <= n; i++) {
        work(primes[i]);
    }
    return 0;
}