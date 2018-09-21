#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;

vector<int> prices, nexts, dp;
vector<bool> visited;

int dfs1(int pos, int step) {
    if (step == 0) {
        return pos;
    }
    if (dp[pos] != -1) {
        return dp[pos];
    }
    if (visited[pos]) {
        return pos;
    }
    visited[pos] = true;
    return dp[pos] = dfs1(nexts[pos], step - 1);
}

int dfs2(int pos, int step, int mini) {
    if (step == 0) {
        return mini;
    }
    if (visited[pos]) {
        return mini;
    }
    visited[pos] = true;
    mini = min(mini, prices[pos]);
    return dfs2(nexts[pos], step - 1, mini);
}

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    input(n);

    prices = vector<int>(n);
    nexts = vector<int>(n);
    dp = vector<int>(n, -1);
    visited = vector<bool>(n, false);

    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &nexts[i]);
        nexts[i] -= 1;
    }

    set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(dfs1(i, n + 1));
    }

    int ans = 0;
    visited = vector<bool>(n, false);
    for (auto p: st) {
        if (visited[p]) {
            continue;
        }
        // print(p);
        ans += dfs2(p, n + 1, INF);
    }

    print(ans);

    return 0;
}
