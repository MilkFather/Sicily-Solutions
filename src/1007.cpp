#include <string>
#include <iostream>

using namespace std;

void work(int col) {
    string encrypted;
    cin >> encrypted;
    int row = encrypted.length() / col;
    char matrix[row][col];
    bool right = true;
    int idx = 0;
    for (int r = 0; r < row; r++) {
        if (right) {
            right = false;
            for (int c = 0; c < col; c++) {
                matrix[r][c] = encrypted[idx++];
            }
        } else {
            right = true;
            for (int c = col - 1; c >= 0; c--) {
                matrix[r][c] = encrypted[idx++];
            }
        }
    }
    string decrypted = "";
    for (int c = 0; c < col; c++) {
        for (int r = 0; r < row; r++) {
            decrypted += matrix[r][c];
        }
    }
    cout << decrypted << endl;
}

int main() {
    int c;
    cin >> c;
    while (c > 0) {
        work(c);
        cin >> c;
    }
    return 0;
}