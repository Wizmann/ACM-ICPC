#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x
#define FOR(i, n) for (int i = 0; i < n; i++)

typedef long long llint;

const int N = 2222;

int n;
vector<int> ns;
llint dp[N][N];

llint dfs(int l, int r) {
    if (l > r) {
        return 0;
    }

    if (dp[l][r] >= 0) {
        return dp[l][r];
    }
    int m = r - l + 1;
    llint cnt = n - m + 1;

    llint res = -1;
    res = max(res, cnt * ns[l] + dfs(l + 1, r));
    res = max(res, cnt * ns[r] + dfs(l, r - 1));

    return dp[l][r] = res;
}

int main() {
    input(n);
    ns.resize(n);

    FOR (i, n) {
        scanf("%d", &ns[i]);
    }

    memset(dp, -1, sizeof(dp));

    print(dfs(0, n - 1));

    return 0;
}
