#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 54;

const int mx[] = {0, 1, 0, -1};
const int my[] = {-1, 0, 1, 0};

int n, m;
char g[SIZE][SIZE];
char visit[SIZE][SIZE];

bool do_dfs(int y, int x, char c, int dir) {
    if (visit[y][x]) {
        return true;
    }
    visit[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + my[i];
        int nx = x + mx[i];
        if (nx < 0 || nx >= m 
                || ny < 0 || ny >= n 
                || g[ny][nx] != c
                || (dir != -1 && i == (dir + 2) % 4)) {
            continue;
        }
        if (do_dfs(ny, nx, c, i)) {
            return true;
        }
    }
    return false;
}

bool dfs(int y, int x) {
    char c = g[y][x];
    return do_dfs(y, x, c, -1);
}

int main() {
    input(n >> m);
    memset(g, 0, sizeof(g));
    memset(visit, 0, sizeof(visit));

    for (int i = 0; i < n; i++) {
        input(g[i]);
    }
    try {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visit[i][j]) {
                    bool res = dfs(i, j);
                    if (res) {
                        print("Yes");
                        throw "Got it";
                    }
                }
            }
        }
        print("No");
    } catch (...) {
        // pass
    }
    return 0;
}