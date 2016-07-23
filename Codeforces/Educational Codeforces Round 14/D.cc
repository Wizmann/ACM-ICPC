#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1234567;

int n, m;
vector<int> p;
vector<int> g[SIZE];
vector<bool> visit;

void dfs(int cur, vector<int>& pos, vector<int>& value) {
    if (visit[cur]) {
        return;
    }
    visit[cur] = 1;
    pos.push_back(cur);
    value.push_back(p[cur]);

    for (auto next: g[cur]) {
        dfs(next, pos, value);
    }
}

void solve(int ptr) {
    vector<int> pos;
    vector<int> value;

    dfs(ptr, pos, value);
    sort(value.begin(), value.end(), greater<int>());
    sort(pos.begin(), pos.end());

    int k = pos.size();

    for (int i = 0; i < k; i++) {
        int c = pos[i];
        int v = value[i];
        p[c] = v;
    }
}

int main() {
    input(n >> m);
    p.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    visit = vector<bool>(n, false);

    for (int i = 0; i < n; i++) {
        if (visit[i]) {
            continue;
        }
        solve(i);
    }

    for (auto i: p) {
        printf("%d ", i);
    }
    puts("");

    return 0;
}
