#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
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

int main() {
    int n, m;
    input(n, m);
    vector<int> ns(n + 1);
    vector<int> ps(m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &ns[i]);
        ns[i] -= 1;
        ps[ns[i]]++;
    }

    vector<vector<int> > presum(m);
    for (int i = 0; i < m; i++) {
        presum[i] = vector<int>(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            if (ns[j] == i) {
                presum[i][j] += 1;
            }
            presum[i][j] += presum[i][j - 1];
        }
    }

    vector<int> dp(1 << m, INF);
    dp[0] = 0;
    for (int i = 0; i < (1 << m); i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                cnt += ps[j];
            }
        }
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                int l = cnt - ps[j];
                int r = cnt;
                int delta = ps[j] - (presum[j][r] - presum[j][l]);
                dp[i] = min(dp[i], dp[i ^ (1 << j)] + delta);
            }
        }
    }
    print(dp[(1 << m) - 1]);

    return 0;
}

/*
^^^TEST^^^
12 4
1
3
2
4
2
1
2
3
1
1
3
4
---
7
$$$TEST$$$
*/
