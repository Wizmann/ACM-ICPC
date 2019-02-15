#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

class Solution {
public:
    Solution(int n_, int m_): n(n_), m(m_) {
        g = vector<vector<int> >(n);
        dp = vector<vector<int> >(n, vector<int>(n, -1));
        ans = 0;
        visit = vector<bool>(n, false);
    }

    void addEdge(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int solve() {
        dfs(0);
        return ans;
    }

    void dfs(int cur) {
        int u = g[cur].size();
        visit[cur] = true;

        vector<int> bl = dp[cur];
        for (int i = 0; i < (1 << u); i++) {
            bool flag = true;
            int b = 0;
            for (int j = 0; j < u && flag; j++) {
                int p = g[cur][j];
                int v = (i & (1 << j))? 1: 0;
                b += (v == 0)? -1: 1;

                if (dp[cur][p] != -1 && dp[cur][p] != v) {
                    flag = false;
                    break;
                }
                dp[cur][p] = dp[p][cur] = v;
            }

            if (flag && b == 0) {
                flag = true;
                for (int j = 0; j < u; j++) {
                    int next = g[cur][j];
                    if (!visit[next]) {
                        dfs(next);
                        flag = false;
                        break;
                    }
                }

                for (int j = 0; j < n && flag; j++) {
                    if (j == cur) {
                        continue;
                    }
                    if (!visit[j]) {
                        dfs(j);
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    ans++;
                }
            }
            dp[cur] = bl;
        }
        visit[cur] = false;
    }
private:
    int n, m;
    int ans;
    vector<vector<int> > g;
    vector<vector<int> > dp;

    vector<bool> visit;
};

int main() {
    int T;
    input(T);
    while (T--) {
        int n, m;
        input(n >> m);

        Solution S(n, m);

        int a, b;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            S.addEdge(a - 1, b - 1);
        }

        print(S.solve());
    }

    return 0;
}
