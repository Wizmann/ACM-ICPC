class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        int n = heights.size();
        int l = 0, r = n - 1;
        int ans = 0;
        
        while (l < r) {
            int a = heights[l];
            int b = heights[r];
            
            ans = max(ans, min(a, b) * (r - l));
            
            if (a < b) {
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};
