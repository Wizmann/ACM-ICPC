#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1111;
const int INF = 0x3f3f3f3f;

int n;
int dp[SIZE][SIZE];
vector<int> ns;

int dfs(int l, int r) {
    if (dp[l][r] != INF) {
        return dp[l][r];
    }
    
    if (l > r) {
        return 0;
    }

    int a = ns[l] - dfs(l + 1, r);
    int b = ns[r] - dfs(l, r - 1);
    
    return dp[l][r] = max(a, b);
}

int main() {
    input(n);
    ns.resize(n);
    memset(dp, INF, sizeof(dp));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }
    
    int delta = dfs(0, n - 1);
    int sum = accumulate(ns.begin(), ns.end(), 0);

    print((sum + delta) / 2);
    
    return 0;
}
