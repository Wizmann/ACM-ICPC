class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (i - 1 >= 0) {
                    int a = j <= i - 1  ? triangle[i-1][j]  : Solution::INF;
                    int b = j - 1 >= 0 ? triangle[i-1][j-1] : Solution::INF;
                    triangle[i][j] += min(a, b);
                }
            }
        }
        int ans = Solution::INF;
        for (int i = 0; i < n; i++) {
            ans = min(ans, triangle[n-1][i]);
        }
        return ans;
    }
private:
    static const int INF = 1 << 28;
};