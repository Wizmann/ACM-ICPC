#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 123456;

struct Edge {
    int dest;
    int cost;
};

int n;
llint ans;
vector<Edge> g[SIZE];

int dfs(int pre, int cur) {
    int tot = 0;
    for (auto& edge: g[cur]) {
        if (edge.dest == pre) {
            continue;
        }
        int u = dfs(cur, edge.dest);
        int v = min(n - u - 1, u + 1);
        tot += u + 1;
        // print(v);
        ans += 1LL * edge.cost * v;
    }
    return tot;
}

int main() {
    int a, b, c;
    input(n);
    for (int i = 0; i < n - 1; i++) {
        input(a >> b >> c);
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    ans = 0;
    dfs(-1, 1);
    print(ans);
    return 0;
}
