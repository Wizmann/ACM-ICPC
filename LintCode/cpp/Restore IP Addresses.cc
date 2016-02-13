class Solution {
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        int n = s.size();
        vector<string> res;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    vector<int> ips = {
                        to_int(s.substr(0, i)),
                        to_int(s.substr(i, j - i)),
                        to_int(s.substr(j, k - j)),
                        to_int(s.substr(k))
                    };
                    
                    bool flag = true;
                    for (auto node: ips) {
                        if (node > 255 || node < 0) {
                            flag = false;
                        }
                    }
                    
                    string tmp;
                    if (flag) {
                        for (int l = 0; l < 4; l++) {
                            if (l) {
                                tmp += '.';
                            }
                            tmp += to_string(ips[l]);
                        }
                        res.push_back(tmp);
                    }
                }
            }
        }
        return res;
    }
private:
    int to_int(const string& str) {
        if (str.empty()) {
            return -1;
        }
        if (str.size() > 1 && str[0] == '0') {
            return -1;
        }
        int res = 0;
        for (auto c: str) {
            res = res * 10 + c - '0';
        }
        return res;
    }
};
