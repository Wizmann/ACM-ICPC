#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

struct Query {
    int a, b, c, d;
};

vector<Query> queries;

llint dfs(int cur, int pre, int n, int m, vector<int>& path) {
    if (cur == n) {
        /*
        for (auto num: path) {
            printf("%d ", num);
        }
        puts("");
        */
        llint tot = 0;
        for (auto q: queries) {
            if (path[q.b] - path[q.a] == q.c) {
                tot += q.d;
            }
        }
        return tot;
    }

    llint maxi = 0;
    for (int i = pre; i <= m; i++) {
        path.push_back(i);
        maxi = max(maxi, dfs(cur + 1, i, n, m, path));
        path.pop_back();
    }
    return maxi;
}

int main() {
    int n, m, q;
    input(n >> m >> q);

    int a, b, c, d;
    for (int i = 0; i < q; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        a--;
        b--;
        queries.push_back({a, b, c, d});
    }

    vector<int> path;
    llint res = dfs(0, 1, n, m, path);
    print(res);
    return 0;
}

