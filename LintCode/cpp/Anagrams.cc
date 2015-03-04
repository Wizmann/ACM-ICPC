class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ans;
        unordered_map<string, vector<string> > mp;
        for (auto& str: strs) {
            auto ordered_str = str;
            sort(ordered_str.begin(), ordered_str.end());
            if (mp.find(ordered_str) == mp.end()) {
                mp[ordered_str] = vector<string>();
            }
            mp[ordered_str].push_back(str);
        }
        
        for (auto& p: mp) {
            auto& key = p.first;
            auto& vec = p.second;
            
            if (vec.size() < 2) {
                continue;
            }
            
            copy(vec.begin(), vec.end(), back_inserter(ans));
        }
        return ans;
    }
};

