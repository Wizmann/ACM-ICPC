class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        vector<string> tmp;
        words.push_back("#");
        int tot = 0;
        for (auto iter = words.begin(); iter != words.end(); /* pass */) {
            if (*iter != "#" && tot + iter->length() + tmp.size() <= L) {
                tmp.push_back(*iter);
                tot += iter -> length();
                ++iter;
            } else {
                int cnt = tmp.size();
                int space = L - tot;
                string s = *(--tmp.end());
                for (int i = tmp.size() - 2; i >= 0; i--) {
                    s = tmp[i] + (*iter == "#"? " " : gen_space(space / (i + 1))) + s;
                    space -= space / (i + 1);
                }
                if (s.length() < L) {
                    s += gen_space(L - s.length());
                }
                res.push_back(s);
                tmp = vector<string>();
                tot = 0;
                
                if (*iter == "#") break;
            }
        }
        return res;
    }
    
    string gen_space(int x) {
        string res = "";
        for (int i = 0; i < x; i++) {
            res += " ";
        }
        return res;
    }
};
