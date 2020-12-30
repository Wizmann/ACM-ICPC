class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        map<char, int> cnt;
        const int n = s.size();
        int l = 0;
        int r = 0;
        int res = 0;
        while (l < n && r < n) {
            while (r < n && cnt.size() <= 2) {
                cnt[s[r]]++;
                if (cnt.size() <= 2) {
                    res = max(res, r - l + 1);
                }
                r++;
            }
            while (l < r && cnt.size() > 2) {
                cnt[s[l]]--;
                if (cnt[s[l]] == 0) {
                    cnt.erase(cnt.find(s[l]));
                }
                l++;
            }
        }
        return res;
    }
};
