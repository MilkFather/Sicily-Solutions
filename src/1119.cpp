#include <iostream>
#include <cmath>

using namespace std;

void work(int yr) {
    yr = (yr / 10) - 194;
    int i = 0;
    double sum = 0;
    while (true) {
        sum += log2(i + 1);
        if (sum > (1 << yr)) break;
        i++;
    }
    cout << i << endl;
}

int main() {
    int y;
    cin >> y;
    while (y > 0) {
        work(y);
        cin >> y;
    }
    return 0;
}