class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int> > res = M;
        
        int n = M.size();
        int m = M[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt = 0;
                int val = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int ny = dy + i;
                        int nx = dx + j;
                        
                        if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
                            cnt++;
                            val += M[ny][nx];
                        }
                    }
                }
                res[i][j] = val / cnt;
            }
        }
        return res;
    }
};
