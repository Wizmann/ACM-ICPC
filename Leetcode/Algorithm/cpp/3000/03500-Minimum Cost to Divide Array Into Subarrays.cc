using llint = long long;
const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int SIZE = 1024;

llint dp[SIZE];

class Solution {
public:
    long long minimumCost(vector<int>& nums_, vector<int>& cost_, int k_) {
        n = nums_.size();
        k = k_;
        nums = nums_;
        cost = cost_;

        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }

        for (int i = 1; i < n; i++) {
            cost[i] += cost[i - 1];
        }
        
        memset(dp, -1, sizeof(dp));

        return dfs(0);
    }
private:
    llint dfs(int cur) {
        if (cur == n) {
            return 0;
        }
        if (dp[cur] != -1) {
            return dp[cur];
        }
        llint mini = INFLL;
        for (int i = cur; i < n; i++) {
            llint a = 1LL * nums[i] * presum(cost, cur, i) + k * presum(cost, cur, n - 1);
            llint v = a + dfs(i + 1);
            mini = min(mini, v);
        }
        return dp[cur] = mini;
    }

    inline llint presum(const vector<int>& pre, int l, int r) {
        llint tot = pre[r];
        if (l - 1 >= 0) {
            tot -= pre[l - 1];
        }
        return tot;
    }
private:
    int n;
    int k;
    vector<int> nums;
    vector<int> cost;
};
