#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 100100;
const int INF = 0x3f3f3f3f;

vector<int> g[SIZE];
int n;
int ans;

int dfs(int ptr, int depth) {
    if (g[ptr].empty()) {
        return 0;
    }
    int res[] = {-INF, -INF};
    for (auto next: g[ptr]) {
        int u = dfs(next, depth + 1);
        res[1] = max(res[1], u);
        if (res[0] < res[1]) {
            swap(res[0], res[1]);
        }
    }
    ans = max(ans, res[0] + res[1] + depth + 2);
    return res[0] + 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    int a, b;
    input(n);
    for (int i = 0; i < n; i++) {
        input(a >> b);
        g[a].push_back(b);
    }
    ans = 0;
    dfs(1, 0);
    print(ans);
    return 0;
}
