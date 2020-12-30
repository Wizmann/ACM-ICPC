typedef long long llint;

const int SIZE = 12;

int dp[SIZE][1 << SIZE];

class Solution {
public:
    int numSquarefulPerms(vector<int>& A_) {
        A = A_;
        n = A.size();
        memset(dp, -1, sizeof(dp));
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += dfs(i, (1 << n) - 1);
        }
        
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[A[i]]++;
        }
        
        for (auto p: mp) {
            for (int i = 1; i <= p.second; i++) {
                ans /= i;
            }
        }
        
        return ans;
    }
private:
    int dfs(int last, int status) {
        if (status == (1 << last)) {
            return 1;
        }
        if (dp[last][status] != -1) {
            return dp[last][status];
        }
        int res = 0;
        assert(status & (1 << last));
        int key = status ^ (1 << last);
        for (int i = 0; i < n; i++) {
            if (key & (1 << i)) {
                if (isSquare(A[last], A[i])) {
                    res += dfs(i, key);
                }
            }
        }
        
        return dp[last][status] = res;
    }
    
    bool isSquare(llint a, llint b) {
        llint u = sqrt(a + b);
        return u * u == a + b; 
    }

private:
    int n;
    vector<int> A;
};
