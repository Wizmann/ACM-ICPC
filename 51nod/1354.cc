#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint MOD = 1000000007;

int n, k, idx;
vector<int> nums;
vector<llint> dp;
map<int, int> factor_mp;
map<int, int> factor_mp_r;

void make_mp() {
    factor_mp.clear();
    factor_mp_r.clear();
    for (llint i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            llint a = i;
            llint b = k / i;
            factor_mp[a] = factor_mp[b] = -1;
        }
    }

    idx = 0;
    for (auto& p: factor_mp) {
        p.second = idx++;
        factor_mp_r[p.second] = p.first;
    }
}

void solve() {
    for (auto num: nums) {
        if (k % num != 0) {
            continue;
        }
        for (int i = idx - 1; i >= 0; i--) {
            if (dp[i] == 0) {
                continue;
            }
            llint a = factor_mp_r[i];
            llint b = a * num;
            if (factor_mp.find(b) == factor_mp.end()) {
                continue;
            }
            dp[factor_mp[b]] += dp[i];
            dp[factor_mp[b]] %= MOD;
        }
    }
    /*
    for (auto num: dp) {
        printf("%lld ", num);
    }
    puts("");
    */
}

int main() {
    int T;
    input(T);
    while (T--) {
        input(n >> k);
        nums.resize(n);
        for (int i = 0; i < n; i++) {
            input(nums[i]);
        }
        make_mp();
        dp.clear();
        dp.resize(idx);
        dp[0] = 1;
        solve();
        print(dp[idx - 1]);
    }
    return 0;
}
