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

const int SIZE = 123456;

int n;
llint p;
llint cnt;
vector<int> g[SIZE];

int dfs(int cur, int depth, int pre) {
    int c = 0;
    for (auto next: g[cur]) {
        if (next == pre) {
            continue;
        }
        int cc = dfs(next, depth + 1, cur);
        p += 1LL * (n - cc) * depth;
        cnt += depth;

        c += cc;
    }

    return c + 1;
}

int main() {   
    int a, b;

    input(n);
    for (int i = 0; i < n - 1; i++) {
        input(a >> b);

        g[a].push_back(b);
        g[b].push_back(a);
    }

    p = cnt = 0;

    dfs(1, 1, -1);
    printf("%.7lf\n", 1.0 * p / cnt);

    return 0;
}
