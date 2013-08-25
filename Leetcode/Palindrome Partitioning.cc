const int SIZE = 1024;
static int isP[SIZE][SIZE];
class Solution {
public:
    vector<vector<string> > partition(string s)
    {
        memset(isP, 0 ,sizeof(isP));
        int len = s.size();
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                if (s[i] == s[j] && (j - i < 2 || isP[i + 1][j - 1])) {
                    isP[i][j] = 1;
                }
            }
        }

        vector<string> _tmp;
        vector<vector<string> > ans;
        dfs(0, len, s, ans, _tmp);
        return ans;
    }

    void dfs(int p, int len, const string& s, vector<vector<string> >& ans, vector<string>& tmp)
    {
        if (p == len) {
            ans.push_back(tmp);
        }
        for (int i = p; i < len; i++) {
            if (isP[p][i]) {
                tmp.push_back(s.substr(p, i+1-p));
                dfs(i+1, len, s, ans, tmp);
                tmp.pop_back();
            }
        }
    }
};
