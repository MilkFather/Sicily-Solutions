#include <iostream>

using namespace std;

int cmp1(int usrw, int m1, int m2, int m3) {
    /* (0, weight1) */
    int min = usrw, idx = 0;
    if (min > m1) {
        min = m1; idx = 1;
    }
    if (min > m2) {
        min = m2; idx = 2;
    }
    if (min > m3) {
        min = m3; idx = 3;
    }
    return idx;
}

int cmp2(int usrw, int m2, int m3) {
    /* (weight1, weight2) */
    int min = usrw, idx = 0;
    if (min > m2) {
        min = m2; idx = 2;
    }
    if (min > m3) {
        min = m3; idx = 3;
    }
    return idx;
}

int cmp3(int usrw, int m3) {
    /* (weight2, weight3) */
    int min = usrw, idx = 0;
    if (min > m3) {
        min = m3; idx = 3;
    }
    return idx;
}

void work(int k, int weight1, int rate1) {
    int weight2, rate2, weight3, rate3, rate4;
    cin >> weight2 >> rate2 >> weight3 >> rate3 >> rate4;
    int min1 = (weight1 + 1) * rate2;
    int min2 = (weight2 + 1) * rate3;
    int min3 = (weight3 + 1) * rate4;

    cout << "Set number " << k << ":" << endl;

    int w;
    cin >> w;
    while (w > 0) {
        if (0 <= w && w <= weight1) {
            int m = cmp1(w * rate1, min1, min2, min3);
            if (m == 0) cout << "Weight (" << w << ") has best price $" << (w * rate1) << " (add 0 pounds)" << endl;
            if (m == 1) cout << "Weight (" << w << ") has best price $" << min1 << " (add " << (weight1 + 1 - w) << " pounds)" << endl;
            if (m == 2) cout << "Weight (" << w << ") has best price $" << min2 << " (add " << (weight2 + 1 - w) << " pounds)" << endl;
            if (m == 3) cout << "Weight (" << w << ") has best price $" << min3 << " (add " << (weight3 + 1 - w) << " pounds)" << endl;
        } else if ((weight1 + 1) <= w && w <= weight2) {
            int m = cmp2(w * rate2, min2, min3);
            if (m == 0) cout << "Weight (" << w << ") has best price $" << (w * rate2) << " (add 0 pounds)" << endl;
            if (m == 2) cout << "Weight (" << w << ") has best price $" << min2 << " (add " << (weight2 + 1 - w) << " pounds)" << endl;
            if (m == 3) cout << "Weight (" << w << ") has best price $" << min3 << " (add " << (weight3 + 1 - w) << " pounds)" << endl;
        } else if ((weight2 + 1) <= w && w <= weight3) {
            int m = cmp3(w * rate3, min3);
            if (m == 0) cout << "Weight (" << w << ") has best price $" << (w * rate3) << " (add 0 pounds)" << endl;
            if (m == 3) cout << "Weight (" << w << ") has best price $" << min3 << " (add " << (weight3 + 1 - w) << " pounds)" << endl;
        } else {
            cout << "Weight (" << w << ") has best price $" << (w * rate4) << " (add 0 pounds)" << endl;
        }
        cin >> w;
    }
    cout << endl;
}

int main() {
    int weight1, rate1;
    int k = 0;
    while(cin >> weight1 >> rate1) {
        k++;
        work(k, weight1, rate1);
    }
    return 0;
}