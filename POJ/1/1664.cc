#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint MOD = 1000000007LL;

int ans = 0;

void dfs(int n, int m, int pre) {
    if (m == 0) {
        if (n == 0) {
            ans++;
        }
        return;
    }
    for (int i = pre; i <= n; i++) {
        dfs(n - i, m - 1, i);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    int n, m;
    input(T);
    while (T--) {
        ans = 0;
        input(n >> m);
        dfs(n, m, 0);
        print(ans);
    }
    return 0;
}
