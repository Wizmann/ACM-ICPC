// Result: wizmann	2342	Accepted	1420K	438MS	G++	1280B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 6666;
const int INF = 0x3f3f3f3f;

int n;
vector<int> g[SIZE];
vector<int> joy;
vector<int> indegree;
int dp[SIZE][2];

int dfs(int cur, int pre) {
    if (dp[cur][pre] != -INF) {
        return dp[cur][pre];
    }

    int ans1 = joy[cur];
    int ans2 = 0;
    for (size_t i = 0; i < g[cur].size(); i++) {
        int next = g[cur][i];
        ans1 += dfs(next, 1);
        ans2 += dfs(next, 0);
    }
    
    if (pre == 0) {
        return dp[cur][pre] = max(ans1, ans2);
    } else {
        return dp[cur][pre] = ans2;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    input(n);

    joy.resize(n);
    for (int i = 0; i < n; i++) {
        input(joy[i]);
    }

    int a, b;
    indegree = vector<int>(n, 0);
    while (input(a >> b) && a + b) {
        a -= 1;
        b -= 1;

        g[b].push_back(a);
        indegree[a]++;
    }

    for (int i = 0; i < SIZE; i++) {
        dp[i][0] = dp[i][1] = -INF;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            ans += dfs(i, 0);
        }
    }

    print(ans);
    return 0;
}

