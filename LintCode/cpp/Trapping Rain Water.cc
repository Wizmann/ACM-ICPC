class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        int n = heights.size();
        
        int l = 0;
        int r = n - 1;
        
        int lmax = -1;
        int rmax = -1;
        
        int res = 0;
        while (l < r) {
            lmax = max(lmax, heights[l]);
            rmax = max(rmax, heights[r]);
            
            if (lmax < rmax) {
                res += lmax - heights[l];
                l++;
            } else {
                res += rmax - heights[r];
                r--;
            }
        }
        return res;
    }
};
