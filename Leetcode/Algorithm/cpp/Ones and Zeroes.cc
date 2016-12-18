const int SIZE = 111;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp = vector<vector<int> >(SIZE, vector<int>(SIZE, -1));
        dp[0][0] = 0;
        for (auto str: strs) {
            int cnt_0 = strcount(str, '0');
            int cnt_1 = strcount(str, '1');
            
            for (int i = SIZE - 1; i >= 0; i--) {
                for (int j = SIZE - 1; j >= 0; j--) {
                    if (dp[i][j] == -1) {
                        continue;
                    }
                    int ii = i + cnt_0;
                    int jj = j + cnt_1;
                    if (ii >= SIZE || jj >= SIZE) {
                        continue;
                    }
                    dp[ii][jj] = max(dp[ii][jj], dp[i][j] + 1);
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
private:
    int strcount(const string& str, char c) {
        int ans = 0;
        for (char x: str) {
            ans += x == c;
        }
        return ans;
    }
private:
    vector<vector<int> > dp;
};
