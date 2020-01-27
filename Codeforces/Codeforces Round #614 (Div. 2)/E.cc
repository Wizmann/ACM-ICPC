#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define print(x) cout << x << endl
#define input(x) cin >> x
 
typedef long long llint;
 
const int SIZE = 3333;
 
vector<int> g[SIZE];
int f[SIZE][SIZE];
int cnt[SIZE][SIZE];
llint dp[SIZE][SIZE];
 
int dfs(int root, int cur, int pre) {
    f[root][cur] = pre;
 
    int tot = 1;
    for (int nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        tot += dfs(root, nxt, cur);
    }
    cnt[root][cur] = tot;
    return tot;
}
 
llint solve(int l, int r) {
    if (l == r) {
        return 0;
    }
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    llint res = 1LL * cnt[l][r] * cnt[r][l] + max(solve(l, f[l][r]), solve(r, f[r][l]));
    dp[l][r] = res;
    return res;
}
 
int main() {
    int n;
    input(n);
 
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &u, &v);
        u -= 1;
        v -= 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    memset(dp, -1, sizeof(dp));
 
    for (int i = 0; i < n; i++) {
        dfs(i, i, -1);
    }
 
    llint ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = max(ans, solve(i, j));
        }
    }
    print(ans);
    return 0;
}
