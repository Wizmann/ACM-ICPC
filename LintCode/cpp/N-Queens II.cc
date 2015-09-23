class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        ans = 0;
        vector<int> board;
        dfs(0, n, board);
        return ans;
    }
private:
    void dfs(int ptr, int n, vector<int>& board) {
        if (ptr == n) {
            ans++;
            return;
        }
        
        for (int i = 0; i < n; i++) {
            int u = 1 << i;
            int a = u;
            int b = u;
            bool flag = true;
            for (auto iter = board.rbegin();
                    iter != board.rend();
                    ++iter) {
                if (u & *iter) {
                    flag = false;
                    break;
                }
                if ((a << 1) < (1 << n)) {
                    a <<= 1;
                    if (a & *iter) {
                        flag = false;
                        break;
                    }
                }
                if ((b >> 1) > 0) {
                    b >>= 1;
                    if (b & *iter) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                board.push_back(u);
                dfs(ptr + 1, n, board);
                board.pop_back();
            }
        }
    }
private:
    int ans;
};

