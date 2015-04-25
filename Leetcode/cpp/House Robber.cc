class Solution {
public:
    int rob(vector<int>& nums) {
        int A = 0; // (x - 1)th house is robbed
        int B = 0; // (x - 1)th house is not robbed
        for (auto i: nums) {
            int tmp = B;
            B = max(A, B);
            A = tmp + i;
        }
        return max(A, B);
    }
};
