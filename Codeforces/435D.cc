// Result: 2014-07-13 13:39:22  Wizmann  D - Special Grid    GNU C++0x  Accepted     826 ms  6400 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 444;
const int DIRS = 8;
const int INF = 0x3f3f3f3f;

const int my[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int mx[] = {0, 1, 1, 1, 0, -1, -1, -1};

int dp[DIRS][SIZE][SIZE];
char g[SIZE][SIZE];
int n, m;

inline bool inMap(int y, int x)
{
    return y >= 0 && y < n && x >= 0 && x < m;
}

inline void do_move(int &y, int &x, int dir)
{
    y += my[dir];
    x += mx[dir];
}



llint do_solve(int y, int x, int d0, int d1)
{
    llint res = 0;
    int step = 0;
    int y0, x0, y1, x1;
    y0 = y1 = y;
    x0 = x1 = x;
    if (g[y][x] == '1') {
        return 0;
    }
    while(1) {
        do_move(y0, x0, d0);
        do_move(y1, x1, d1);
        step++;
        if (!inMap(y0, x0) || !inMap(y1, x1)) {
            break;
        }
        if (g[y0][x0] == '1' || g[y1][x1] == '1') {
            break;
        }
        int d2 = (d0 + 3) % DIRS;
        int mindis = dp[d2][y0][x0];
        int dis = d0 % 2 == 0? step + 1: step * 2 + 1;
        if (dis > mindis) {
            continue;
        }
        res++;
    }
    return res;
}

llint solve()
{
    llint res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // int cnt = 0;
            // printf("(%d %d) => ", i, j);
            for (int k = 0; k < DIRS; k++) {
                int d0 = k, d1 = (k + 2) % DIRS;
                res += do_solve(i, j, d0, d1);
                // printf("%lld, ", do_solve(i, j, d0, d1));
                // cnt += do_solve(i, j, d0, d1);
            }
            // printf(" => %d\n", cnt);
        }
    }
    return res;
}

void do_mark(int y, int x)
{
    for (int i = 0; i < DIRS; i++) {
        int ny = y, nx = x;
        int step = 0;
        int opp = (i + 4) % DIRS;
        while (1) {
            ny += my[i];
            nx += mx[i];
            if (!inMap(ny, nx)) {
                break;
            }
            step++;
            dp[opp][ny][nx] = min(dp[opp][ny][nx], step);
        }
    }
}

void do_test(int y, int x, int d0)
{
    int d1 = (d0 + 2) % DIRS;
    print("TEST: " << do_solve(y, x, d0, d1));
}

int main()
{
    freopen("input.txt", "r", stdin);
    input(n >> m);
    memset(dp, INF, sizeof(dp));
    for (int i = 0; i < n; i++) {
        scanf("%s", g[i]);
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '1') {
                do_mark(i, j);
            }
        }
    }
    
    print(solve());
    return 0;
}

