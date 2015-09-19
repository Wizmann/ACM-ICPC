class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        _board = board;
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!check_grid(i, j)) {
                    return false;
                }
            }
        }
        
        auto add_x = [](int &x, int &y) {
            x += 1;
        };
        auto add_y = [](int &x, int &y) {
            y += 1;
        };
        auto add_lr = [](int &x, int &y) {
            x += 1;
            y += 1;
        };
        auto add_rl = [](int &x, int &y) {
            x -= 1;
            y += 1;
        };
        for (int i = 0; i < 9; i++) {
            if (!check_line(0, i, add_y) || !check_line(i, 0, add_x)) {
                return false;
            }
        }
        return true;
    }
private:
    bool check_grid(int y, int x) {
        int cur = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char c = _board[i + y][j + x];
                if (c != '.') {
                    int val = c - '0';
                    if (cur & (1 << val)) {
                        return false;
                    }
                    cur |= (1 << val);
                }
            }
        }
        return true;
    }
    bool check_line(int y, int x, function<void(int&, int&)> fun) {
        int cur = 0;
        for (int i = 0; i < 9; i++) {
            char c = _board[y][x];
            if (c != '.') {
                int val = c - '0';
                if (cur & (1 << val)) {
                    return false;
                }
                cur |= (1 << val);
            }
            fun(x, y);
        }
        return true;
    }
private:
    vector<vector<char>> _board;
};
