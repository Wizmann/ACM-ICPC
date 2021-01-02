#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 200010;

const int INF = 0x3f3f3f3f;
const llint MOD = 1000000000 + 7;

int n;
vector<int> g[SIZE];
vector<int> treesize;
vector<llint> dp;
vector<llint> ans;

void dfs1(int pre, int cur) {
    int s = 1;
    llint res = 0;
    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        dfs1(cur, nxt);
        s += treesize[nxt];
        res += dp[nxt];
    }
    res += s;
    dp[cur] = res;
    treesize[cur] = s;
}

void dfs2(int pre, int cur) {
    if (cur != 1) {
        int s = n - treesize[cur];
        llint u = ans[pre] - dp[cur] - n + s;
        ans[cur] = dp[cur] + u + n - treesize[cur];
    }

    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        dfs2(cur, nxt);
    }
}

int main() {
    input(n);

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    treesize = vector<int>(SIZE, 0);
    dp = vector<llint>(SIZE, 0);
    ans = vector<llint>(SIZE, 0);

    dfs1(-1, 1);
    ans[1] = dp[1];
    dfs2(-1, 1);

    llint maxi = 0;
    for (int i = 1; i <= n; i++) {
        maxi = max(maxi, ans[i]);
    }
    print(maxi);

    return 0;
}
/*
^^^TEST^^^
3
1 2
1 3
---
6
$$$TEST$$$

^^^TEST^^^
2
1 2
---
3
$$$TEST$$$

^^^TEST^^^
9
1 2
2 3
2 5
2 6
1 4
4 9
9 7
9 8
-----
36
$$$TEST$$$
*/
