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

const int SIZE = 123456;

struct Edge {
    int dest, cost;
};

vector<int> cows;
vector<Edge> g[SIZE];
vector<llint> subcnt;
vector<llint> dp;
llint mini = 0;
int n;
llint m = 0;

int dfs1(int pre, int cur) {
    int tot = cows[cur];

    for (const auto& e : g[cur]) {
        if (e.dest == pre) {
            continue;
        }

        tot += dfs1(cur, e.dest);
    }

    return subcnt[cur] = tot;
}

llint dfs2(int pre, int cur) {
    llint tot = 0;

    for (const auto& e : g[cur]) {
        if (e.dest == pre) {
            continue;
        }

        tot += dfs2(cur, e.dest) + e.cost * subcnt[e.dest];
    }

    return dp[cur] = tot;
}

void dfs3(int pre, int cur, llint parent) {
    mini = min(parent + dp[cur], mini);
    // print(cur, parent + dp[cur]);

    llint tot = 0;
    for (const auto& e : g[cur]) {
        if (e.dest == pre) {
            continue;
        }
        tot += dp[e.dest] + subcnt[e.dest] * e.cost;
    }

    for (const auto& e : g[cur]) {
        if (e.dest == pre) {
            continue;
        }

        llint nxt = parent + (m - subcnt[e.dest]) * e.cost + (tot - dp[e.dest] - subcnt[e.dest] * e.cost);

        dfs3(cur, e.dest, nxt);
    }
}

int main() {
    input(n);

    cows.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &cows[i]);
        m += cows[i];
    }

    int a, b, c;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d%d", &a, &b, &c);
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    subcnt = vector<llint>(n + 1, 0);
    dp = vector<llint>(n + 1, 0);
    mini = INFLL;

    dfs1(-1, 1);
    dfs2(-1, 1);
    dfs3(-1, 1, 0);

    print(mini);

    return 0;
}

/*

^^^TEST^^^
5 
1 
1 
0 
0 
2 
1 3 1 
2 3 2 
3 4 3 
4 5 3 
-----
15
$$$TEST$$$

*/
