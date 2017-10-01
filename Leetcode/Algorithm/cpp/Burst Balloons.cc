const int SIZE = 555;

class Solution {
public:
    int maxCoins(vector<int>& nums_) {
        memset(dp, -1, sizeof(dp));
        nums = nums_;
        n = nums.size();
        
        return dfs(0, n - 1);
    }
private:
    int dfs(int l, int r) {
        if (l > r) {
            return 0;
        }
                
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        
        if (r == l) {
            return nums[l] * get_num(l - 1) * get_num(l + 1);
        }
                
        int maxi = 0;
        for (int i = l; i <= r; i++) {
            int a = dfs(l, i - 1);
            int b = dfs(i + 1, r);
            maxi = max(maxi, 
                      a + b + get_num(l - 1) * nums[i] * get_num(r + 1));
        }
        
        return dp[l][r] = maxi;
    }
    
    int get_num(int p) {
        if (p < 0 || p >= n) {
            return 1;
        }
        return nums[p];
    }
private:
    int n;
    vector<int> nums;
    int dp[SIZE][SIZE];
};
