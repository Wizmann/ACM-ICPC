class Solution {
public:
    int arrayNesting(vector<int>& nums_) {
        nums = nums_;
        
        int n = nums.size();
        visit = vector<bool>(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (visit[i]) {
                continue;
            }
            ans = max(ans, dfs(i));
        }
        return ans;
    }
private:
    int dfs(int cur) {
        if (visit[cur]) {
            return 0;
        }
        visit[cur] = true;
        return dfs(nums[cur]) + 1;
    }
    vector<int> nums;
    vector<bool> visit;
};
