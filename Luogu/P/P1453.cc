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

const int SIZE = 112345;

vector<int> ps;
vector<int> g[SIZE];
map<int, int> sub[2];

bool dfs1(int pre, int cur, vector<int>& path, vector<bool>& visited) {
    path.push_back(cur);
    if (visited[cur]) {
        return true;
    }
    visited[cur] = true;

    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        if (dfs1(cur, nxt, path, visited)) {
            return true;
        }
    }

    path.pop_back();
    visited[cur] = false;
    return false;
}

int dfs2(int pre, int cur, bool flag, const set<int>& route) {
    int res = 0;
    if (flag) {
        res += ps[cur];
    }

    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        if (route.count(nxt)) {
            continue;
        }

        int maxi = 0;
        maxi = max(maxi, dfs2(cur, nxt, false, route));
        if (!flag) {
            maxi = max(maxi, dfs2(cur, nxt, true, route));
        }
        res += maxi;
    }

    return res;
}

int main() {
    int n;
    input(n);

    ps.resize(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &ps[i]);
    }

    int a, b;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    double k;
    scanf("%lf", &k);

    vector<int> path;
    vector<bool> visited(n, false);
    dfs1(-1, 0, path, visited);

    vector<int> route;
    int st = path.back();
    do {
        route.push_back(path.back());
        path.pop_back();
    } while (path.back() != st);

    set<int> routest(route.begin(), route.end());
    assert(routest.size() == route.size());
    assert(route.size() >= 3);
    for (auto cur : route) {
        sub[0][cur] = dfs2(-1, cur, false, routest);
        sub[1][cur] = dfs2(-1, cur, true, routest);
    }

    int m = route.size();
    vector<int> dp[2];
    int maxi = 0;

    for (int first = 0; first < 2; first++) {
        dp[0] = vector<int>(m, 0);
        dp[1] = vector<int>(m, 0);

        if (first) {
            dp[1][0] = sub[1][route[0]];
        } else {
            dp[0][0] = sub[0][route[0]];
        }

        for (int i = 1; i < m; i++) {
            dp[0][i] = max(dp[0][i], dp[0][i - 1] + sub[0][route[i]]);
            dp[0][i] = max(dp[0][i], dp[1][i - 1] + sub[0][route[i]]);

            if (i != m - 1) {
                dp[1][i] = max(dp[1][i], dp[0][i - 1] + sub[1][route[i]]);
            } else {
                if (first) {
                    // pass
                } else {
                    dp[1][i] = max(dp[1][i], dp[0][i - 1] + sub[1][route[i]]);
                }
            }
        }
        maxi = max(maxi, dp[0][m - 1]);
        maxi = max(maxi, dp[1][m - 1]);
    }

    printf("%.1lf\n", k * maxi);

    return 0;
}

/*

^^^TEST^^^
4
1 2 1 5
0 1
0 2
1 2
1 3
2
-----
12.0
$$$TEST$$$

^^^TEST^^^
3
1 2 5
0 1
0 2
1 2
3
-----
15.0
$$$TEST$$$

^^^TEST^^^
4
1 2 5 8
0 1
1 2
2 3
3 0
3
-----
30.0
$$$TEST$$$

^^^TEST^^^
5
1 2 5 8 10
0 1
1 2
2 3
3 0
3 4
3.14
-----
50.2
$$$TEST$$$

^^^TEST^^^
5
1 20 5 8 10
0 1
1 2
2 3
3 0
3 4
3.14
-----
94.2
$$$TEST$$$


^^^TEST^^^
5
1 3 5 8 10
0 1
0 4
1 2
1 3
2 3
3.14
-----
56.5
$$$TEST$$$

^^^TEST^^^
6
1 3 5 8 10 7
0 1
0 4
1 2
1 3
2 3
3 5
0.66
-----
14.5
$$$TEST$$$

^^^TEST^^^
5 1 2 3 4 5 0 1 2 3 2 4 0 2 3 4 9.0
-----
63.0
$$$TEST$$$


^^^TEST^^^
8
3 5 4 1 4 4 3 4
0 1
1 2
2 3
3 0
5 0
6 5
1 7
1 8
1.11111
-----
15.6
$$$TEST$$$

^^^TEST^^^
8
1 1 1 1 1 1 1 1
0 1
1 2
2 3
3 0
5 0
6 5
0 7
0 8
1.11111
-----
4.4
$$$TEST$$$

^^^TEST^^^
8
3 3 2 2 2 4 5 4
0 1
1 2
2 3
3 0
5 0
6 5
0 7
0 8
1.11111
-----
15.6
$$$TEST$$$

*/
