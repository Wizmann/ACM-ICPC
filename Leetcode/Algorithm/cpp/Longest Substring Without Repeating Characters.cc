class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool hash[256] = {0};
        int p = 0;
        int n = s.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            int c = static_cast<int>(s[i]);
            while (hash[c]) {
                int cc = static_cast<int>(s[p]);
                hash[cc] = false;
                p++;
            }
            hash[c] = true;
            ans = max(ans, i - p + 1);
        }
        return ans;
    }
};
