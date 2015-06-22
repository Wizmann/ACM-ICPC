class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        if (n == 0) {
            return {0};
        }
        if (n == 1) {
            return {0, 1};
        }
        vector<int> res = {0, 1, 3, 2};
        
        for (int i = 3; i <= n; i++) {
            int num = (1 << i) / 2;
            for (int j = num - 1; j >= 0; j--) {
                res.push_back((1 << (i - 1)) | res[j]);
            }
        }
        return res;
    }
};
