const int N = 1111;
const int INF = 0x3f3f3f3f;
int dp[N][N];

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, int> mp;
        int n = stones.size();
        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }
        
        memset(dp, INF, sizeof(dp));
        dp[0][0] = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < N; j++) {
                if (dp[i][j] == INF) {
                    continue;
                }
                for (int k = -1; k <= 1; k++) {
                    if (j + k <= 0) {
                        continue;
                    }
                    int s = stones[i] + j + k;
                    if (mp.find(s) == mp.end()) {
                        continue;
                    }
                    int next = mp[s];
                    dp[next][j + k] = min(dp[next][j + k], dp[i][j] + 1);
                    if (next == n - 1) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
