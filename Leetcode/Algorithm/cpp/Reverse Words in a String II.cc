class Solution {
public:
    void reverseWords(vector<char>& str) {
        int n = str.size();
        if (n == 0) {
            return;
        }
        int pre = 0;
        for (int i = 0; i <= n; i++) {
            if (str[i] == ' ' || i == n) {
                reverse(str.begin() + pre, str.begin() + i);
                pre = i + 1;
            }
        }
        reverse(str.begin(), str.end());
    }
};
