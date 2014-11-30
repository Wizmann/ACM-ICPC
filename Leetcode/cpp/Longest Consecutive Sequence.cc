class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> mp;
        copy(num.begin(), num.end(), inserter(mp, mp.end()));
        int ans = 0;
        for (auto i: num) {
            if (mp.find(i) == mp.end()) {
                continue;
            }
            int cnt = 0, now = i;
            while (mp.find(now) != mp.end()) {
                mp.erase(mp.find(now));
                now--;
                cnt++;
            }
            now = i + 1;
            while (mp.find(now) != mp.end()) {
                mp.erase(mp.find(now));
                now++;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
