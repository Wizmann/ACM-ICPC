#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int SIZE = 123;
llint dp[SIZE][SIZE];

int main() {
    int n, m, y, x;
    input(n, m, y, x);

    memset(dp, 0, sizeof(dp));
    dp[y][x] = -INF;

    for (int dy = -2; dy <= 2; dy++) {
        for (int dx = -2; dx <= 2; dx++) {
            if (abs(dy) + abs(dx) != 3) {
                continue;
            }
            int ny = y + dy;
            int nx = x + dx;
            if (0 <= ny && ny <= n && 0 <= nx && nx <= m) {
                dp[ny][nx] = -INF;
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) {
                dp[0][0] = 1;
                continue;
            }
            if (dp[i][j] <= -INF) {
                continue;
            }
            dp[i][j] += max(0LL, (i - 1) >= 0? dp[i - 1][j]: 0);
            dp[i][j] += max(0LL, (j - 1) >= 0? dp[i][j - 1]: 0);
        }
    }

    print(max(0LL, dp[n][m]));

    return 0;
}

/*

^^^^TEST^^^^
6 6 3 3
------------
6
$$$$TEST$$$$



*/
