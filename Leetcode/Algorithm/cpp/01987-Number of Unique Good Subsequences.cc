typedef long long llint;

const int MOD = 1000000000 + 7;

class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        const int n = binary.size();
        dp = vector<int>(n + 1, -1);
        next0.resize(n);
        next1.resize(n);

        find_next(binary, next0, 0);
        find_next(binary, next1, 1);

        int res = solve(binary, n, 0, true);
        return res;
    }
private:
    void find_next(const std::string& binary, vector<int>& next, int pivot) {
        const int n = binary.size();
        int pre = n;
        for (int i = n - 1; i >= 0; i--) {
            if (binary[i] == '0' + pivot) {
                pre = i;
            }
            next[i] = pre;
        }
    }


    llint solve(const std::string& binary, int n, int cur, bool isFirst) {
        if (!isFirst && dp[cur] != -1) {
            return dp[cur];
        }

        llint res = isFirst? 0: 1;
        if (cur == n) {
            return res;
        }

        // check 0
        int nxt0 = next0[cur];
        if (nxt0 < n) {
            if (isFirst) {
                res++;
            } else {
                res += solve(binary, n, nxt0 + 1, false);
            }
        }

        // check 1
        int nxt1 = next1[cur];
        if (nxt1 < n) {
            res += solve(binary, n, nxt1 + 1, false);
        }

        return dp[cur] = res % MOD;
    }

    vector<int> dp;
    vector<int> next0, next1;
};


