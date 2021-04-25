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

const int N = 18;

llint dp[1 << N];

struct Rule {
    int x, y, z;
};

int n, m;
vector<Rule> rules;

llint dfs(int cur, int status) {
    if (cur == n) {
        return 1;
    }

    if (dp[status] != -1) {
        return dp[status];
    }

    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++) {
        if (status & (1 << i)) {
            pre[i] += 1;
        }
        if (i - 1 >= 0) {
            pre[i] += pre[i - 1];
        }
    }

    llint res = 0;
    for (int i = 0; i < n; i++) {
        if (status & (1 << i)) {
            continue;
        }

        bool flag = true;
        for (const auto& r : rules) {
            if (r.y == cur) {
                int tot = pre[r.x] + (i > r.x? 0: 1);
                if (tot > r.z) {
                    flag = false;
                    break;
                }
            }
        }

        if (flag) {
            res += dfs(cur + 1, status | (1 << i));
        }
    }
    return dp[status] = res;
}

int main() {
    input(n, m);

    int x, y, z;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        rules.push_back({x - 1, y - 1, z});
    }

    memset(dp, -1, sizeof(dp));
    print(dfs(0, 0));

    return 0;
}

/*

^^^TEST^^^
3 1
2 2 1
-----
4
$$$TEST$$$

^^^TEST^^^
5 2
3 3 2
4 4 3
-----
90
$$$TEST$$$

^^^TEST^^^
18 0
-----
6402373705728000
$$$TEST$$$

*/
