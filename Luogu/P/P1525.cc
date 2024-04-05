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

const int N = 22222;
const int MAXI = 101000;

struct Edge {
    int dest;
    int cost;
};

int n, m;
vector<Edge> g[N];
vector<int> colors;

bool dfs(int pre, int cur, int color, int threshold) {
    colors[cur] = color;

    bool flag = true;
    for (const auto& nxt : g[cur]) {
        if (nxt.cost < threshold) {
            continue;
        }
        if (colors[nxt.dest] == color) {
            return false;
        }
        if (colors[nxt.dest] == -1) {
            flag = dfs(cur, nxt.dest, color ^ 1, threshold);
        }
        if (!flag) {
            break;
        }
    }
    return flag;
}

bool check(int mid) {
    colors = vector<int>(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (colors[i] != -1) {
            continue;
        }

        if (!dfs(-1, i, 0, mid)) {
            return false;
        }
    }
    return true;
}

int main() {
    input(n, m);

    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    int l = 0;
    int r = MAXI;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (!check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (r < 0) {
        r = 0;
    }
    print(r);

    return 0;
}

/*

^^^TEST^^^
4 6
1 4 2534
2 3 3512
1 2 28351
1 3 6618
2 4 1805
3 4 12884
-----
3512
$$$TEST$$$

*/
