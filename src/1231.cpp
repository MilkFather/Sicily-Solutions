#include <iostream>
#include <string>

using namespace std;

int primes[79000];

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
    for (int i = 3; i <= 1000000; i += 2) {
        if (isprime(i, nprime)) {
            primes[nprime] = i;
            nprime++;
        }
    }
}

bool longDivision(string number, int divisor) { 
    string ans; 
    int idx = 0; 
    int temp = number[idx] - '0'; 
    while (temp < divisor) {
        if (idx == number.size() - 1) break;
        temp = temp * 10 + (number[++idx] - '0'); 
    }
    while (number.size() > idx) {
        ans += (temp / divisor) + '0';
        if (idx == number.size() - 1) return (temp % divisor) == 0;
        else temp = (temp % divisor) * 10 + number[++idx] - '0'; 
    } 
    return temp == 0;
}

void work(string K, int L) {
    for (int i = 0; primes[i] < L && i < 78498; i++) {
        if (longDivision(K, primes[i])) {
            cout << "BAD " << primes[i] << endl;
            return;
        }
    }
    cout << "GOOD" << endl;
}

int main() {
    calcprimes();
    string K;
    int L;
    cin >> K >> L;
    while (K != "0" && L != 0) {
        work(K, L);
        cin >> K >> L;
    }
    return 0;
}