#include <iostream>

using namespace std;

int primes[100000];

bool isprime(int x, int hasprime) {
    for (int i = 0; i < hasprime && primes[i] * primes[i] <= x; i++) {
        if (x % primes[i] == 0) {
            return false;
        }
    }
    return true;
}

void calcprimes() {
    int nprime = 1;
    primes[0] = 2;
    for (int i = 3; i <= 1299709; i += 2) {
        if (isprime(i, nprime)) {
            primes[nprime] = i;
            nprime++;
        }
    }
}

int binsearch(int x) {
    // 2 <= x <= 1299709
    // return value is the index of the first prime >= x
    int hi = 99999, lo = 0;
    while (hi - lo > 1) {
        int mi = (hi + lo) / 2;
        if (primes[mi] >= x) {
            hi = mi;
        } else {
            lo = mi;
        }
    }
    if (primes[lo] >= x) return lo;
    if (primes[hi] >= x) return hi;
    return -1;
}

void work(int x) {
    int idx = binsearch(x);
    if (x == primes[idx]) {
        cout << 0 << endl;  // it is a prime
    } else {
        cout << primes[idx] - primes[idx - 1] << endl;
    }
}

int main() {
    calcprimes();
    int x;
    cin >> x;
    while (x > 0) {
        work(x);
        cin >> x;
    }
    return 0;
}