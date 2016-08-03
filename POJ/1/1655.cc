#include <cstdio>
#include <cstring>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x
#define loop(i, n) for (int i = 0; i < n; i++)

const int SIZE = 22222;
const int INF = 0x3f3f3f3f;

int n;
vector<int> g[SIZE];

void init() {
    loop(i, SIZE) {
        g[i].clear();
    }
}

class Solution {
public:
    Solution() {
        dp = vector<int>(n + 1, 0);
    }

    void get_result(int& core, int& min_balance) {
        int mini = INF;
        int res = -1;
        loop(i, n) {
            if (dp[i + 1] < mini) {
                mini = dp[i + 1];
                res = i + 1;
            }
        }
        core = res;
        min_balance = mini;
    }
    int dfs(int pre, int cur) {
        int child_num = 0;
        int max_subtree = 0;
        loop(i, g[cur].size()) {
            int next = g[cur][i];
            if (next == pre) {
                continue;
            }
            int t = dfs(cur, next);
            child_num += t;
            max_subtree = max(max_subtree, t);
        }
        max_subtree = max(max_subtree, n - child_num - 1);
        dp[cur] = max_subtree;
        return child_num + 1;
    }
private:
    vector<int> dp;
};

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    int a, b;

    input(T);
    while (T--) {
        init();

        input(n);
        loop(i, n - 1) {
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }

        Solution S;
        S.dfs(-1, 1);
        S.get_result(a, b);
        printf("%d %d\n", a, b);
    }
    return 0;
}
