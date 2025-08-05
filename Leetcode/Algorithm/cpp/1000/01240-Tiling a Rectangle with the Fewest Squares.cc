typedef long long llint;

const llint MOD = 0xdeadbeef;
const int MAXI = 0x3f3f3f3f;

unordered_map<int, int> dp;

class Solution {
public:
    int tilingRectangle(int n_, int m_) {
        n = n_;
        m = m_;
        vector<int> h(n, m);

        return dfs(h);
    }

    int dfs(const vector<int>& h) {
        assert(h.size() == n);
        int tot = accumulate(h.begin(), h.end(), 0);
        if (tot == 0) {
            return 0;
        }

        int hash = get_hash(h);
        if (dp.count(hash)) {
            return dp[hash];
        }

        int res = MAXI;

        int maxi = -MAXI;
        for (auto num: h) {
            if (num > 0) {
                maxi = max(maxi, num);
            }
        }

        assert(maxi > 0);

        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (flag) {
                break;
            }

            if (h[i] != maxi) {
                continue;
            }

            for (int j = i; j < n; j++) {
                if (h[j] != maxi) {
                    break;
                }
                if (j - i + 1 > maxi) {
                    break;
                }
                vector<int> hh = h;
                for (int k = i; k <= j; k++) {
                    hh[k] -= j - i + 1;
                }
                res = min(res, dfs(hh) + 1);
            }
            
            flag = true;
        }
        return dp[hash] = res;
    }

    int get_hash(const vector<int>& h) {
        llint res = 0;
        for (auto num: h) {
            res = ((res * 17) + num + 1) % MOD;
        }
        return res;
    }
private:
    int n, m;
};

/*
int main() {
    assert(Solution().tilingRectangle(13, 2) == 8);
    assert(Solution().tilingRectangle(2, 1) == 2);
    assert(Solution().tilingRectangle(2, 2) == 1);
    assert(Solution().tilingRectangle(13, 13) == 1);
    assert(Solution().tilingRectangle(2, 3) == 3);
    assert(Solution().tilingRectangle(5, 8) == 5);
    assert(Solution().tilingRectangle(11, 13) == 6);
    return 0;
}
*/
