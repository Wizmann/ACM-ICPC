const int my[4] = {0, 1, 0, -1};
const int mx[4] = {1, 0, -1, 0};

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res;
        if (!n) return res;
        for (int i = 0; i < n; i++) {
            vector<int> vec;
            for (int j = 0; j < n; j++) {
                vec.push_back(0);
            }
            res.push_back(vec);
        }
        
        int g = 1;
        int dir = 0;
        int x = 0, y = 0;
        while (1) {
            res[y][x] = g++;
            
            if (g > n * n) break;
            
            while (1) {
                int ny = y + my[dir];
                int nx = x + mx[dir];
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !res[ny][nx]) {
                    y = ny;
                    x = nx;
                    break;
                } else {
                    dir = (dir + 1) % 4;
                }
            }
        }
        return res;
    }
};
