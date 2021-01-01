const int SIZE = 555;
int dp[SIZE][SIZE];

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue_) {
        stoneValue = stoneValue_;
        prefixsum = stoneValue;
        n = stoneValue.size();
        for (int i = 1; i < n; i++) {
            prefixsum[i] += prefixsum[i - 1];
        }
        memset(dp, -1, sizeof(dp));
        return dfs(0, n);
    }
    
    int presum(int l, int r) {
        int ll = l == 0? 0: prefixsum[l - 1];
        int rr = r == 0? 0: prefixsum[r - 1];
        return rr - ll;
    }
private:
    int dfs(int l, int r) {
        if (r - l == 1) {
            return 0;
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        
        int res = 0;
        for (int i = l + 1; i < r; i++) {
            int tot = 0;
            int ll = presum(l, i);
            int rr = presum(i, r);
            if (ll < rr) {
                tot += dfs(l, i) + ll;
            } else if (ll > rr) {
                tot += dfs(i, r) + rr;
            } else {
                tot += max(dfs(l, i), dfs(i, r)) + ll;
            }
            res = max(res, tot);
        }
        return dp[l][r] = res;
    }
private:
    int n;
    vector<int> stoneValue;
    vector<int> prefixsum;
};
