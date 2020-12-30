class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        map<char, int> mp;
        int ans = 0;
        for (int i = 0, j = 0; i < n && j <= n; /* pass */) {
            while (j - i > 0 && !canAdd(mp, j - i, k)) {
                char c = s[i];
                mp[c]--;
                i++;
            }
            ans = max(ans, j - i);
            char c = s[j];
            mp[c]++;
            j++;
        }
        return ans;
    }
private:
    bool canAdd(const map<char, int>& mp, int len, int k) {
        int maxi = 0;
        for (auto p: mp) {
            maxi = max(maxi, p.second);
        }
        return maxi + k >= len;
    }
};
