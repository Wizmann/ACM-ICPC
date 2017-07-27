class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        int n = sentences.size();
        for (int i = 0; i < n; i++) {
            mp[sentences[i]] = times[i];
        }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            if (!buffer.empty()) {
                mp[buffer]++;
                buffer = "";
            }
            return {};
        }
        
        buffer += c;
        vector<pair<int, string> > res;
        auto pa = mp.lower_bound(buffer);
        auto pb = mp.upper_bound(buffer + "~");
        for (auto iter = pa; iter != pb; ++iter) {
            res.push_back({-iter->second, iter->first});
        }
        sort(res.begin(), res.end());
        
        vector<string> ans;
        int cnt = 0;
        for (const auto& item: res) {
            ans.push_back(item.second);
            cnt++;
            if (cnt >= 3) {
                break;
            }
        }
        return ans;
    }
private:
    string buffer;
    map<string, int> mp;
};
