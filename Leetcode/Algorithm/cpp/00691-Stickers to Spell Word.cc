const int INF = 0x3f3f3f3f;

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        sort(target.begin(), target.end());
        for (auto& sticker: stickers) {
            sort(sticker.begin(), sticker.end());
        }
        
        int n = target.size();
        vector<int> dp(1 << n, INF);
        dp[0] = 0;
        
        for (int i = 0; i < 1 << n; i++) {
            if (dp[i] == INF) {
                continue;
            }
            for (const auto& sticker: stickers) {
                int j = merge(i, sticker, target);
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }
        return dp[(1 << n) - 1] == INF? -1: dp[(1 << n) - 1];
    }
private:
    int merge(int mask, const string& s, const string& target) {
        int p = 0;
        int q = 0;
        int res = mask;
        while (p < s.size() && q < target.size()) {
            while (q < target.size() && ((1 << q) & mask)) {
                q++;
            }
            if (s[p] < target[q]) {
                p++;
            } else if (s[p] > target[q]) {
                q++;
            } else {
                res |= (1 << q);
                p++;
                q++;
            }
        }
        return res;
    }
};
