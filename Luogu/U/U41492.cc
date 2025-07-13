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

const int N = 123456;
const int M = 123456;

int color_cnt = 0;
vector<int> colors;
vector<int> counts;
vector<int> dp;
vector<int> heavy;
vector<int> g[N];

int dfs1(int pre, int cur) {
    int cnt = 1;

    int maxi = -1;
    int maxv = -1;
    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        int sub = dfs1(cur, nxt);
        if (sub > maxv) {
            maxi = nxt;
            maxv = sub;
            heavy[cur] = maxi;
        }
        cnt += sub;
    }
    return cnt;
}

void DoAddColor(int color, int delta) {
    // assert(color != 0);
    if (dp[color] == 0 && delta == 1) {
        color_cnt++;
    } else if (dp[color] == 1 && delta == -1) {
        color_cnt--;
    }
    dp[color] += delta;
}

void DoAdd(int pre, int cur, int delta, int skip) {
    DoAddColor(colors[cur], delta);
    for (auto nxt : g[cur]) {
        if (nxt == pre || nxt == skip) {
            continue;
        }
        DoAdd(cur, nxt, delta, skip);
    }
}

void dfs2(int pre, int cur, bool keep) {
    for (int nxt : g[cur]) {
        if (nxt == pre || nxt == heavy[cur]) {
            continue;
        }
        dfs2(cur, nxt, false);
    }

    if (heavy[cur] > 0) {
        dfs2(cur, heavy[cur], true);
    }

    DoAdd(pre, cur, 1, heavy[cur]);
    counts[cur] = color_cnt;

    if (!keep) {
        DoAdd(pre, cur, -1, -1);
    }
}

int main() {
    int n;
    input(n);

    colors = vector<int>(N + 1, 0);
    counts = vector<int>(N + 1, 0);
    heavy = vector<int>(N + 1, -1);
    dp = vector<int>(M + 1, 0);

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &colors[i]);
    }

    dfs1(-1, 1);
    dfs2(-1, 1, false);

    int q;
    input(q);

    for (int i = 0; i < q; i++) {
        scanf("%d", &a);
        printf("%d\n", counts[a]);
    }

    return 0;
}

/*

^^^TEST^^^
5
1 2
1 3
2 4
2 5
1 2 2 3 3
5
1
2
3
4
5
-----
3
2
1
1
1
$$$TEST$$$

^^^TEST^^^
5
1 2
2 3
3 4
4 5
1 2 2 3 3
3
1
3
5
-----
3
2
1
$$$TEST$$$

^^^TEST^^^
4
1 2
1 3
1 4
1 1 2 2
2
1
3
-----
2
1
$$$TEST$$$

^^^TEST^^^
7
1 2
1 3
2 4
2 5
3 6
3 7
1 2 2 3 3 4 4
4
1
2
3
4
-----
4
2
2
1
$$$TEST$$$

^^^TEST^^^
20
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
5 10
5 11
6 12
7 13
7 14
13 15
13 16
10 17
10 18
18 19
18 20
1 2 3 4 2 3 1 5 5 4 4 6 2 3 1 2 5 1 1 2
5
1
2
10
13
18
-----
6
4
4
2
2
$$$TEST$$$

*/
