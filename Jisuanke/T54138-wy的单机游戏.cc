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

#define print(x) cout << x << endl
#define input(x) cin >> x

const int N = 123;

struct Point {
    int y, x;
};


char board[N][N];
int dp[N][N];
Point mp[N][N];
char inq[N][N];

const int my[] = {-1, 0, 1, 0};
const int mx[] = {0, 1, 0, -1};

int solve(int n, int m) {
    memset(dp, INF, sizeof(dp));
    memset(mp, -1, sizeof(mp));
    memset(inq, 0, sizeof(inq));

    map<char, vector<Point> > portals;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] >= 'A' && board[i][j] <= 'Z') {
                portals[board[i][j]].push_back({i, j});
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (portals['A' + i].size() == 0) {
            continue;
        }
        Point p1 = portals['A' + i][0];
        Point p2 = portals['A' + i][1];

        mp[p1.y][p1.x] = p2;
        mp[p2.y][p2.x] = p1;
    }

    queue<Point> q;
    dp[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        inq[cur.y][cur.x] = 0;
        // print(cur.y << ' ' << cur.x << ' ' << dp[cur.y][cur.x]);

        for (int i = 0; i < 4; i++) {
            int ny = cur.y + my[i];
            int nx = cur.x + mx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || board[ny][nx] == '#') {
                continue;
            }
            if (mp[ny][nx].y != -1) {
                int ny_ = mp[ny][nx].y;
                int nx_ = mp[ny][nx].x;
                ny = ny_;
                nx = nx_;
            }
            if (dp[ny][nx] > dp[cur.y][cur.x] + 1) {
                dp[ny][nx] = dp[cur.y][cur.x] + 1;
                if (inq[ny][nx] == 0) {
                    q.push({ny, nx});
                    inq[ny][nx] = 1;
                }
            }
        }
    }
    return dp[n - 1][m - 1];
}

int main() {
#ifndef __CPRUN__
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s", board[i]);
    }

    int res = solve(n, m);
    if (res >= INF) {
        puts("Game Over.");
    } else {
        printf("%d\n", res);
    }

    return 0;
}

/*

^^^TEST^^^
3 3
.#.
A#A
.#.
-----
2
$$$TEST$$$

^^^TEST^^^
3 3
.#.
.#.
.#.
-----
Game Over.
$$$TEST$$$

^^^TEST^^^
3 3
.#.
.#.
ZZ.
-----
3
$$$TEST$$$

^^^TEST^^^
3 3
.#A
.#.
ZZA
-----
5
$$$TEST$$$

^^^TEST^^^
1 6
.AABB.
-----
3
$$$TEST$$$

^^^TEST^^^
2 6
.AAB..
B###..
-----
4
$$$TEST$$$

^^^TEST^^^
3 3
.#A
A##
...
-----
Game Over.
$$$TEST$$$

*/
