const int MOD = 1000000000 + 7;

class Solution {
public:
    int numDecodings(string s) {
        n = s.size();
        dp = vector<int>(n + 1, 0);

        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            char pre = i > 0? s[i - 1]: '\0';
            char cur = s[i];

            dp[i + 1] += 1LL * dp[i] * calc(cur) % MOD;
            if (i - 1 >= 0) {
                dp[i + 1] += 1LL * dp[i - 1] * calc(pre, cur) % MOD;
            }
            dp[i + 1] %= MOD;
        }

        return dp[n];
    }
private:
    int calc(char cur) {
        if (cur == 0) {
            return 0;
        }
        if (cur == '0') {
            return 0;
        }
        if (cur == '*') {
            return 9;
        }
        return 1;
    }

    int calc(char pre, char cur) {
        if (pre == '\0' || pre == '0') {
            return 0;
        }

        int l0 = pre == '*'? 1: pre - '0';
        int r0 = pre == '*'? 9: pre - '0';

        int l1 = cur == '*'? 1: cur - '0';
        int r1 = cur == '*'? 9: cur - '0';

        int cnt = 0;
        for (int i = l0; i <= r0; i++) {
            for (int j = l1; j <= r1; j++) {
                int u = i * 10 + j;
                if (1 <= u && u <= 26) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
private:
    int n;
    vector<int> dp;
};


