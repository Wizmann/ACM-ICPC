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

const int SIZE = 6123;

vector<int> g[SIZE];
int dp[SIZE][2];
vector<int> value;

int dfs(int cur, bool flag) {
    if (dp[cur][flag] != -1) {
        return dp[cur][flag];
    }
    int maxi1 = (flag == false) ? value[cur]: -INF;
    int maxi2 = 0;

    for (auto nxt : g[cur]) {
        if (flag == false) {
            maxi1 += dfs(nxt, true);
        }
        maxi2 += dfs(nxt, false);
    }

    return dp[cur][flag] = max(maxi1, maxi2);
}

int main() {
    int n;
    input(n);
    value = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &value[i]);
    }

    int a, b;
    vector<int> degree(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        g[b].push_back(a);
        degree[a]++;
    }

    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            root = i;
            break;
        }
    }

    memset(dp, -1, sizeof(dp));
    print(dfs(root, false));

    return 0;
}

/*

^^^TEST^^^
1
1
-----
1
$$$TEST$$$

^^^TEST^^^
3
1
1
1
2 1
3 1
-----
2
$$$TEST$$$

^^^TEST^^^
3
1
123
3
1 2
2 3
-----
123
$$$TEST$$$

^^^TEST^^^
3
1
123
300
1 2
2 3
-----
301
$$$TEST$$$

^^^TEST^^^
7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5
-----
5
$$$TEST$$$

*/
