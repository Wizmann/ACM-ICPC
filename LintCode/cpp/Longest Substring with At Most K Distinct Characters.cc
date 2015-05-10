class Solution {
public:
    /**
     * @param s : A string
     * @return : The length of the longest substring 
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> mp;
        int cnt = 0;
        int ans = 0;
        queue<char> q;
        
        for (auto& c: s) {
            if (mp[c] == 0) {
                cnt++;
            }
            mp[c]++;
            q.push(c);
            
            if (cnt > k) {
                int cc = q.front();
                q.pop();
                mp[cc]--;
                if (mp[cc] == 0) {
                    cnt--;
                }
            }
            
            ans = max(ans, static_cast<int>(q.size()));
        }
        
        return ans;
    }
};
