#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename... T, typename X> void print(X&& x, T... args) {
    cout << x << " ";
    print(args...);
}

int input() { return 0; }

template <typename... T, typename X> int input(X& x, T&... args) {
    if (!(cin >> x))
        return 0;
    return input(args...) + 1;
}

struct Point {
    int pos;
    int score;
};

const int SIZE = 1111;
int dp[SIZE][SIZE];

int solve(int n, vector<Point> ps) {
    sort(ps.begin(), ps.end(), [](const Point& p1, const Point& p2) {
        return p1.pos < p2.pos;
    });

    memset(dp, -INF, sizeof(dp));

    for (int i = 0; i < n; i++) {
        dp[i][i] = ps[i].score;
        int k = i;
        int maxi = 0;
        for (int j = i + 1; j < n; j++) {
            while (k >= 0 && ps[j].pos - ps[i].pos >= ps[i].pos - ps[k].pos) {
                maxi = max(maxi, dp[k][i]);
                k--;
            }

            dp[i][j] = max(dp[i][j], maxi + ps[j].score);
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

int main() {
    int n;
    input(n);

    vector<Point> ps;
    ps.resize(n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &ps[i].pos, &ps[i].score);
    }

    int a = solve(n, ps);

    for (int i = 0; i < n; i++) {
        ps[i].pos *= -1;
    }
    int b = solve(n, ps);

    print(max(a, b));

    return 0;
}

/*
^^^TEST^^^^
2
1 1
2 2
-----
3
$$$TEST$$$$

^^^TEST^^^^
3
1 1
10 2
11 3
-----
6
$$$TEST$$$$

^^^TEST^^^^
4
4 8
5 6
7 6
10 5
-----
25
$$$TEST$$$$

^^^TEST^^^^
4
1 1
10000 2
100000 3
1000000 4
-----
10
$$$TEST$$$$

^^^TEST^^^^
4
1 1
10000 2
11000 3
11100 4
-----
10
$$$TEST$$$$

^^^TEST^^^
6
5 6
1 1
10 5
7 6
4 8
8 10
-----
25
$$$TEST$$$

*/
