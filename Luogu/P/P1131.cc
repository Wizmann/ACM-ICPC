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

const int SIZE = 512345;

struct Edge {
    int dest, cost;
};

llint ans = 0;
vector<Edge> g[SIZE];

llint dfs1(int pre, int cur, llint depth) {
    llint maxi = depth;
    for (const auto& nxt : g[cur]) {
        if (nxt.dest == pre) {
            continue;
        }
        maxi = max(maxi, dfs1(cur, nxt.dest, depth + nxt.cost));
    }
    return maxi;
}

llint dfs2(int pre, int cur, llint depth, const llint maxi) {
    vector<llint> sub;
    for (const auto& nxt : g[cur]) {
        if (nxt.dest == pre) {
            continue;
        }
        sub.push_back(dfs2(cur, nxt.dest, depth + nxt.cost, maxi));
    }

    if (sub.empty()) {
        return maxi - depth;
    }

    llint mini = INFLL;
    for (auto num : sub) {
        mini = min(mini, num);
    }

    if (pre != -1) {
        for (auto num : sub) {
            ans += num - mini;
        }
    } else {
        for (auto num : sub) {
            ans += num;
        }
    }

    return mini;
}

int main() {
    int n;
    input(n);

    int root;
    input(root);

    int a, b, c;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d%d", &a, &b, &c);
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    llint maxi = dfs1(-1, root, 0);
    dfs2(-1, root, 0, maxi);

    print(ans);

    return 0;
}

/*

^^^TEST^^^
3
1
1 2 1
1 3 3
-----
2
$$$TEST$$$

*/
