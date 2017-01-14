#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int MOD = 1000000007;
const int BITS = 30;

class Solution {
public:
    Solution(vector<int>& nums_): nums(nums_) {
        nums.push_back(0);
    }

    llint solve() {
        llint ans = 0;
        for (int i = 0; i < 32; i++) {
            ans += solve(i) % MOD;
            ans %= MOD;
            // print(solve(i) % MOD);
        }
        return ans;
    }
private:
    llint solve(int idx) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        llint ans = 0;

        for (int i = 0; i < n; i++) {
            int cur = nums[i] & (1 << idx);
            if (cur == 0) {
                ans += calc(l, r - 1, (1 << idx));
                ans %= MOD;
                l = r = i + 1;
                continue;
            }
            r++;
        }
        return ans;
    }
    
    llint calc(int l, int r, llint value) {
        if (r < l) {
            return 0;
        }
        if (l == r) {
            return value * nums[l] % MOD;
        }
        llint res = 0;
        // print(l << ' ' << r);

        for (int i = 0; i < 32; i++) {
            llint tot = 0;
            int cnt = 0;
            for (int j = l; j <= r; j++) {
                int cur = nums[j] & (1 << i);
                if (cur == 0) {
                    cnt++;
                } else {
                    tot += 1LL * cnt * (cnt + 1) / 2;
                    cnt = 0;
                }
            }
            tot += 1LL * cnt * (cnt + 1) / 2;
            tot = 1LL * (r - l + 1) * (r - l + 2) / 2 - tot;

            res += 1LL * tot * (1 << i) % MOD * value % MOD;
            res %= MOD;
        }

        return res;
    }
private:
    vector<int>& nums;
};

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    vector<int> ns;

    input(n);
    ns.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    auto S = Solution(ns);
    // print("fuck");
    print(S.solve());

    return 0;
}
