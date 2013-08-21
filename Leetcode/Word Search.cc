const int mx[] = {1, 0, -1, 0};
const int my[] = {0, 1, 0, -1};
const int SIZE = 1024;

class Solution {
public:
    int n, m;
    char visit[SIZE][SIZE];
    bool exist(vector<vector<char> > &board, string word) {
        n = board.size();
        m = board[0].size();
        memset(visit, 0 ,sizeof(visit));
        
        bool is_exist = false;
        for (int i = 0; i < n && !is_exist; i++) {
            for (int j = 0; j < m && !is_exist; j++) {
                if (board[i][j] == word[0]) {
                    is_exist = dfs(i, j, word.c_str(), board);
                }
            }
        }
        return is_exist;
    }
    
    bool dfs(int y, int x, const char* word, const vector<vector<char> > &board) {
        if (board[y][x] != *word) {
            return false;
        } else if (*(word+1) == '\0') {
            return true;
        }
        
        bool res = false;
        visit[y][x] = 1;
        for (int i = 0; i < 4 && !res; i++) {
            int next_x = x + mx[i];
            int next_y = y + my[i];
            
            if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n) {
                if (!visit[next_y][next_x]) {
                    res |= dfs(next_y, next_x, word + 1, board);
                }
            }
        }
        visit[y][x] = 0;
        return res;
    }
};
