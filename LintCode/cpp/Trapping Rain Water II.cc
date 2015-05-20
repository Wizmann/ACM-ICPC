template <typename T>
class MinHeap: public priority_queue<T, vector<T>, greater<T> > {};

class Solution {
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int> > &heights) {
        int n = heights.size();
        if (n == 0) {
            return 0;
        }
        int m = heights[0].size();
        if (m == 0) {
            return 0;
        }
        
        vector<vector<int> > waters;
        waters.resize(n);
        for (auto& v: waters) {
            v.resize(m);
        }
        
        MinHeap<
            pair<
                int,
                pair<int, int>
            >
        > q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    q.push({
                        heights[i][j],
                        { i, j }
                    });
                    waters[i][j] = heights[i][j];
                } else {
                    waters[i][j] = INF;
                }
            }
        }
        
        const int mx[] = {0, 1, 0, -1};
        const int my[] = {-1, 0, 1, 0};
        
        set<pair<int, int> > in_queue;

        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            
            int y = p.second.first;
            int x = p.second.second;
            
            for (int i = 0; i < 4; i++) {
                int ny = y + my[i];
                int nx = x + mx[i];
                
                if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                    continue;
                }
                
                int hh = max(
                    heights[ny][nx],
                    min(
                        waters[ny][nx],
                        waters[y][x]
                    )
                );

                if (hh != waters[ny][nx]) {
                    waters[ny][nx] = hh;
                    if (in_queue.find({ny, nx}) != in_queue.end()) {
                        continue;
                    }

                    q.push({
                        hh,
                        { ny, nx }
                    });
                    in_queue.insert({ny, nx});
                }
            }
        }
        

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += waters[i][j] - heights[i][j];
            }
        }
        return ans;
    }
private:
    static const int INF = 0x3f3f3f3f;
};
