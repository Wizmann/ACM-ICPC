const int my[] = {-1, -1, -1,  0,  0,  1, 1, 1};
const int mx[] = {-1,  0,  1, -1,  1, -1, 0, 1};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        n = board.size();
        m = board[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt = 0;
                for (int k = 0; k < 8; k++) {
                    int y = i + my[k];
                    int x = j + mx[k];
                    if (is_valid(y, x) && (board[y][x] & 1) == 1) {
                        cnt++;
                    }
                }
                if (board[i][j] && (cnt == 2 || cnt == 3)) {
                    board[i][j] |= 2;
                }
                if (!board[i][j] && cnt == 3) {
                    board[i][j] |= 2;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] >>= 1;
            }
        }
    }
private:
    bool is_valid(int y, int x) {
        return y >= 0 && y < n && x >= 0 && x < m;
    }
private:
    int n, m;
};
