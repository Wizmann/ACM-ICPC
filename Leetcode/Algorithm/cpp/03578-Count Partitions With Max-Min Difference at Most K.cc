const int MOD = 1e9 + 7;

int quickpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = (1LL * res * a) % MOD;
        }
        a = (1LL * a * a) % MOD;
        b /= 2;
    }
    return res;
}

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        multiset<int> st;
        int n = nums.size();

        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            st.insert(nums[i - 1]);
            assert(!st.empty());
            int pre = (i - 1) - st.size() + 1;
            while (*st.rbegin() - *st.begin() > k) {
                st.erase(st.find(nums[pre]));
                pre++;
            }
            if (pre - 1 < 0) {
                dp[i] = quickpow(2, i - 1);
            } else {
                assert(i - 1 >= 0);
                assert(pre - 1 >= 0);
                dp[i] = ((dp[i - 1] - dp[pre - 1]) % MOD + MOD) % MOD;
            }
            dp[i] = (1LL * dp[i] + dp[i - 1]) % MOD;
            // cout << i << ' ' << pre << ' ' << dp[i] << endl;
        }

        return ((dp[n] - dp[n - 1]) % MOD + MOD) % MOD;
    }
};
