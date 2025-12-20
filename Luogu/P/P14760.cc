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

const int SIZE = 1234567;

int n;
vector<int> g[SIZE];

int dfs(int pre, int cur) {
    int res = 0;
    for (auto nxt : g[cur]) {
        if (pre == nxt) {
            continue;
        }
        res += dfs(cur, nxt);
    }
    return res == 0;
}

int main() {
    int T;
    input(T);
    while (T--) {
        input(n);
        for (int i = 0; i <= n; i++) {
            g[i].clear();
        }

        int a, b;
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }

        int u = dfs(-1, 1);
        if (u == 0) {
            puts("first");
        } else {
            puts("second");
        }
    }

    return 0;
}

/*

^^^TEST^^^
2
4
1 2
1 3
1 4
4
1 2
2 3
2 4
-----
first
second
$$$TEST$$$

^^^TEST^^^
3
1
2
1 2
3
1 2
2 3
-----
second
first
second
$$$TEST$$$

*/
