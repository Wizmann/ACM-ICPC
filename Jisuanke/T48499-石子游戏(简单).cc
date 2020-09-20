#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;

struct Stone {
    int a, v;
};

int n, m, q;

unsigned int solve(const vector<Stone>& stones, int l, int r, int k, int x) {
    vector<int> dis[2];

    int p = 0;
    dis[0] = vector<int>(m, -INF);
    dis[0][0] = 0;

    dis[1] = vector<int>(m, -INF);
    for (int i = l; i <= r; i++) {
        auto stone = stones[i];
        int q = p ^ 1;
        fill(dis[q].begin(), dis[q].end(), -INF);

        for (int j = 0; j < m; j++) {
            if (dis[p][j] >= 0) {
                dis[q][j] = max(dis[q][j], dis[p][j]);

                int u = j ^ stone.a;
                assert(0 <= u && u < m);
                dis[q][u] = max(dis[q][u], dis[p][j] + stone.v);
            }
        }
        p = q;
    }

    unsigned int tot = 0;
    for (int i = 0; i < m; i++) {
        int cur = dis[p][i];
        if (cur < 0) {
            cur = -1;
        }
        cur *= x ^ i;
        // printf("%d %d %d\n", k, i, dis[p][i]);
        tot += (unsigned int)cur;
    }
    return tot ^ (unsigned int)k;
}

int main() {
    input(n >> m >> q);

    vector<Stone> stones(n);

    int a, b, c;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        stones[i] = {a, b};
    }

    unsigned int res = 0;
    for (int i = 0; i < q; i++) {
        scanf("%d%d%d", &a, &b, &c);
        res += solve(stones, a, b, i + 1, c);
    }
    print(res);

    return 0;
}

/*
^^TEST^^
5 8 5
3 5
0 1
1 8
5 3
0 9
3 4 2
3 3 1
1 2 3
0 1 7
1 4 7
---
340
$$TEST$$
*/
