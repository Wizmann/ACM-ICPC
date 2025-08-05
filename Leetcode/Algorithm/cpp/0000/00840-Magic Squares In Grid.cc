class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) {
            return 0;
        }
        int m = grid[0].size();
        if (m == 0) {
            return 0;
        }

        int ans = 0;
        for (int i = 1; i + 1 < n; i++) {
            for (int j = 1; j + 1 < m; j++) {
                if (grid[i][j] == 5 && check(grid, i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
private:
    bool check(const vector<vector<int> >& grid, int y, int x) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int a = grid[y + i][x + j];
                int b = grid[y - i][x - j];
                if (a + b != 10 || a <= 0 || a >= 10 || b <= 0 || b >= 10) {
                    return false;
                }
            }
        }
        return true;
    }
};
