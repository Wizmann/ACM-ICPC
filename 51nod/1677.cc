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

const llint MOD = 1000000007LL;
const int SIZE = 111111;

int n, k;
llint ans = 0;

vector<int> g[SIZE];
vector<llint> C;

llint fastpow(llint a, llint b) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

llint C_(int a, int b) {
    if (b > a) {
        return 0;
    }
    llint res = 1;
    for (int i = 0; i < b; i++) {
        res = res * (a - i) % MOD;
        res = res * fastpow(i + 1, MOD - 2) % MOD;
    }
    return res;
}

void init() {
    llint res = 1;
    C.resize(n + 1, 0);
    
    for (int i = k; i <= n; i++) {
        C[i] = res;
        res *= i + 1;
        res %= MOD;
        res *= fastpow(i - k + 1, MOD - 2);
        res %= MOD;
    }
    /*
    for (int i = 0; i <= n; i++) {
        print(i);
        assert(C_(i, k) == C[i]);
    }
    */
}

int dfs(int pre, int cur) {
    int sum = 0;
    for (auto next: g[cur]) {
        if (next == pre) {
            continue;
        }
        sum += dfs(cur, next);
    }
    
    if (pre == -1) {
        return -1;
    }
    
    int left = sum + 1;
    int right = n - sum - 1;
        
    ans += (C[n] - C[left] - C[right]) % MOD;
    ans = (ans % MOD + MOD) % MOD;
    return sum + 1;
}

int main() {
    int a, b;
    input(n >> k);
    init();
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(-1, 1);
    print(ans);

    return 0;
}
