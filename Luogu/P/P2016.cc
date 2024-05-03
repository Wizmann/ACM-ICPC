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

const int SIZE = 1555;

set<int> g[SIZE];
int dp[SIZE][2];
vector<int> value;

int dfs(int pre, int cur, bool flag) {
    if (dp[cur][flag] != INF) {
        return dp[cur][flag];
    }
    int mini1 = 1;
    int mini2 = flag == true? 0: INF;

    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        mini1 += dfs(cur, nxt, true);
        if (flag) {
            mini2 += dfs(cur, nxt, false);
        }
    }

    return dp[cur][flag] = min(mini1, mini2);
}

int main() {
    int n;
    input(n);

    for (int i = 0; i < n; i++) {
        int cur;
        input(cur);

        int cnt;
        input(cnt);

        int a;
        for (int j = 0; j < cnt; j++) {
            input(a);
            g[cur].insert(a);
            g[a].insert(cur);
        }
    }

    memset(dp, INF, sizeof(dp));
    print(dfs(-1, 0, true));

    return 0;
}

/*

^^^TEST^^^
1
0 0
-----
0
$$$TEST$$$

^^^TEST^^^
2
0 1 1
1 1 0
-----
1
$$$TEST$$$

^^^TEST^^^
3
0 1 1
1 2 0 2
2 1 1
-----
1
$$$TEST$$$

^^^TEST^^^
4
0 1 1
1 2 2 3
2 0
3 0
-----
1
$$$TEST$$$

^^^TEST^^^
6
0 0
1 4 2 3 4 5
2 1 0
3 0
4 0
5 0
-----
2
$$$TEST$$$
*/

