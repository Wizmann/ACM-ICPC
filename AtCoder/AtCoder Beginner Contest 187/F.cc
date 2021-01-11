#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int INF = 0x3f3f3f3f;
const int SIZE = 18;

int n, m;
int g[SIZE][SIZE];
int dp[1 << SIZE];

bool check_group(const vector<int>& ps) {
    int m = ps.size();
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            int a = ps[i];
            int b = ps[j];
            if (!g[a][b]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    input(n >> m);
    memset(g, 0, sizeof(g));
    memset(dp, INF, sizeof(dp));

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        a--;
        b--;
        assert(a < SIZE && b < SIZE);
        g[a][b] = g[b][a] = 1;
    }

    vector<int> ps;
    ps.reserve(n);
    for (int i = 1; i < (1 << n); i++) {
        ps.clear();
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                ps.push_back(j);
                cnt++;
            }
        }
        if (check_group(ps)) {
            dp[i] = 1;
        }
    }

    for (int i = 1; i < (1 << n); i++) {
        for (int j = i; j != 0; j = (j - 1) & i) {
            dp[i] = min(dp[i], dp[j] + dp[i ^ j]);
        }
    }
    print(dp[(1 << n) - 1]);


    return 0;
}

/*
^^^TEST^^^
3 2
1 2
1 3
---
2
$$$TEST$$$

^^^TEST^^^
4 6
1 2
1 3
1 4
2 3
2 4
3 4
---
1
$$$TEST$$$

^^^TEST^^^
10 11
9 10
2 10
8 9
3 4
5 8
1 8
5 6
2 5
3 6
6 9
1 9
---
5
$$$TEST$$$

^^^TEST^^^
18 0
---
18
$$$TEST$$$

*/
