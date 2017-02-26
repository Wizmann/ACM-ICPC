class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board_, vector<int>& click_) {
        memset(visit, 0, sizeof(visit));
        
        int y = click_[0];
        int x = click_[1];
        
        board = board_;
        
        n = board.size();
        m = board[0].size();
        
        dfs(y, x);
        
        return board;
    }
private:
    void dfs(int y, int x) {
        visit[y][x] = 1;
        
        if (board[y][x] == 'M') {
            board[y][x] = 'X';
            return;
        }
        
        if (board[y][x] != 'E') {
            return;
        }
        
        int cnt = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int ny = y + i;
                int nx = x + j;
                if (0 <= ny && ny < n && 0 <= nx && nx < m && board[ny][nx] == 'M') {
                    cnt++;
                }
            }
        }
        if (cnt) {
            board[y][x] = '0' + cnt;
            return;
        }
        
        board[y][x] = 'B';
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int ny = y + i;
                int nx = x + j;
                if (0 <= ny && ny < n && 0 <= nx && nx < m && !visit[ny][nx]) {
                    dfs(ny, nx);
                }
            }
        }
    }
    
private:
    int n, m;
    vector<vector<char> > board;
    char visit[55][55];
};
