#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 10;
const int N = 8;
const int INF = 0x3f3f3f3f;

char board[SIZE][SIZE];

bool in_board(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < N;
}

int do_move(int y, int x, function<void(int&, int&)> fun) {
    int step = 0;
    while (1) {
        fun(y, x);
        if (!in_board(y, x)) {
            break;
        }
        if (board[y][x] != '.') {
            return INF;
        }
        step++;
    }
    return step;
}

int main() {
    freopen("a.txt", "r", stdin);
    for (int i = 0; i < N; i++) {
        scanf("%s", board[i]);
    }

    int min_a = INF;
    int min_b = INF;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 'W') {
                min_a = min(min_a, do_move(i, j, [](int &y, int &x) { y--; }));
            } else if (board[i][j] == 'B') {
                min_b = min(min_b, do_move(i, j, [](int &y, int &x) { y++; }));
            }
        }
    }

    if (min_a <= min_b) {
        puts("A");
    } else {
        puts("B");
    }
    return 0;
}
