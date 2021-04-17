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

const int SIZE = 2222;

vector<llint> ns;
llint dp[SIZE][SIZE];

llint dfs(int l, int r) {
    if (dp[l][r] != -1) {
        return dp[l][r];
    }

    if (l == r) {
        return 0;
    }

    llint ans = ns[r] - ns[l];

    llint mini = INFLL;
    mini = min(mini, dfs(l + 1, r));
    mini = min(mini, dfs(l, r - 1));

    return dp[l][r] = ans + mini;
}

int main() {
    int n;
    input(n);

    ns.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &ns[i]);
    }
    sort(ns.begin(), ns.end());

    memset(dp, -1, sizeof(dp));
    print(dfs(0, n - 1));

    return 0;
}

/*

^^^TEST^^^
3
3 1 2
---
3
$$$TEST$$$

^^^TEST^^^
1
5
---
0
$$$TEST$$$

^^^TEST^^^
6
1 6 3 3 6 3
---
11
$$$TEST$$$

^^^TEST^^^
6
104 943872923 6589 889921234 1000000000 69
----
2833800505
$$$TEST$$$

*/
