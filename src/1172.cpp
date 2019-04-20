#include <iostream>
#include <vector>

#define BLANK 0
#define QUEEN 1
#define KNIGHT 2
#define PAWN 3

using namespace std;

bool safe[1000][1000];
int board[1000][1000];
int nsafe;
int row, col;

void unsafe(int r, int c) {
    if (safe[r][c]) {
        safe[r][c] = false;
        nsafe--;
    }
}

void init(int _row, int _col) {
    row = _row; col = _col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            safe[i][j] = true;
            board[i][j] = BLANK;
        }
    }
    nsafe = row * col;
}

void do_queen(int r, int c) {
    unsafe(r, c);
    int i;
    // right
    i = 1;
    while (c + i < col && board[r][c + i] == BLANK) {
        unsafe(r, c + i);
        i++;
    }
    // left
    i = 1;
    while (c - i >= 0 && board[r][c - i] == BLANK) {
        unsafe(r, c - i);
        i++;
    }
    // top
    i = 1;
    while (r - i >= 0 && board[r - i][c] == BLANK) {
        unsafe(r - i, c);
        i++;
    }
    // down
    i = 1;
    while (r + i < row && board[r + i][c] == BLANK) {
        unsafe(r + i, c);
        i++;
    }
    // top-left
    i = 1;
    while (r - i >= 0 && c - i >= 0 && board[r - i][c - i] == BLANK) {
        unsafe(r - i, c - i);
        i++;
    }
    // top-right
    i = 1;
    while (r - i >= 0 && c + i < col && board[r - i][c + i] == BLANK) {
        unsafe(r - i, c + i);
        i++;
    }
    // bottom-left
    i = 1;
    while (r + i < row && c - i >= 0 && board[r + i][c - i] == BLANK) {
        unsafe(r + i, c - i);
        i++;
    }
    // bottom-right
    i = 1;
    while (r + i < row && c + i < col && board[r + i][c + i] == BLANK) {
        unsafe(r + i, c + i);
        i++;
    }
}

void do_knight(int r, int c) {
    unsafe(r, c);
    if (r - 1 >= 0 && c - 2 >= 0 && board[r - 1][c - 2] == BLANK) unsafe(r - 1, c - 2);
    if (r - 2 >= 0 && c - 1 >= 0 && board[r - 2][c - 1] == BLANK) unsafe(r - 2, c - 1);
    if (r - 2 >= 0 && c + 1 < col && board[r - 2][c + 1] == BLANK) unsafe(r - 2, c + 1);
    if (r - 1 >= 0 && c + 2 < col && board[r - 1][c + 2] == BLANK) unsafe(r - 1, c + 2);
    if (r + 1 < row && c + 2 < col && board[r + 1][c + 2] == BLANK) unsafe(r + 1, c + 2);
    if (r + 2 < row && c + 1 < col && board[r + 2][c + 1] == BLANK) unsafe(r + 2, c + 1);
    if (r + 2 < row && c - 1 >= 0 && board[r + 2][c - 1] == BLANK) unsafe(r + 2, c - 1);
    if (r + 1 < row && c - 2 >= 0 && board[r + 1][c - 2] == BLANK) unsafe(r + 1, c - 2);
}

void do_pawn(int r, int c) {
    unsafe(r, c);
}

void work(int T) {
    // queen
    int nqueen;
    cin >> nqueen;
    vector<int> qy, qx;
    for (int i = 0; i < nqueen; i++) {
        int y, x;
        cin >> y >> x;
        qy.push_back(y); qx.push_back(x);
        board[y - 1][x - 1] = QUEEN;
    }
    // knight
    int nknight;
    cin >> nknight;
    vector<int> ky, kx;
    for (int i = 0; i < nknight; i++) {
        int y, x;
        cin >> y >> x;
        ky.push_back(y); kx.push_back(x);
        board[y - 1][x - 1] = KNIGHT;
    }
    // pawn
    int npawn;
    cin >> npawn;
    vector<int> py, px;
    for (int i = 0; i < npawn; i++) {
        int y, x;
        cin >> y >> x;
        py.push_back(y); px.push_back(x);
        board[y - 1][x - 1] = PAWN;
    }

    // do
    for (int i = 0; i < qy.size(); i++) {
        do_queen(qy[i] - 1, qx[i] - 1);
    }
    for (int i = 0; i < ky.size(); i++) {
        do_knight(ky[i] - 1, kx[i] - 1);
    }
    for (int i = 0; i < py.size(); i++) {
        do_pawn(py[i] - 1, px[i] - 1);
    }

    cout << "Board " << T << " has " << nsafe << " safe squares." << endl;
}

int main() {
    int r, c;
    int kase = 1;
    cin >> r >> c;
    while (r != 0 || c != 0) {
        init(r, c);
        work(kase);
        kase++;
        cin >> r >> c;
    }
    return 0;
}