// Result: 2014-07-04 17:24:59  Accepted    1728    31MS    648K    2859 B  G++ Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 128;
const int DIRS = 4;
const int INF  = 0x3f3f3f3f;
const int mx[] = {1, 0, -1, 0};
const int my[] = {0, 1, 0, -1};

struct Point {
    int x, y, dir;
    Point(){}
    Point(int ix, int iy, int idir = 0): x(ix), y(iy), dir(idir) {}

    friend bool operator == (const Point& a, const Point& b)
    {
        return a.x == b.x && a.y == b.y;
    }

    Point move()
    {
        Point res = *this;
        res.x += mx[dir];
        res.y += my[dir];
        return res;
    }

};

int dp[SIZE][SIZE][DIRS];
int n, m, max_step;
char maze[SIZE][SIZE];
Point pst, pend;

bool inMap(const Point& p)
{
    return p.x >= 1 && p.x <= m && p.y >= 1 && p.y <= n && maze[p.y][p.x] == '.';
}

bool solve()
{
    memset(dp, INF, sizeof(dp));
    queue<Point> q;
    for (int i = 0; i < 4; i++) {
        pst.dir = i;
        q.push(pst);
        dp[pst.y][pst.x][i] = 0;
    }
    while (!q.empty()) {
        Point now = q.front();
        q.pop();
        if (now == pend) {
            return true;
        }

        // printf("%d %d\n", now.x, now.y);
        Point no_turn = now.move();
        if (inMap(no_turn) && 
                dp[no_turn.y][no_turn.x][no_turn.dir] > dp[now.y][now.x][now.dir]) {
            dp[no_turn.y][no_turn.x][no_turn.dir] = dp[now.y][now.x][now.dir];
            if (dp[no_turn.y][no_turn.x][no_turn.dir] <= max_step) {
                q.push(no_turn);
                if (no_turn == pend) {
                    return true;
                }
            }
        }

        for (int i = 0; i < DIRS; i++) {
            if (i == now.dir) {
                continue;
            }
            Point do_turn = now;
            do_turn.dir = i;
            if (!inMap(do_turn)) {
                continue;
            }
            if (dp[now.y][now.x][i] > dp[now.y][now.x][now.dir] + 1) {
                dp[now.y][now.x][i] = dp[now.y][now.x][now.dir] + 1;
                if (dp[now.y][now.x][i] <= max_step) {
                    q.push(do_turn);
                }
            }
        }
    }
    for (int i = 0; i < DIRS; i++) {
        if (dp[pend.y][pend.x][i] <= max_step) {
            return true;
        }
    }
    return false;
}


int main()
{
    freopen("input.txt", "r", stdin);
    int T, x1, y1, x2, y2;
    input(T);
    while (T--) {
        input(n >> m);
        for (int i = 1; i <= n; i++) {
            scanf("%s", maze[i] + 1);
        }
        input(max_step >> x1 >> y1 >> x2 >> y2);
        pst  = Point(x1, y1);
        pend = Point(x2, y2);
        puts(solve()? "yes": "no");
    }
    return 0;
}
