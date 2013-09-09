class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string t;
        dfs(digits, 0, t, res);
        return res;
    }
    
    void dfs(const string& digits, int p, string t, vector<string>& res) {
        if (p == digits.size()) {
            res.push_back(t);
            return;
        }
        
        int now = digits[p] - '0';
        for (int i = 0; i < v[now].size(); i++) {
            dfs(digits, p + 1, t + v[now][i], res);
        }
    }
    
    Solution(){
        v[2] = "abc";
        v[3] = "def";
        v[4] = "ghi";
        v[5] = "jkl";
        v[6] = "mno";
        v[7] = "pqrs";
        v[8] = "tuv";
        v[9] = "wxyz";
    }
    
    string v[10];
};
