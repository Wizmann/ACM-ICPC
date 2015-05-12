class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        string res;
        int n = strs.size();
        if (n == 0) {
            return "";
        }
        if (n == 1) {
            return strs[0];
        }
        int ptr = 0;
        while (true) {
            bool flag = true;
            if (ptr >= strs[0].size()) {
                break;
            }
            for (int i = 1; i < n; i++) {
                if (ptr >= strs[i].size()) {
                    flag = false;
                    break;
                }
                if (strs[i][ptr] != strs[i - 1][ptr]) {
                    flag = false;
                }
            }
            if (!flag) {
                break;
            }
            res += strs[0][ptr];
            ptr++;
        }
        return res;
    }
};
