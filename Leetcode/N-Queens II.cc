class Solution {
public:
    int totalNQueens(int in) {
        ans = 0;
        n = in;
        solve(0);
        return ans;
    }
    
    void solve(int line) {
        if (line == n) {
            ans++;
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (col[i]) continue;
            bool flag = true;
            for (int j = 0; j < line; j++) {
                if (abs(j - line) == abs(i - col_pos[j])) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                col_pos[line] = i;
                col[i] = 1;
                solve(line + 1);
                col[i] = 0;
            }
        }
    }

    static const int SIZE = 24;
    
    int ans;
    int n;
    int col[SIZE], col_pos[SIZE];
};
