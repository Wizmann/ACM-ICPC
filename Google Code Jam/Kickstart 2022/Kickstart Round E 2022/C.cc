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
const int NINF = 0xf3f3f3f3;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;
const llint NINFLL = 0xf3f3f3f3f3f3f3f3LL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int N = 12;
const int P = 10;

struct Point {
    int y, x, status;
};

struct Customer {
    int id;
    int cost;
};

const int my[] = {-1, 0, 0, 1, 0};
const int mx[] = {0, 1, -1, 0, 0};

int n, p, m, st_y, st_x;
vector<function<llint(llint)>> fs;

Customer board[N][N];

llint dp[2][N][N][1 << P];

llint solve() {
    memset(dp, NINF, sizeof(dp));

    queue<Point> q[2];
    q[0].push({st_y, st_x, 0});
    dp[0][st_y][st_x][0] = 0;

    int ptr = 0;
    for (int step = 0; step < m; step++) {
        memset(dp[ptr ^ 1], NINF, sizeof(dp[ptr ^ 1]));
        while (!q[ptr].empty()) {
            Point pp = q[ptr].front();
            q[ptr].pop();

            int y = pp.y;
            int x = pp.x;
            int s = pp.status;
            llint c = dp[ptr][y][x][s];
            // print(step, y, x, s, c);

            for (int i = 0; i < 5; i++) {
                int ny = y + my[i];
                int nx = x + mx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
                    continue;
                }

                int ns = s;
                llint nc = fs[i](c);

                if (nc > dp[ptr ^ 1][ny][nx][ns]) {
                    dp[ptr ^ 1][ny][nx][ns] = nc;
                    q[ptr ^ 1].push({ny, nx, ns});
                }

                if (board[ny][nx].id != -1) {
                    int nid = board[ny][nx].id;
                    if (!(ns & (1 << nid))) {
                        ns |= 1 << nid;
                        nc += board[ny][nx].cost;
                    }
                }

                if (nc > dp[ptr ^ 1][ny][nx][ns]) {
                    dp[ptr ^ 1][ny][nx][ns] = nc;
                    q[ptr ^ 1].push({ny, nx, ns});
                }
            }
        }
        ptr ^= 1;
    }

    llint res = NINFLL;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res = max(res, dp[ptr][i][j][(1 << p) - 1]);
        }
    }
    return res;
}

int main() {
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        input(n, p, m, st_y, st_x);
        // print(n, p, m, st_y, st_x);

        st_y--;
        st_x--;

        memset(board, -1, sizeof(board));
        fs.clear();

        char op[5];
        int c;
        for (int i = 0; i < 4; i++) {
            scanf("%s%d", op, &c);
            switch (op[0]) {
                case '+': {
                    fs.push_back([=](llint x) { return x + c; });
                    break;
                }
                case '-': {
                    fs.push_back([=](llint x) { return x - c; });
                    break;
                }
                case '*': {
                    fs.push_back([=](llint x) { return x * c; });
                    break;
                }
                case '/': {
                    fs.push_back([=](llint x) { 
                        llint cc = c;
                        if (x == 0) {
                            return 0LL;
                        } else if (x * cc > 0) {
                            return x / cc;
                        } else {
                            x = -(abs(x));
                            cc = abs(cc);
                            return (x - cc + 1) / cc;
                        }
                    });
                    break;
                }
                default: {
                    assert(false);
                }
            }
        }
        fs.push_back([=](llint x) { return x; });

        int y, x;
        for (int i = 0; i < p; i++) {
            input(y, x, c);
            y--;
            x--;
            board[y][x] = {i, c};
        }

        llint res = solve();

        printf("Case #%d: ", case_ + 1);
        if (res <= NINFLL) {
            puts("IMPOSSIBLE");
        } else {
            print(res);
        }
    }

    return 0;
}

/*

^^^TEST^^^
2
3 0 1 1 2
+ 1
- 2
+ 3
/ 4
3 0 1 2 3
- 2
- 2
- 2
- 2
-----
Case #1: 3
Case #2: 0
$$$TEST$$$

^^^TEST^^^
3
3 1 3 1 3
+ 4
- 2
* 1
/ 4
1 2 4
2 2 1 1 2
+ 2
+ 3
* 2
* 1
1 1 4
2 2 1
3 1 2 1 3
+ 1
* 1
- 3
/ 4
2 2 2
-----
Case #1: 8
Case #2: IMPOSSIBLE
Case #3: 1
$$$TEST$$$

*/
