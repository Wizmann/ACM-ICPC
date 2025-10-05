#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int N = 20;

int n;
vector<int> ns;
vector<int> g[N];

int16_t dp[N][1 << N];

int dfs(int cur, int state) {
    state |= (1 << cur);

    if (dp[cur][state] != -1) {
        return dp[cur][state];
    }

    int maxi = 0;
    for (auto nxt : g[cur]) {
        maxi = max(maxi, dfs(nxt, state));
    }

    return dp[cur][state] = maxi + ns[cur];
}

void dfs2(int cur, int maxi, int state, vector<int>& path) {
    maxi -= ns[cur];
    state |= 1 << cur;
    path.push_back(cur);

    for (auto nxt : g[cur]) {
        if (dfs(nxt, state) == maxi) {
            dfs2(nxt, maxi, state, path);
            break;
        }
    }
}

int main() {
    input(n);
    ns = vector<int>(n, -1);

    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    int a;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            scanf("%d", &a);
            if (a) {
                g[i].push_back(j);
            }
        }
    }

    memset(dp, -1, sizeof(dp));

    int maxp = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        int res = dfs(i, 0);
        if (res > maxi) {
            maxi = res;
            maxp = i;
        }
    }

    vector<int> path;
    dfs2(maxp, maxi, 0, path);

    for (auto node : path) {
        printf("%d ", node + 1);
    }
    puts("");

    print(maxi);

    return 0;
}

/*

^^^TEST^^^
5
10 8 4 7 6
1 1 1 0
0 0 0
1 1
1
-----
1 3 4 5
27
$$$TEST$$$

*/
