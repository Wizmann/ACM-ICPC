const int N = 12;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = {-1, ""};
            }
        }
        n = nums.size();
        if (n == 1) {
            return to_string(nums[0]);
        }
        string ans = solve(nums, 0, n, INF).second;
        return ans.substr(1, ans.size() - 2);
    }
private:
    pair<int, string> solve(const vector<int>& nums, int l, int r, int mm) {
        assert(l != r);
        
        if (r == l + 1) {
            return {nums[l], to_string(nums[l])};
        }
        
        if (dp[l][r].first != -1) {
            return dp[l][r];
        }
        
        int ans = nums[l];
        string res = to_string(nums[l]);
        for (int i = l + 1; i < r; i++) {
            res += "/";
            res += to_string(nums[i]);
            ans /= nums[i];
        }
        
        for (int i = l + 1; i < r; i++) {
            auto p1 = solve(nums, l, i, INF);
            auto p2 = solve(nums, i, r, -INF);
            
            int cur = -1;
            if (p2.first == 0) {
                cur = INF;
            } else {
                cur = p1.first / p2.first;
            }
            
            if (mm == INF && cur > ans) {
                ans = cur;
                res = p1.second + "/" + p2.second;
            }
            if (mm == -INF && cur < ans) {
                ans = cur;
                res = p1.second + "/" + p2.second;
            }
        }
        return {ans, "(" + res + ")"};
    }
private:
    int n;
    pair<int, string> dp[N][N];
};
