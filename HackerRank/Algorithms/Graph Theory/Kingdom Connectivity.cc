#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint MOD = 1000000000LL;
const int SIZE = 12345;

int n;
int m;
vector<int> g[SIZE];
vector<bool> visit;
bool infinite_loop;

llint dp[SIZE];

llint dfs2(int cur, int cnt) {
    if (visit[cur]) {
        return -1;
    }
    
    visit[cur] = true;
    
    
    if (dp[cur] != -1) {
        visit[cur] = false;
        return dp[cur];
    }
    bool loop = false;
    llint sum = 0;
    for (const auto& next: g[cur]) {
        llint t = dfs2(next, cnt + 1);
        if (t == -1) {
            loop = true;
        } else {
            sum = (sum + t) % MOD;
        }
    }
    if (sum && loop) {
        infinite_loop = true;
        return -1;
    }
    visit[cur] = false;
    return dp[cur] = sum;
}

int main() {
    int a, b;
    input(n >> m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
    }
    
    infinite_loop = false;
    visit = vector<bool>(SIZE, false);
    memset(dp, -1, sizeof(dp));
    dp[n] = 1;
    dfs2(1, 0);
    
    /*
    for (int i = 1; i <= n; i++) {
        printf("%d: %lld\n", i, dp[i]);
    }
    puts("");
    */
    
    if (!infinite_loop) {
        print(dp[1]);
    } else {
        puts("INFINITE PATHS");
    }

    return 0;
}
