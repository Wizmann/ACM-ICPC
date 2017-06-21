const int SIZE = 111;

int dp[SIZE][SIZE][SIZE];

class Solution {
public:
    int removeBoxes(vector<int>& boxes_) {
        boxes = boxes_;
        
        int n = boxes.size();
        memset(dp, -1, sizeof(dp));
        
        return dfs(0, n - 1, 0);
    }
private:
    int dfs(int l, int r, int k) {
        if (l > r) {
            return 0;
        }
        if (dp[l][r][k] != -1) {
            return dp[l][r][k];
        }
        
        while (l < r && boxes[r] == boxes[r - 1]) {
            k++;
            r--;
        }
        
        int maxi = (k + 1) * (k + 1) + dfs(l, r - 1 ,0);
        
        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {
                maxi = max(maxi, dfs(l, i, k + 1) + dfs(i + 1, r - 1, 0));
            }
        }
        return dp[l][r][k] = maxi;
    }
private:
    vector<int> boxes;
};
