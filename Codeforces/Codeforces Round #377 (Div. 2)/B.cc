#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 555;
const int INF = 0x3f3f3f3f;

struct node {
    int value;
    int pre;
};

int n, m;
int ans, ptr;
node dp[SIZE][SIZE];
vector<int> vec;
vector<int> path;

int solve() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            dp[i][j] = {INF, -1};
        }
    }

    for (int i = *vec.begin(); i < SIZE; i++) {
        dp[0][i] = {i - *vec.begin(), -1};
    }

    for (int i = 1; i < n; i++) {
        for (int j = vec[i]; j < SIZE; j++) {
            for (int k = vec[i - 1]; k < SIZE; k++) {
                if (j + k < m || dp[i - 1][k].value == INF) {
                    continue;
                }
                int u = dp[i][j].value;
                int v = dp[i - 1][k].value + max(0, j - vec[i]);

                if (v < u) {
                    dp[i][j].value = v;
                    dp[i][j].pre = k;
                }
            }
        }
    }

    ans = INF;
    for (int i = 0; i < SIZE; i++) {
        if (dp[n - 1][i].value < ans) {
            ptr = i;
            ans = min(dp[n - 1][i].value, ans);
        }
    }
    return ans;
}

void dfs(int idx, int p) {
    if (idx == -1) {
        return;
    }
    path.push_back(p);
    p = dp[idx][p].pre;
    dfs(idx - 1, p);
}

int main() {
    input(n >> m);
    vec.resize(n);
    for (int i = 0; i < n; i++) {
        input(vec[i]);
    }

    ans = solve();
    dfs(n - 1, ptr);
    print(ans);

    reverse(path.begin(), path.end());
    for (auto item: path) {
        printf("%d ", item);
    }
    puts("");

    return 0;
}
