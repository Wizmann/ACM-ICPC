class Solution {
public:
    string countAndSay(int n) {
        vector<int> res;
        res.push_back(1);
        res.push_back(-1);
        for (int i = 0; i < n -1; i++) {
            int val = res[0];
            int num = 0;
            vector<int> next;
            for (int j = 0; j < res.size(); j++) {
                if (res[j] != val) {
                    next.push_back(num);
                    next.push_back(val);
                    val = res[j];
                    num = 1;
                } else {
                    num++;
                }
            }
            next.push_back(-1);
            res = next;
        }
        int sz = res.size() - 1;
        string res_str = "";
        for (int i = 0; i < sz; i++) {
            res_str += '0' + res[i];
        }
        return res_str;
    }
};
