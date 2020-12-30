#pragma comment(linker, "/STACK:102400000,102400000") 

typedef long long llint;

const int SIZE = 123456;
const int MOD = 1000000000 + 7;

int dp[SIZE][2][2];

int dfs(int cur, int A, char last) {
    int ans = 0;
    if (cur == 0) {
        return 1;
    }

    int& cached = dp[cur][A][last == 'L'];
    if (cached != -1) {
        return cached;
    }

    if (!A) {
        ans = (ans + dfs(cur - 1, 1, 'A')) % MOD;     // + "A"
    }
    ans = (ans + dfs(cur - 1, A, 'P')) % MOD;         // + "P"

    if (last != 'L') {
        if (cur - 1 >= 0) {
            ans = (ans + dfs(cur - 1, A, 'L')) % MOD; // + "L"
        }
        if (cur - 2 >= 0) {
            ans = (ans + dfs(cur - 2, A, 'L')) % MOD; // + "LL"
        }
    }

    return cached = ans;
}

class Solution {
public:
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            dfs(i, 0, 'L');
            dfs(i, 1, 'O');
        }
        return dfs(n, 0, 'O');
    }
};
