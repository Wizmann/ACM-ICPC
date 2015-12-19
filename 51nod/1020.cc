#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint MOD = 1000000000 + 7;
const int SIZE = 22222;
const int N = 1111;

llint dp[2][SIZE];
unordered_multimap<int, pair<int, int> > mp;
vector<llint> ans;

llint do_sum(int ptr, int a, int b) {
    llint A = dp[ptr][a];
    llint B = b - 1 >= 0? dp[ptr][b - 1]: 0;
    return ((A - B) % MOD + MOD) % MOD;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T, a, b;
    input(T);
    ans.resize(T);
    
    for (int i = 0; i < T; i++) {
        scanf("%d%d", &a, &b);
        mp.insert({a, {b, i}});
    }
    
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < SIZE; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i < N; i++) {
        int pre = (i ^ 1) & 1;
        int cur = i & 1;
        memset(dp[cur], 0, sizeof(dp[cur]));
        
        for (int j = 0; j < SIZE; j++) {
            dp[cur][j] += j - 1 >= 0? dp[cur][j - 1]: 0;
            if (j <= i * (i - 1) / 2) {
                dp[cur][j] += do_sum(pre, j, j - i + 1);
            }
            dp[cur][j] %= MOD;
        }
        
        auto iter_pair = mp.equal_range(i);
        for (auto iter = iter_pair.first; iter != iter_pair.second; ++iter) {
            int value = (iter->second).first;
            int pos = (iter->second).second;
            ans[pos] = dp[cur][value] - (value - 1 >= 0? dp[cur][value - 1]: 0);
        }
    }
    
    for (auto num: ans) {
        printf("%lld\n", ((num % MOD) + MOD) % MOD);
    }
    return 0;
}
    
