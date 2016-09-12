#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 15;

const int mx[] = {-2, -2, 1, -1};
const int my[] = {1, -1, -2, -2};

int board[SIZE][SIZE];

int dfs(int y, int x) {
    if (board[y][x] != -1) {
        return board[y][x];
    }

    int res = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + mx[i];
        int ny = y + my[i];
        if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) {
            continue;
        }
        int t = dfs(nx, ny);
        res |= (!t);
    }
    return board[y][x] = res;
}



void init() {
    memset(board, -1, sizeof(board));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = dfs(i, j);
        }
    }
}

int main() {
    init();
    int T, x, y;
    input(T);
    while (T--) {
        input(x >> y);
        int r = board[y - 1][x - 1];
        if (r) {
            puts("First");
        } else {
            puts("Second");
        }
    }
    return 0;
}

