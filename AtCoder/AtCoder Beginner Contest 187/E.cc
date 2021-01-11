#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 212345;

struct Edge {
    int a, b;
};

int n;
vector<int> g[SIZE];
vector<Edge> edges;
vector<int> depth;
vector<llint> weight;
vector<llint> value;

void dfs1(int pre, int cur, int d) {
    depth[cur] = d;
    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        dfs1(cur, nxt, d + 1);
    }
}

void dfs2(int pre, int cur, llint w) {
    w += weight[cur];
    value[cur] = w;
    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        dfs2(cur, nxt, w);
    }
}

int main() {
    input(n);

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        edges.push_back({a, b});
        g[a].push_back(b);
        g[b].push_back(a);
    }

    depth = vector<int>(n + 1, 0);
    weight = vector<llint>(n + 1, 0);
    value = vector<llint>(n + 1, 0);
    dfs1(-1, 1, 0);

    int q;
    input(q);

    int t, e, x;
    while (q--) {
        scanf("%d%d%d", &t, &e, &x);
        a = edges[e - 1].a;
        b = edges[e - 1].b;
        if (t == 2) {
            swap(a, b);
        }
        if (depth[a] < depth[b]) {
            weight[1] += x;
            weight[b] -= x;
        } else {
            weight[a] += x;
        }
    }

    dfs2(-1, 1, 0);

    for (int i = 1; i <= n; i++) {
        printf("%lld\n", value[i]);
    }

    return 0;
}

/*
^^^TEST^^^
5
1 2
2 3
2 4
4 5
4
1 1 1
1 4 10
2 1 100
2 2 1000
-----
11
110
1110
110
100
$$$TEST$$$

^^^TEST^^^
7
2 1
2 3
4 2
4 5
6 1
3 7
7
2 2 1
1 3 2
2 2 4
1 6 8
1 3 16
2 4 32
2 1 64
----
72
8
13
26
58
72
5
$$$TEST$$$

^^^TEST^^^
11
2 1
1 3
3 4
5 2
1 6
1 7
5 8
3 9
3 10
11 4
10
2 6 688
1 10 856
1 8 680
1 8 182
2 2 452
2 4 183
2 6 518
1 3 612
2 6 339
2 3 206
----
1657
1657
2109
1703
1474
1657
3202
1474
1247
2109
2559
$$$TEST$$$

*/
