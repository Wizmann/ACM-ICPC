#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1111;

char board[SIZE][SIZE];
int n, m;

void dfs(int y, int x, int idx) {
    board[y][x] = 'X';

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int ny = y + i;
            int nx = x + j;

            if (0 <= ny && ny < n && 0 <= nx && nx < m) {
                if (board[ny][nx] == 'W') {
                    dfs(ny, nx, idx);
                }
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    input(n >> m);
    for (int i = 0; i < n; i++) {
        scanf("%s", board[i]);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'W') {
                ++ans;
                dfs(i, j, ans);
            }
        }
    }
    print(ans);
    return 0;
}

