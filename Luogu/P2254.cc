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

struct Item {
    int tm, steps;
};

struct Move {
    int st, end, dir;
};

const int my[] = {-INF, -1, 1, 0, 0};
const int mx[] = {-INF, 0, 0, -1, 1};

const int SIZE = 222;

char board[SIZE][SIZE];
int dp[SIZE][SIZE];

int main() {
    int n, m, stx, sty, k;
    input(n, m, sty, stx, k);

    for (int i = 1; i <= n; i++) {
        scanf("%s", board[i] + 1);
    }

    vector<Move> moves(k);
    for (int i = 0; i < k; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        moves[i] = {a, b, c};
    }

    memset(dp, -1, sizeof(dp));
    dp[sty][stx] = 0;

    for (const auto& mv : moves) {
        int y = -1;
        int x = -1;
        int dir = mv.dir;

        switch (mv.dir) {
        case 1: {
            y = n;
        } break;
        case 2: {
            y = 1;
        } break;
        case 3: {
            x = m;
        } break;
        case 4: {
            x = 1;
        } break;
        default:
            assert(false);
            break;
        }

        int loop1 = -1;
        int loop2 = -1;

        if (x == -1) {
            loop1 = m;
            loop2 = n;
        } else if (y == -1) {
            loop1 = n;
            loop2 = m;
        } else {
            assert(false);
        }

        int length = mv.end - mv.st + 1;

        for (int i = 1; i <= loop1; i++) {
            vector<int> nxt(loop2 + 1, -1);
            deque<Item> dq;
            for (int j = 1; j <= loop2; j++) {
                int cy = -1;
                int cx = -1;
                int v = -1;

                if (x == -1) {
                    cx = i;
                    v = cy = y + my[dir] * (j - 1);
                } else if (y == -1) {
                    cy = i;
                    v = cx = x + mx[dir] * (j - 1);
                } else {
                    assert(false);
                }

                if (cy <= 0 || cy > n || cx <= 0 || cx > m) {
                    continue;
                }

                if (board[cy][cx] == 'x') {
                    dq.clear();
                    continue;
                }

                if (!dq.empty() && abs(dq.begin()->tm - v) > length) {
                    dq.pop_front();
                }

                nxt[v] = dp[cy][cx];
                if (!dq.empty()) {
                    nxt[v] = max(nxt[v], dq.begin()->steps + abs(v - dq.begin()->tm));
                }

                if (dp[cy][cx] >= 0) {
                    while (!dq.empty() && dq.rbegin()->steps + abs(v - dq.rbegin()->tm) <= dp[cy][cx]) {
                        dq.pop_back();
                    }
                    dq.push_back({v, dp[cy][cx]});
                }
            }
            for (int j = 1; j <= loop2; j++) {
                if (x == -1) {
                    int cx = i;
                    dp[j][cx] = nxt[j];
                } else if (y == -1) {
                    int cy = i;
                    dp[cy][j] = nxt[j];
                } else {
                    assert(false);
                }
            }
        }
        /*
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (dp[i][j] == -1) {
                    printf("%c ", board[i][j]);
                } else {
                    printf("%d ", dp[i][j]);
                }
            }
            puts("");
        }
        puts("---");
        */
    }

    // puts("---");

    int maxi = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // printf("%d ", dp[i][j]);
            maxi = max(maxi, dp[i][j]);
        }
        // puts("");
    }
    print(maxi);

    return 0;
}

/*
^^^TEST^^^
3 4 1 1 1
....
.x..
....
1 3 2
-----
2
$$$TEST$$$

^^^TEST^^^
3 3 1 1 2
...
.x.
...
1 3 2
4 100 4
-----
4
$$$TEST$$$

^^^TEST^^^
4 5 4 1 3
..xx.
.....
...x.
.....
1 3 4
4 5 1
6 7 3
-----
6
$$$TEST$$$

^^^TEST^^^
10 10 5 8 5
..........
......xxxx
.....xxxxx
.....xxxxx
..........
xxxx......
..........
..........
..........
..x.......
1 5 3
6 7 1
8 11 2
12 15 3
16 17 2
------
15
$$$TEST$$$

*/
