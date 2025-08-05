const int INF = 0x3f3f3f3f;
const int my[] = {-1, 0, 1, 0};
const int mx[] = {0, 1, 0, -1};

struct GridPoint {
    int y, x;
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
		dp = vector<vector<int> >(n);
		for (int i = 0; i < n; i++) {
			dp[i] = vector<int>(n, INF);
		}
        dp[0][0] = grid[0][0];
        
        queue<GridPoint> q;
        q.push({0, 0});
		while (!q.empty()) {
            GridPoint cur = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int ny = cur.y + my[i];
                int nx = cur.x + mx[i];
                
                if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
                    continue;
                }
                
                if (dp[ny][nx] > max(dp[cur.y][cur.x], grid[ny][nx])) {
                    q.push({ny, nx});
                    dp[ny][nx] = max(dp[cur.y][cur.x], grid[ny][nx]);
                }
            }
		}
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
		return dp[n - 1][n - 1];
    }
private:
	int n;
	vector<vector<int> > dp;
};
