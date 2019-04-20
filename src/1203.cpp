#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string getMul(string a, string b) {
    int n1 = a.size(); 
    int n2 = b.size(); 
    if (n1 == 0 || n2 == 0) {
        return "0"; 
    }
    vector<int> result(n1 + n2, 0); 
   
    int i_n1 = 0;  
    int i_n2 = 0;  
    
    for (int i = n1 - 1; i >= 0; i--) { 
        int carry = 0; 
        int n1 = a[i] - '0'; 
        i_n2 = 0;              
        for (int j = n2 - 1; j >= 0; j--) { 
            int n2 = b[j] - '0'; 
            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
            carry = sum/10; 
            result[i_n1 + i_n2] = sum % 10;
            i_n2++; 
        } 
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
        i_n1++; 
    } 
    while (result.size() > 1 && result.back() == 0)
        result.pop_back();
    reverse(result.begin(), result.end());
    string s = "";
    for (int i = 0; i < result.size(); i++) {
        s += result[i] + '0';
    }
    return s;
} 

bool cmp(string a, string b) {
    for (int i = 1; i <= b.length(); i++) {
        if (a[a.length() - i] != b[b.length() - i]) return false;
    }
    return true;
}

void work() {
    string t;
    cin >> t;
    
    string res = "";
    // starting from the least significant bit
    for (int i = 0; i < t.length() - 1; i++) {
        for (int j = 0; j <= 9; j++) {
            string tmp = to_string(j) + res;
            string tmpr = getMul(getMul(tmp, tmp), tmp);
            if (cmp(tmpr, t.substr(t.length() - i - 1))) {
                res = tmp;
                break;
            }
        }
    }
    
    for (int j = 1; j <= 9; j++) {
        string tmp = to_string(j) + res;
        string tmpr = getMul(getMul(tmp, tmp), tmp);
        if (cmp(tmpr, t)) {
            res = tmp;
            break;
        }
    }
    
    while (res.front() == '0' && res.length() > 1) res = res.substr(1);
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        work();
    }
    return 0;
}