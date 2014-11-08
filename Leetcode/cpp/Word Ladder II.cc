class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        _start = start;
        _end = end;
        unordered_set<string> us[2];
        _prevG.clear();
        _path = vector<vector<string> >();
        us[0].insert(start);
        int cur = 0;
        while (true) {
            int pre = cur ^ 1;
            for (auto iter = us[cur].begin(); iter != us[cur].end(); ++iter) {
                dict.erase(*iter);
            }
            us[pre].clear();
            for (auto iter = us[cur].begin(); iter != us[cur].end(); ++iter) {
                for (int i = 0; i < (int)iter -> length(); i++) {
                    string str = *iter;
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (str[i] == c) {
                            continue;
                        }
                        str[i] = c;
                        if (dict.find(str) != dict.end()) {
                            us[pre].insert(str);
                            _prevG[str].push_back(*iter);
                        }
                    }
                }
            }
            if (us[pre].empty() || us[pre].find(end) != us[pre].end()) {
                break;
            }
            cur = pre;
        }
        vector<string> tmp;
        tmp.push_back(end);
        make_path(tmp);
        for (auto iter = _path.begin(); iter != _path.end(); ++iter) {
            reverse(iter -> begin(), iter -> end());
        }
        return _path;
    }
private:
    void make_path(vector<string> &tmp)
    {
        if (*(--tmp.end()) == _start) {
            _path.push_back(tmp);
            return;
        }
        string now = *(--tmp.end());
        
        for (auto iter = _prevG[now].begin(); iter != _prevG[now].end(); ++iter) {
            tmp.push_back(*iter);
            make_path(tmp);
            tmp.pop_back();
        }
    }
private:
    string _start, _end;
    vector<vector<string> > _path;
    unordered_map<string, vector<string> > _prevG;
};
