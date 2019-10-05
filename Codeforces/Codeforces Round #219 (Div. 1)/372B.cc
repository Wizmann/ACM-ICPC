#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <list>
#include <cassert>

using namespace std;

#define print(x) cout << x << '\n'
#define input(x) cin >> x
#define FOR(i, n) for (int i = 0; i < n; i++)

typedef long long llint;

const int SIZE = 44;

char mat[SIZE][SIZE];
int dis[SIZE][SIZE];
int dp[SIZE][SIZE][SIZE][SIZE];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, q;
    input(n >> m >> q);

    for (int i = 0; i < n; i++) {
        input(mat[i]);
        for (int j = 0; j < m; j++) {
            mat[i][j] -= '0';
        }
    }

    for (int i = 0; i < n; i++) {
        int d = 0;
        for (int j = 0; j < m; j++) {
            d++;
            if (mat[i][j] == 1) {
                d = 0;
            }
            dis[i][j] = d;
        }
    }

    for (int a = 0; a < n; a++) {
    for (int b = 0; b < m; b++) {
    for (int c = a; c < n; c++) {
    for (int d = b; d < m; d++) {
        if (c - 1 >= 0) {
            dp[a][b][c][d] += dp[a][b][c - 1][d];
        }
        if (d - 1 >= 0) {
            dp[a][b][c][d] += dp[a][b][c][d - 1];
        }
        if (c - 1 >= 0 && d - 1 >= 0) {
            dp[a][b][c][d] -= dp[a][b][c - 1][d - 1];
        }

        int r = d - b + 1;
        for (int i = c; i >= a; i--) {
            r = min(r, dis[i][d]);
            dp[a][b][c][d] += r;
        }
    }
    }
    }
    }

    int a, b, c, d;
    while (q--) {
        input(a >> b >> c >> d);
        a--;
        b--;
        c--;
        d--;
        print(dp[a][b][c][d]);
    }

    return 0;
}