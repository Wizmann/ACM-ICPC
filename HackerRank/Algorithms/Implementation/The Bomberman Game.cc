#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 222;

int n, m, t;
char board[2][SIZE][SIZE];

const int my[] = {-1, 0, 1, 0, 0};
const int mx[] = {0, 1, 0, -1, 0};

void print_board(int p) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[p][i][j] == 0) {
                putchar('.');
            } else {
                //putchar('0' + board[p][i][j]);
                putchar('O');
            }
        }
        puts("");
    }
}


int simulation(int T) {
    int p = 0;
    while (T--) {
        int q = p ^ 1;
        memset(board[q], -1, sizeof(board[q]));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[p][i][j] == 1) {
                    for (int k = 0; k < 5; k++) {
                        int ny = i + my[k];
                        int nx = j + mx[k];
                        if (0 <= ny && ny < n && 0 <= nx && nx < m) {
                            board[q][ny][nx] = 0;
                        }
                    }
                } else if (board[q][i][j] == -1) {
                    board[q][i][j] = board[p][i][j] - 1;
                    if (board[q][i][j] < 0) {
                        board[q][i][j] = 3;
                    }
                }
            }
        }
        p ^= 1;
    }
    return p;
}


int main() {
    input(n >> m >> t);
    for (int i = 0; i < n; i++) {
        scanf("%s", board[0][i]);
        
        for (int j = 0; j < m; j++) {
            if (board[0][i][j] == 'O') {
                board[0][i][j] = 2;
            } else {
                board[0][i][j] = 0;
            }
        }
    }
    if (t < 10) {
        t -= 1;
    } else {
        t = (t + 3) % 4;
    }
    int p = simulation(t);
    print_board(p);

    return 0;
}
