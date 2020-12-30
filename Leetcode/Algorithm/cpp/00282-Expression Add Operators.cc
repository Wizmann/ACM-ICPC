class Solution {
    typedef long long llint;
    
public:
    vector<string> addOperators(string num, int target) {
        res.clear();
        vector<string> expr;
        dfs(0, 0, num, expr, target);
        return res;
    }
private:
    void dfs(llint pre, llint cur, const string& num, vector<string>& expr, int target) {
        /*
        cout << "(" << num << ")";
        for (auto item: expr) {
            cout << item;
        }
        cout << endl;
        */
        if (num.empty()) {
            pre = pre + cur;
            if (pre != target) {
                return;
            }
            string expr_str;
            for (auto& item: expr) {
                if (item.size() > 1 && item[0] == '0') {
                    return;
                }
                expr_str += item;
            }
            // cout << expr_str << "=" << pre << endl;
            res.push_back(expr_str);
            return;
        }
        int n = num.size();
        if (expr.empty()) {
            pre = 0;
            for (int i = 0; i < n; i++) {
                cur = cur * 10 + (num[i] - '0');
                expr.push_back(num.substr(0, i + 1));
                dfs(0, cur, num.substr(i + 1), expr, target);
                expr.pop_back();
            }
            return;
        }
        
        for (int i = 0; i < n; i++) {
            string left = num.substr(0, i + 1);
            string right = num.substr(i + 1);
            
            llint left_i = strtoll(left.c_str(), NULL, 0);
            
            expr.push_back("+");
            expr.push_back(left);
            dfs(pre + cur, left_i, right, expr, target);
            expr.pop_back();
            expr.pop_back();
            
            expr.push_back("-");
            expr.push_back(left);
            dfs(pre + cur, -left_i, right, expr, target);
            expr.pop_back();
            expr.pop_back();
            
            expr.push_back("*");
            expr.push_back(left);
            dfs(pre, cur * left_i, right, expr, target);
            expr.pop_back();
            expr.pop_back();
        }
    }
private:
    vector<string> res;
};
