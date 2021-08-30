const int INF = 0x3f3f3f3f;

const int N = 14;
const int M = 15;

int dp[(1 << N) + 12][M + 1];

class Solution {
public:
    int minSessions(const vector<int>& tasks_, int sessionTime) {
        tasks = tasks_;
        n = tasks.size();
        m = sessionTime;
        memset(dp, INF, sizeof(dp));
        
        return dfs(0, 0);
    }
private:
    int dfs(int status, int remains) {
        if (dp[status][remains] < INF) {
            return dp[status][remains];
        }
        
        if (status == (1 << n) - 1) {
            return 0;
        }
        
        int mini = INF;
        for (int i = 0; i < n; i++) {
            assert(tasks[i] <= M);
            if (status & (1 << i)) {
                continue;
            }
            if (tasks[i] > remains) {
                mini = min(mini, 1 + dfs(status, m));
            } else {
                mini = min(mini, dfs(status | (1 << i), remains - tasks[i]));
            }
        }
        
        return dp[status][remains] = mini;
    }
        
    vector<int> tasks;
    int n;
    int m;
};
