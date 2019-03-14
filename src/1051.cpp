#include <iostream>
#include <cstdio>

using namespace std;

void work(int n, double diameter, int revolution, double time) {
    double distance = diameter * 3.1415927 * revolution / 12 / 5280;
    double MPH = distance / (time / 3600);
    printf("Trip #%d: %.2f %.2f\n", n, distance, MPH);
}

int main() {
    int n = 0;
    double diameter;
    int revolution;
    double time;

    cin >> diameter >> revolution >> time;
    while (revolution != 0) {
        n++;
        work(n, diameter, revolution, time);
        cin >> diameter >> revolution >> time;
    }
    return 0;
}