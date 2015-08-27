class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        int n = heights.size();
        int l = 0;
        int r = n - 1;
        int ans = 0;
        
        while (l < r) {
            ans = max(
                ans,
                min(heights[l], heights[r]) * (r - l)
            );
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};
