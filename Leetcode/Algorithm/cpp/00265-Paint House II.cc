const int INF = 0x3f3f3f3f;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        const int n = costs.size();
        if (n == 0) {
            return 0;
        }
        
        const int k = costs[0].size();
        vector<int> dp = costs[0];
        
        for (int i = 1; i < n; i++) {
            pair<int, int> min1, min2;
            get_min(dp, min1, min2);
            vector<int> next(k, INF);
            for (int j = 0; j < k; j++) {
                if (j != min1.second) {
                    next[j] = costs[i][j] + min1.first;
                } else {
                    next[j] = costs[i][j] + min2.first;
                }
            }
            dp = next;
        }
        return accumulate(dp.begin(), dp.end(), INF, [](int a, int b) { return min(a, b); });
    }
private:
    void get_min(const vector<int>& nums, pair<int, int>& min1, pair<int, int>& min2) {
        min1 = min2 = {INF, -1};
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            pair<int, int> p = {nums[i], i};
            if (p < min1) {
                min2 = min1;
                min1 = p;
            } else if (p < min2) {
                min2 = p;
            }
        }
    }
};
