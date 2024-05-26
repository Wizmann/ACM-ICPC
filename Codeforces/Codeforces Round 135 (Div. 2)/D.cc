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

const int SIZE = 212345;

struct Edge {
    int dest;
    int cost;
};

vector<Edge> g[SIZE];
int dp[SIZE];
int minv;
vector<int> mini;

int dfs1(int pre, int cur) {
    int tot = 0;
    for (const auto& e : g[cur]) {
        if (e.dest == pre) {
            continue;
        }
        tot += dfs1(cur, e.dest) + e.cost;
    }
    return dp[cur] = tot;
}

void dfs2(int pre, int cur, int parent) {
    int tot = parent + dp[cur];
    if (tot < minv) {
        mini.clear();
    }

    if (tot <= minv) {
        minv = tot;
        mini.push_back(cur);
    }

    for (const auto& e : g[cur]) {
        if (e.dest == pre) {
            continue;
        }
        parent += dp[e.dest] + e.cost;
    }

    for (const auto& e : g[cur]) {
        if (e.dest == pre) {
            continue;
        }

        dfs2(cur, e.dest, parent - (dp[e.dest] + e.cost) + (e.cost ^ 1));
    }
}

int main() {
    int n;
    input(n);

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back({b, 0});
        g[b].push_back({a, 1});
    }

    int cur = dfs1(-1, 1);
    minv = cur;
    dfs2(-1, 1, 0);

    sort(mini.begin(), mini.end());

    print(minv);
    for (auto num : mini) {
        printf("%d ", num);
    }
    puts("");

    return 0;
}

/*

^^^TEST^^^
3
2 1
2 3
-----
0
2
$$$TEST$$$

^^^TEST^^^
4
1 4
2 4
3 4
-----
2
1 2 3
$$$TEST$$$

*/
