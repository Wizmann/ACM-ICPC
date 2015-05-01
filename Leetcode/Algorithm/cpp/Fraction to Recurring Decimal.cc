class Solution {
private:
    typedef long long llint;
public:
    string fractionToDecimal(llint numerator, llint denominator) {
        int sig = 1;
        if ((numerator < 0) ^ (denominator < 0)) {
            sig = -1;
        }
        numerator   = abs(numerator);
        denominator = abs(denominator);
        
        string int_part  = to_string(numerator / denominator);
        string frac_part = calc_frac(numerator, denominator);
        if (int_part == "0" && frac_part.empty()) {
            return "0";
        }
        return (sig == 1? "": "-") + int_part + (frac_part.empty()? "": "." + frac_part);
    }

private:
    string calc_frac(llint a, llint b) {
        unordered_map<llint, int> mp;
        vector<llint> res_vec;
        int idx = 0;
        
        a = (a % b) * 10;
        while (a) {
            if (mp.find(a) != mp.end()) {
                return loop_frac_str(res_vec, mp[a]);
            }
            mp[a] = idx;
            res_vec.push_back(a / b);
            idx++;
            a = (a % b) * 10;
        }
        return ord_frac_str(res_vec);
    }
    string loop_frac_str(const vector<llint>& vec, int idx) {
        string res = "";
        int n = vec.size();
        for (int i = 0; i < idx; i++) {
            res += to_string(vec[i]);
        }
        res += "(";
        for (int i = idx; i < n; i++) {
            res += to_string(vec[i]);
        }
        res += ")";
        return res;
    }
    string ord_frac_str(const vector<llint>& vec) {
        string res = "";
        for (auto i: vec) {
            res += to_string(i);
        }
        return res;
    }
};
