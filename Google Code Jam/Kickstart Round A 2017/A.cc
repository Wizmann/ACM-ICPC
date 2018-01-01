// it cost me about 5 mins to get the final answer

#include <cstdio>
#include <iostream>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int MOD = 1000000000 + 7;

llint solve(int n, int m) {
    llint res = 0;
    for (int i = 0; i < min(n, m); i++) {
        res += 1LL * (n - i) * (m - i) % MOD * min(m, i);
        res %= MOD;
    }
    return res;
}

int main() {
    int T;
    input(T);
    for (int case_ = 0; case_ < T; case_++) {
        int n, m;
        input(n >> m);
        printf("Case #%d: %lld\n", case_ + 1, solve(n, m));
    }
    return 0;
}


