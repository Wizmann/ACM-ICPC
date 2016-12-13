// Result: Accepted	2444	156MS	1972K	1729B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 222;

int n, m;
vector<int> g[SIZE];
vector<int> color;
vector<int> pre;
vector<bool> inpath;

void init() {
    for (int i = 0; i < SIZE; i++) {
        g[i].clear();
    }
    color = vector<int>(SIZE, 0);
    pre = vector<int>(SIZE, -1);
}

bool dfs1(int cur, int c) {
    if (color[cur] != 0) {
        return color[cur] == c;
    }

    color[cur] = c;

    bool res = true;
    for (auto next: g[cur]) {
        res &= dfs1(next, -c);
    }
    return res;
}

int dfs2(int cur) {
    for (auto next: g[cur]) {
        if (!inpath[next]) {
            inpath[next] = 1;
            if (pre[next] == -1 || dfs2(pre[next])) {
                pre[next] = cur;
                return true;
            }
        }
    }
    return false;
}

int hungary() {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        inpath = vector<bool>(SIZE, false);
        sum += dfs2(i);
    }
    return sum;
}
    

int main() {
    freopen("input.txt", "r", stdin);
    while (input(n >> m)) {
        int a, b;

        init();

        for (int i = 0; i < m; i++) {
            input(a >> b);
            g[a].push_back(b);
            g[b].push_back(a);
        }

        bool flag = true;
        for (int i = 1; i <= n && flag; i++) {
            if (color[i] == 0) {
                flag &= dfs1(i, 1);
            }
        }

        if (!flag) {
            puts("No");
        } else {
            print(hungary() / 2);
        }
    }
    return 0;
}

