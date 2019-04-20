#include <iostream>

using namespace std;

int primes[1229];

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
    for (int i = 3; i <= 10000; i += 2) {
        if (isprime(i, nprime)) {
            primes[nprime] = i;
            nprime++;
        }
    }
}

bool elaborate(int sidx, int target) {
    int total = 0;
    for (int i = sidx; i < 1229; i++) {
        if (total > target) return false;
        if (total == target) return true;
        total += primes[i];
    }
    return (total == target);
}

void work(int x) {
    int rep = 0;
    for (int i = 0; i < 1229; i++) {
        if (primes[i] > x) break;
        if (elaborate(i, x)) rep++;
    }
    cout << rep << endl;
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