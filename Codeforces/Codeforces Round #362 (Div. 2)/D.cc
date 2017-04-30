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

typedef long long llint;

int n;
vector<vector<int> > g;
vector<int> cnt;
vector<double> ans;

int dfs1(int cur) {
    int sum = 1;
    for (auto next: g[cur]) {
        sum += dfs1(next);
    }
    return cnt[cur] = sum;
}

void dfs2(int cur, double exp) {
    // print(cur << ' ' << exp);
    ans[cur] = exp + 1;

    int sum = 0;
    int m = g[cur].size();
    for (auto next: g[cur]) {
        sum += cnt[next];
    }

    if (m == 1) {
        int next = g[cur][0];
        dfs2(next, ans[cur]);
        return;
    }
    
    for (auto next: g[cur]) {
        ans[next] = ans[cur] + 1.0 * (sum - cnt[next]) / 2;
        dfs2(next, ans[next]);
    }
}

int main() {
    input(n);
    g.resize(n + 1);
    cnt.resize(n + 1);
    ans.resize(n + 1);

    int u;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &u);
        g[u].push_back(i);
    }

    dfs1(1);
    dfs2(1, 0);

    for (int i = 1; i <= n; i++) {
        printf("%lf ", ans[i]);
    }
    puts("");

    return 0;
}
