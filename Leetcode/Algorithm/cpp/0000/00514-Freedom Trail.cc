const int SIZE = 111;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        
        for (int i = 0; i < n; i++) {
            char c = ring[i];
            if (mp.count(c) == 0) {
                mp[c] = vector<int>();
            }
            mp[c].push_back(i);
        }
        
        memset(dp, INF, sizeof(dp));
        
        int p = 0;
        dp[0][0] = 0;
        
        for (int i = 0; i < m; i++) {
            int q = p ^ 1;
            memset(dp[q], INF, sizeof(dp[q]));
            
            for (int j = 0; j < n; j++) {
                if (dp[p][j] == INF) {
                    continue;
                }

                char c = key[i];
                for (auto next: mp[c]) {
                    int mv = dis(next, j, n);
                    dp[q][next] = min(dp[q][next], dp[p][j] + mv + 1);
                }
            }
            p ^= 1;
        }
        
        int ans = INF;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[p][i]);
        }
        return ans;
    }
private:
    int dis(int a, int b, int n) {
        if (a > b) {
            swap(a, b);
        }
        return min(b - a, a + n - b);
    }
private:
    map<char, vector<int> > mp;
    int dp[2][SIZE];
};
