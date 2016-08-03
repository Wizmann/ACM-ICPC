#include <cstdio>
#include <cstring>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x
#define loop(i, n) for (int i = 0; i < n; i++)

typedef long long llint;

const int SIZE = 222222;
const int INF = 0x3f3f3f3f;

int n, m;
vector<int> g[SIZE];
unordered_set<int> uc;

void init() {
    loop(i, SIZE) {
        g[i].clear();
    }
    uc.clear();
}

bool contain_university(int x) {
    return uc.find(x) != uc.end();
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
        max_subtree = max(max_subtree, m - child_num - contain_university(cur));
        dp[cur] = max_subtree;
        return child_num + contain_university(cur);
    }
private:
    vector<int> dp;
};

void dfs1(int pre, int cur, int depth, llint& ans) {
    loop(i, g[cur].size()) {
        int next = g[cur][i];
        if (next == pre) {
            continue;
        }
        dfs1(cur, next, depth + 1, ans);
    }
    if (contain_university(cur)) {
        ans += depth;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int a, b;

    init();

    input(n >> m);
    m *= 2;
    loop(i, m) {
        scanf("%d", &a);
        uc.insert(a);
    }
    loop(i, n - 1) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    Solution S;
    S.dfs(-1, 1);
    S.get_result(a, b);
    
    int core = a;
    llint ans = 0;

    dfs1(-1, core, 0, ans);
    print(ans);

    return 0;
}
