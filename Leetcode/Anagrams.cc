class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string> > idx;
        for (int i = 0; i < strs.size(); i++) {
            string _str = strs[i];
            sort(_str.begin(), _str.end());
            if (idx.find(_str) == idx.end()) {
                idx[_str] = vector<string>();
            }
            idx[_str].push_back(strs[i]);
        }
        vector<string> res;
        for (map<string, vector<string> >::iterator iter = idx.begin();
                iter != idx.end();
                iter++) {
            if (iter->second.size() == 1) {
                continue;
            } else {
                for (int i = 0; i < iter->second.size(); i++) {
                    res.push_back(iter->second[i]);
                }
            }
        }
        return res;
    }
};
