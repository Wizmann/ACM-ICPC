const int INF = 0x3f3f3f3f;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = INF;
        int maxi = -INF;
        
        int ans = 0;
        for (const auto& array: arrays) {
            int a = *array.begin();
            int b = *array.rbegin();
            
            if (mini != INF) {
                ans = max(ans, abs(b - mini));
                ans = max(ans, abs(maxi - a));
            }
            mini = min(mini, a);
            maxi = max(maxi, b);
        }
        return ans;
    }
};
