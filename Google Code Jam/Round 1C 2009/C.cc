#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123;
const int INF = 0x3f3f3f3f;

int n, m;
vector<int> ns;
int dp[SIZE][SIZE];

int dfs(int l, int r) {
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    int len = ns[r] - ns[l] - 1;
    if (l + 1 == r) {
        return 0;
    }
    int res = INF;
    for (int i = l + 1; i < r; i++) {
        res = min(res, len - 1 + dfs(l, i) + dfs(i, r));
    }
    return dp[l][r] = res;
}

int solve() {
    return dfs(0, m + 1);
}

int main() {
    // freopen("input.txt", "r", stdin);
    int T;
    int case_ = 0;
    input(T);
    while (T--) {
        input(n >> m);
        memset(dp, -1, sizeof(dp));
        ns = vector<int>(m + 2, 0);
        ns[0] = 0;
        ns[m + 1] = n + 1;
        for (int i = 1; i <= m; i++) {
            input(ns[i]);
        }
        printf("Case #%d: %d\n", ++case_, solve());
    }
    return 0;
}
