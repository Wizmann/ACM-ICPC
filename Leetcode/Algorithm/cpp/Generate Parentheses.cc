class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        vector<char> s;
        solve(0, 0, n * 2, s, res);
        return res;
    }
    
    void solve(int l, int r, int n, vector<char>& s, vector<string>& res)
    {
        if (l + r == n) {
            string t;
            for (int i = 0; i < s.size(); i++) {
                t += s[i];
            }
            res.push_back(t);
        }
        
        if (l <  n / 2) {
            s.push_back('(');
            solve(l + 1, r, n, s, res);
            s.pop_back();
        }
        
        if (r + 1 <= l) {
            s.push_back(')');
            solve(l, r + 1, n, s, res);
            s.pop_back();
        }
    }            
};
