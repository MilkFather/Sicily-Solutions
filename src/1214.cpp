#include <iostream>
#include <cmath>

using namespace std;

int stored[33] = {-1, 
1, 1, 2, 2, 4, 4, 8, 8, 
16, 16, 32, 32, 64, 64, 128, 128, 
256, 256, 512, 512, 1024, 1024, 2048, 2048,
4096, 4096, 8192, 8192, 16384, 16384, 32768, 32768};

int make_loopback(int raw, int totallen) {
    int rev = 0;
    int rawb = raw;
    while (rawb > 0) {
        rev <<= 1;
        rev |= (rawb & 1);
        rawb >>= 1;
    }
    for (int i = (int)log2(rev) + 1; i < totallen; i++) rev <<= 1;
    rev |= raw;
    return rev;
}

int main() {
    uint32_t x;
    cin >> x;
    // what is the length of x in binary form?
    int d = (int)log2(x) + 1;
    int cnt = 0;
    // any number that is shorter than x must counts
    for (int i = 1; i < d; i++) cnt += stored[i];
    // for the number that is as long as x...
    for (int i = 1; i < (1 << ((d + 1) / 2)); i += 2) {
        if (make_loopback(i, d) <= x) cnt++;
    }
    cout << cnt << endl;
    return 0;
}