#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 100001;
const llint MOD = 1000000007;

int n;
vector<int> g[SIZE];

llint fastpow(llint a, llint b, llint c) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % c;
        }
        b >>= 1;
        a = (a * a) % c;
    }
    return res;
}

void dfs(int cur, int pre, llint& cnt, llint& res) {
    int m = g[cur].size();

    if (pre == -1) {
        res = 1;
    } else {
        res = ((res * 2) + fastpow(2, cnt - 1, MOD)) % MOD;
    }
    cnt++;
    
    //print(cur << ' ' << pre << ' ' << cnt << ' ' << res);

    for (int i = 0; i < m; i++) {
        if (g[cur][i] == pre) {
            continue;
        }
        dfs(g[cur][i], cur, cnt, res);
    }
}

int main() {
    input(n);
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    g[1].push_back(-1);
    llint cnt = 0;
    llint res = 0;
    dfs(1, -1, cnt, res);
    print(res);
    return 0;
}
