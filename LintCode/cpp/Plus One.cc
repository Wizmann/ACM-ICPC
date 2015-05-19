class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        int g = 1;
        for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter) {
            int u = *iter + g;
            *iter = u % 10;
            g = u / 10;
        }
        if (g) {
            vector<int> res = {g};
            copy(digits.begin(), digits.end(), back_inserter(res));
            return res;
        }
        return digits;
    }
};
