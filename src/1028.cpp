#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string longDivision(string number, int divisor) { 
    string ans; 
    int idx = 0; 
    int temp = number[idx] - '0'; 
    while (temp < divisor) 
       temp = temp * 10 + (number[++idx] - '0'); 
    while (number.size() > idx) 
    {
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[++idx] - '0'; 
    } 
    if (ans.length() == 0) 
        return "0"; 
    return ans; 
}

void work(int id) {
    string n;
    cin >> n;
    char end = n[n.length() - 1];
    int res = 1;
    while (n != "0" && (end == '0' || end == '2' || end == '4' || end == '6' || end == '8')) {
        res++;
        n = longDivision(n, 2);
        end = n[n.length() - 1];
    }
    if (id != 1) cout << endl;
    cout << "Case " << id << ": " << res << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        work(i);
    }
    return 0;
}