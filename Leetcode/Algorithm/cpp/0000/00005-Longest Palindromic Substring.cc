class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> vec[256];
        int len = s.length();
        for (int i = 0; i < len; i++) {
            int x = int(s[i]);
            vec[x].push_back(i);
        }
        
        int ans = -1;
        pair<int, int> res;
        for (int i = 0; i < 256; i++) {
            int vsize = vec[i].size();
            for (int j = 0; j < vsize; j++) {
                for (int k = j; k < vsize; k++) {
                    if (vec[i][k] - vec[i][j] + 1 <= ans) {
                        continue;
                    }
                    if (is_palin(s, vec[i][j], vec[i][k])) {
                        ans = vec[i][k] - vec[i][j] + 1;
                        res = make_pair(vec[i][j], vec[i][k]);
                    }
                }
            }
        }
        return s.substr(res.first, ans);
    }
    
    bool is_palin(const string& s, int j, int k)
    {
        while(j < k) {
            if (s[j] != s[k]) {
                return false;
            }
            j++; k--;
        }
        return true;
    }
};
