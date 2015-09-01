class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        if (n == 0) {
            return 0;
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                int add = numeric_limits<int>::max();
                if (j - 1 >= 0) {
                    add = min(add, triangle[i - 1][j - 1]);
                }
                if (j < i) {
                    add = min(add, triangle[i - 1][j]);
                }
                triangle[i][j] += add;
            }
        }
        
        return accumulate(
            triangle[n - 1].begin(),
            triangle[n - 1].end(),
            numeric_limits<int>::max(),
            [](const int a, const int b) {
                return min(a, b);
            });
    }
};

