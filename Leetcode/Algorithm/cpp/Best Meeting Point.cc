class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) {
            return 0;
        }
        int m = grid[0].size();
        if (m == 0) {
            return 0;
        }
        
        vector<int> xs, ys;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    xs.push_back(j);
                    ys.push_back(i);
                }
            }
        }
        
        nth_element(xs.begin(), xs.begin() + xs.size() / 2, xs.end());
        nth_element(ys.begin(), ys.begin() + ys.size() / 2, ys.end());
        
        int res = 0;
        for (auto u: xs) {
            res += abs(u - xs[xs.size() / 2]);
        }
        for (auto u: ys) {
            res += abs(u - ys[ys.size() / 2]);
        }
        return res;
    }
};
