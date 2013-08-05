class Solution {
public:
    vector<vector<char> > board;
    int n,m;
    const int mx[4] = {0, 1, 0, -1};
    const int my[4] = {1, 0 ,-1, 0};
    
    void solve(vector<vector<char>> &i_board) {
        board = i_board;
        
        n = board.size();
        m = n;
        
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') {
                dfs(0, i);
            }
            if (board[n-1][i] == 'O') {
                dfs(n-1, i);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                dfs(i, 0);
            }
            if (board[i][m - 1] == 'O') {
                dfs(i, m-1);
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(board[i][j] == '#') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
        i_board = board;
    }
    
    void dfs(int y, int x)
    {
        stack<pair<int, int> > st;
        st.push(make_pair(y, x));
        while (!st.empty()) {
            y = st.top().first;
            x = st.top().second;
            st.pop();
            
            board[y][x] = '#';
            for (int i = 0; i < 4; i++) {
                int next_x = x + mx[i];
                int next_y = y + my[i];
                
                if (next_x >= 0 && 
                        next_x < n && 
                        next_y >= 0 && 
                        next_y < n) {
                    if (board[next_y][next_x] == 'O') {
                        st.push(make_pair(next_y, next_x));
                    }
                }
            }
        }
    }    
};
