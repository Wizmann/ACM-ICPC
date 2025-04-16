struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return p.first * 64 + p.second;
    }
};

class Solution {
public:
    long long minOperations(const vector<vector<int>>& queries) {
        long long total = 0;
        for (const auto& q: queries) {
            long long cnt = calc(q[1]) - calc(q[0] - 1);
            total += (cnt + 1) / 2;
        }
        return total;
    }

private:
    unordered_map<pair<int, int>, long long, pair_hash> dp;

    int bin_length(int x) {
        return std::bit_width(static_cast<unsigned int>(x));
    }

    long long calc(long long x) {
        int n = bin_length(x);
        long long res = dfs(x, n, 0, 0, true);
        return res;
    }

    long long dfs(long long x, int n, int pre, int cur, bool flag) {
        if (cur == n) {
            return (pre + 1) / 2;
        }
        
        pair<int, int> key = {pre, n - cur};

        if (!flag) {
            if (dp.count(key)) return dp[key];
        }

        long long total = 0;
        int bit = (x & (1 << (n - cur - 1))) ? 1 : 0;
        for (int i = 0; i <= 1; ++i) {
            int nxt = (pre || i) ? pre + 1 : pre;

            if (flag) {
                if (i == bit) {
                    total += dfs(x, n, nxt, cur + 1, true);
                } else if (i < bit) {
                    total += dfs(x, n, nxt, cur + 1, false);
                }
            } else {
                total += dfs(x, n, nxt, cur + 1, false);
            }
        }

        if (!flag) {
            dp[key] = total;
        }

        return total;
    }
};
