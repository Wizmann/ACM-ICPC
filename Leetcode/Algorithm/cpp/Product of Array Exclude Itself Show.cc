class Solution {
    typedef long long llint;
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        int n = nums.size();
        vector<llint> res(n, 1);
        for (llint i = 0, a = 1; i < n; i++) {
            res[i] *= a;
            a *= nums[i];
        }
        for (llint i = n - 1, a = 1; i >= 0; i--) {
            res[i] *= a;
            a *= nums[i];
        }
        return res;
    }
};
