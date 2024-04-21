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

const int SIZE = 333;

vector<int> ns;
vector<int> pre;
int dp[SIZE][SIZE];

int rangesum(int l, int r) {
    if (l == 0) {
        return pre[r];
    }
    return pre[r] - pre[l - 1];
}

int dfs(int l, int r) {
    if (l == r) {
        return 0;
    }
    if (l + 1 == r) {
        return ns[l] + ns[r];
    }

    if (dp[l][r] < INF) {
        return dp[l][r];
    }

    int mini = INF;
    for (int i = l; i < r; i++) {
        mini = min(mini, dfs(l, i) + dfs(i + 1, r) + rangesum(l, i) + rangesum(i + 1, r));
    }
    return dp[l][r] = mini;
}

int main() {
    int n;
    input(n);
    ns = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        input(ns[i]);
    }
    pre = ns;
    for (int i = 1; i < n; i++) {
        pre[i] += pre[i - 1];
    }
    
    memset(dp, INF, sizeof(dp));

    print(dfs(0, n - 1));

    return 0;
}

/*

^^^TEST^^^
4
1 3 5 2
-----
22
$$$TEST$$$

^^^TEST^^^
10
548 592 715 844 602 857 544 847 423 623
-----
21971
$$$TEST$$$

*/
