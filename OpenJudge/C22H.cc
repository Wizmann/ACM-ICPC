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

const int SIZE = 151234;

vector<int> values;
vector<int> maxsub;
vector<int> subsize;
vector<int> g[SIZE];
vector<int> ans;
vector<int> cnt;
int maxn = 0;

int dfs(int pre, int cur) {
    int cnt = 1;
    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }

        int sub = dfs(cur, nxt);
        cnt += sub;
        if (subsize[maxsub[cur]] < sub) {
            maxsub[cur] = nxt;
        }
    }
    return subsize[cur] = cnt;
}

void DoAdd(int pre, int cur, int d, int ignore) {
    cnt[values[cur]] += d;
    if (cnt[values[cur]] > maxn) {
        maxn = cnt[values[cur]];
    }

    for (auto nxt : g[cur]) {
        if(nxt == pre || nxt == ignore) {
            continue;
        }
        DoAdd(cur, nxt, d, ignore);
    }
}

void dfs2(int pre, int cur, bool keep) {
    for (auto nxt : g[cur]) {
        if (nxt == pre || nxt == maxsub[cur]) {
            continue;
        }
        dfs2(cur, nxt, false);
    }

    int ignore = -1;
    if (maxsub[cur]) {
        dfs2(cur, maxsub[cur], true);
        ignore = maxsub[cur];
    }

    DoAdd(pre, cur, 1, ignore);

    ans[cur] = subsize[cur] - maxn;

    if (!keep) {
        DoAdd(pre, cur, -1, -1);
        maxn = 0;
    }
}

int main() {
    int n;
    input(n);

    values.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &values[i]);
    }

    int a, b;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ans.resize(n + 1);

    cnt = vector<int>(n + 1, 0);
    subsize = vector<int>(n + 1, 0);
    maxsub = vector<int>(n + 1, 0);
    dfs(0, 1);
    dfs2(0, 1, 0);

    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            putchar(' ');
        }
        printf("%d", ans[i]);
    }
    puts("");

    return 0;
}

/*

^^^TEST^^^
2
1 2
1 2
-----
1 0
$$$TEST$$$

^^^TEST^^^
4
1 2 3 3
1 2
1 3
1 4
-----
2 0 0 0
$$$TEST$$$

^^^TEST^^^
16
1 2 3 1 2 3 3 1 1 3 2 2 1 2 3 3
4 6
1 2
12 3
14 15
5 7
8 5
3 4
11 16
2 9
9 13
3 2
14 9
1 10
11 10
5 3
-----
10 8 4 1 2 0 0 0 2 1 1 0 0 1 0 0
$$$TEST$$$

*/
