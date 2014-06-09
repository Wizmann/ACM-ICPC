const int mx[4] = {-1, 1, 0, 0};
const int my[4] = {0 , 0, 1, -1};

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty()) {
            return;
        }
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            do_fill(i, 0, board);
            do_fill(i, m - 1, board);
        }
        for (int i = 0; i < m; i++) {
            do_fill(0, i, board);
            do_fill(n - 1, i, board);
        }
        prettify(board);
    }
    
    void do_fill(int y, int x, vector<vector<char> > &board) {
        if (board[y][x] != 'O') {
            return;
        } else {
            queue<Point> q;
            q.push(Point(y, x));
            while (!q.empty()) {
                Point now = q.front();
                q.pop();
                board[now.y][now.x] = 'y';
                for (int i = 0; i < 4; i++) {
                    Point next = now;
                    next.y += my[i];
                    next.x += mx[i];
                    
                    if (inMap(next) && board[next.y][next.x] == 'O') {
                        board[next.y][next.x] = 'y';
                        q.push(next);
                    }
                }
            }
        }
    }
private:
    struct Point {
        int y, x;
        Point(int iy, int ix): y(iy), x(ix) {}
    };
    
    bool inMap(const Point& p) {
        return p.y >= 0 && p.y < n && p.x >= 0 && p.x < m;
    }
    
    void prettify(vector<vector<char> >& board) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'y') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    int n, m;
};
