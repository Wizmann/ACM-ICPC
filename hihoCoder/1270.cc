#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 12345;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    Solution(int n_, int m_, int k_, int t_, vector<int>& A_, vector<int>& B_): 
        n(n_), m(m_), k(k_), t(t_), A(A_), B(B_) 
    {
        // pass
    }
    
    int solve() {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int cur = solve(i);
            if (cur == INF) {
                return INF;
            }
            ans += cur;
            
            for (int j = 0; j < m; j++) {
                B[j] /= t;
            }
        }
        return ans;
    }
private:
    int solve(int level) {
        memset(dp, INF, sizeof(dp));
        dp[0] = 0;
        
        for (int i = 0; i < m; i++) {
            if (B[i] == 0) {
                continue;
            }
            for (int j = 0; j <= k; j++) {
                if (dp[j] != INF) {
                    int next = min(k, j + B[i]);
                    dp[next] = min(dp[next], dp[j] + A[i]);
                }
            }
        }
        return dp[k];
    }
private:
    int n, m, k, t;
    vector<int>& A;
    vector<int>& B;
    int dp[SIZE];
};

int main() {
    int q;
    input(q);
    
    int n, m, k, t;
    while (q--) {
        input(n >> m >> k >> t);
        vector<int> A(m, 0);
        vector<int> B(m, 0);
        for (int i = 0; i < m; i++) {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &B[i]);
        }
        Solution s(n, m, k, t, A, B);
        int res = s.solve();
        if (res == INF) {
            puts("No Answer");
        } else {
            print(res);
        }
    }
    return 0;
}
