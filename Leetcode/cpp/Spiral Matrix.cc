const int mx[] = {1, 0, -1, 0};
const int my[] = {0, 1, 0, -1};
const int VISITED = 0x3f3f3f3f;

class Solution {
private:
    int n, m;
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int dir = 0;
        n = matrix.size();
        if (n == 0) {
            return res;
        }
        m = matrix[0].size();
        int y = 0, x = 0;
        while (1) {
            res.push_back(matrix[y][x]);
            matrix[y][x] = VISITED;
            dir = next_dir(y, x, dir, matrix);
            y += my[dir];
            x += mx[dir];
            if (dir == -1) {
                break;
            }
        }
        return res;
    }
private:
    int next_dir(int y, int x, int dir, vector<vector<int> > &matrix) {
        for (int i = 0; i < 4; i++) {
            int ny = y + my[dir];
            int nx = x + mx[dir];
            if (ny < n && ny >= 0 && nx < m && nx >= 0 && matrix[ny][nx] != VISITED) {
                return dir;
            }
            dir = (dir + 1) % 4;
        }
        return -1;  
    }
};
