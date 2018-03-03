class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<string, vector<string> > mp;
        for (const auto word: strings) {
            int delta = word[0] - 'a';
            string key = word;
            for (auto& c: key) {
                c = (c - 'a' - delta + 26) % 26 + 'a';
            }
            mp[key].push_back(word);
        }
        
        vector<vector<string> > res;
        for (const auto& p: mp) {
            res.push_back(p.second);
        }
        return res;
    }
};
