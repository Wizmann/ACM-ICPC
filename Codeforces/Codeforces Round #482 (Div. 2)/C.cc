#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456 * 3;

int n, x, y;
vector<int> g[SIZE];

bool dfs(int cur, vector<bool>& visit, int p, int& cnt) {
    if (cur == p) {
        return false;
    }

    visit[cur] = true;
    bool flag = true;

    cnt += 1;

    for (auto child: g[cur]) {
        if (visit[child]) {
            continue;
        }
        flag &= dfs(child, visit, p, cnt);
    }
    return flag;
}

int solve(int root, int p) {
    int tot = 0;
    for (auto child: g[root]) {
        vector<bool> visit(SIZE, false);
        visit[root] = true;

        int cnt = 0;

        if (dfs(child, visit, p, cnt)) {
            tot += cnt;
        }
    }
    return tot + 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    input(n >> x >> y);

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int u = solve(x, y);
    int v = solve(y, x);

    print(1LL * n * n - n - 1LL * u * v);

    return 0;
}


