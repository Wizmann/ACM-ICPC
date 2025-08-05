typedef long long llint;

const llint MAX = numeric_limits<int>::max();

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res;
        dfs(S, 0, res);
        return res;
    }
    
    bool dfs(const string& S, int cur, vector<int>& res) {
        if (cur == S.size() && res.size() >= 3) {
            return true;
        }
        
        llint u = 0;
        int m = res.size();
        for (int i = cur; i < S.size(); i++) {
            u = u * 10 + S[i] - '0';
            if (u > MAX) {
                break;
            }
            if (m < 2 || res[m - 1] + res[m - 2] == u) {
                res.push_back(u);
                if (dfs(S, i + 1, res)) {
                    return true;
                }
                res.pop_back();
            }
            if (S[cur] == '0') {
                break;
            }
        }
        return false;
    }
};
