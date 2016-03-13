#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 55555;
const int INF = 0x3f3f3f3f;

struct Rope {
    int c, w, f;
};

int n;
vector<int> g[SIZE];
vector<Rope> ropes;

bool do_dfs(int cur, int& w) {
    w = 0;
    for (auto child: g[cur]) {
        int ww = 0;
        bool flag = do_dfs(child, ww);
        if (!flag) {
            return false;
        }
        w += ww;
    }
    
    w += ropes[cur].w;
    
    //print(cur << ' ' << w << ' ' << ropes[cur].c);
    if (w > ropes[cur].c) {
        return false;
    }
    return true;
}

bool dfs(int cur) {
    int tmp = 0;
    return do_dfs(cur, tmp);
}

bool solve(int m) {
    for (int i = 0; i < SIZE; i++) {
        g[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        const auto& rope = ropes[i];
        g[rope.f].push_back(i);
        
    }
    // print("---");
    // print(m);
    return dfs(0);
}

int main() {
    freopen("input.txt", "r", stdin);
    input(n);
    
    int a, b, c;
    ropes.resize(n + 1);
    ropes[0] = {INF, 0, 0};
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a, &b, &c);
        ropes[i] = {a, b, c + 1};
    }
    
    int l = 0;
    int r = n;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (solve(m)) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    print(r);
    return 0;
    
}
