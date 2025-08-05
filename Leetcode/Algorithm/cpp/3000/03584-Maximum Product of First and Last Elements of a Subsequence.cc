const int INF = 0x3f3f3f3f;

using llint = long long;

class Solution {
public:
    llint maximumProduct(vector<int>& nums, int m) {
        const int n = nums.size();
        int mini = INF;
        int maxi = -INF;
        llint res = 1LL * -INF * INF;
        for (int i = n - m; i >= 0; i--) {
            int cur = nums[i];
            int nxt = nums[i + m - 1];
            mini = min(mini, nxt);
            maxi = max(maxi, nxt);

            res = max(res, 1LL * mini * cur);
            res = max(res, 1LL * maxi * cur);
        }
        return res;
    }
};
