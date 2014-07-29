class Solution {
public:
    bool solveSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (int k = 1; k <= 9; k++) {
                    board[i][j] = '0' + k;
                    if (validSudoku(board, i, j) && solveSudoku(board)) {
                        return true;
                    }
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    }
private:
    bool validSudoku(vector<vector<char> > &board, int y, int x) {
        for (int i = 0; i < 9; i++) {
            if (board[y][x] == board[y][i] && x != i) {
                return false;
            }
            if (board[y][x] == board[i][x] && y != i) {
                return false;
            }
        }
        for (int i = (y / 3) * 3; i < (y / 3) * 3 + 3; i++) {
            for (int j = (x / 3) * 3; j < (x / 3) * 3 + 3; j++) {
                if (i == y && j == x) {
                    continue;
                }
                if (board[i][j] == board[y][x]) {
                    return false;
                }
            }
        }
        return true;
    } 
};
