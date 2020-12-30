typedef long long llint;
typedef unsigned long long ullint;
const ullint MUL = 29;
const ullint MOD = 0xdeadbeefLL;

class Solution {
public:
    int longestDecomposition(string text_) {
        text = text_;
        n = text.size();
        dp = vector<vector<int> >(n, vector<int>(n, -1));
        
        return dfs(0, n - 1);
    }
private:
    int dfs(int l, int r) {
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        if (l > r) {
            return 0;
        }
        int m = r - l + 1;
        ullint hl = 0;
        ullint hr = 0;
        int maxi = 1;
        for (int i = 0; l + i < r - i; i++) {
            hl = append_hash(hl, i + 1, text[l + i]);
            hr = prepend_hash(hr, i + 1, text[r - i]);
            if (hl == hr) {
                maxi = max(maxi, 2 + dfs(l + i + 1, r - i - 1));
            }
        }
        return dp[l][r] = maxi;
    }
    
    ullint append_hash(ullint h, int pos, char c) {
        c = c - 'a' + 1;
        h = (h * MUL) % MOD + c;
        return h;
    }
    
    ullint prepend_hash(ullint h, int pos, char c) {
        c = c - 'a' + 1;
        h = (h + mypow(MUL, pos - 1) * c) % MOD;
        return h;
    }
    
    ullint mypow(ullint a, ullint b) {
        ullint res = 1;
        while (b) {
            if (b & 1) {
                res = (res * a) % MOD;
            }
            a = 1ULL * a * a % MOD;
            b >>= 1;
        }
        return res;
    }
private:
    int n;
    string text;
    vector<vector<int> > dp;
};
