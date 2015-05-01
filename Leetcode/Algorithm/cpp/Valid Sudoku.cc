class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0;j < 3; j++) {
                if (!check_block(board, i, j)) {
                    goto FAIL;
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            if (!check_x(board, i)) {
                goto FAIL;
            }
            if (!check_y(board, i)) {
                goto FAIL;
            }
        }
        return true;
FAIL:
        return false;
    }
private:
    bool check_block(vector<vector<char> > &board, int yn, int xn)
    {
        set<int> st;
        int y = yn * 3;
        int x = xn * 3;
        int dot = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[y + i][x + j] == '.') {
                    dot++;
                } else {
                    st.insert(board[y + i][x + j] - '0');
                }
            }
        }
        return dot + st.size() == 9;
    }
    
    bool check_x(vector<vector<char> > &board, int x)
    {
        set<int> st;
        int dot = 0;
        for (int i = 0; i < 9; i++) {
            if (board[i][x] == '.') {
                dot++;
            } else {
                st.insert(board[i][x] - '0');
            }
        }
        return dot + st.size() == 9;
    }
    
    bool check_y(vector<vector<char> > &board, int y)
    {
        set<int> st;
        int dot = 0;
        for (int i = 0; i < 9; i++) {
            if (board[y][i] == '.') {
                dot++;
            } else {
                st.insert(board[y][i] - '0');
            }
        }
        return dot + st.size() == 9;
    }
};
