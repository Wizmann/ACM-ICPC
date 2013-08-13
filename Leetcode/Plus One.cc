class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int sz = digits.size();
        int g = 1;
        vector<int> res;
        for (int i = sz - 1; i >= 0; i--) {
            digits[i] += g;
            g /= 10;
            if (digits[i] >= 10) {
                g = digits[i] / 10;
                digits[i] = digits[i] % 10;
            }
            res.push_back(digits[i]);
        }
        if (g) {
            res.push_back(g);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
