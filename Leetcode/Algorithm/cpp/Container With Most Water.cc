class Solution {
public:
    int maxArea(vector<int> &height) {
        int p = 0, q = height.size() - 1, ans = 0;
        while (p < q) {
            ans = max(ans, (q - p) * min(height[p], height[q]));
            height[p] < height[q] ? p++: q--;
        }
        return ans;
    }
};
