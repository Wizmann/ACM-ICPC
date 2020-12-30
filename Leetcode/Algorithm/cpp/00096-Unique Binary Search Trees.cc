// 卡特兰数
class Solution {
public:
    int numTrees(int n) {
        long long x = 1;
        for (int i = 0; i < n; i++) {
            x *= (2 * n - i);
        }
        for (int i = 0; i < n; i++) {
            x /= (i + 1);
        }
        x /= (n + 1);
        return x;
    }
};

// ---

// 记忆化搜索
class Solution {
public:
    int numTrees(int n)
    {
        dp.resize(n + 5);
        fill(dp.begin(), dp.end(), -1);
        return do_numTrees(n);
    }
private:
    int do_numTrees(int n)
    {
        if (dp[n] != -1) {
            return dp[n];
        }
        if (n <= 1) {
            return dp[n] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += do_numTrees(i - 1) * do_numTrees(n - i);
        }
        return dp[n] = ans;
    }
private:
    vector<int> dp;
};
