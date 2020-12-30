class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        int maxi = 0;
        
        for (auto& word: d) {
            int p = 0;
            int q = 0;
            
            if (word.size() < maxi) {
                continue;
            }
            
            while (p < s.size() && q < word.size()) {
                if (word[q] != s[p]) {
                    p++;
                } else {
                    p++;
                    q++;
                }
            }
            
            if (q == word.size()) {
                if (word.size() > maxi) {
                    maxi = word.size();
                    res = word;
                } else if (word.size() == maxi) {
                    res = min(res, word);
                }
            }
        }
        return res;
    }
};
