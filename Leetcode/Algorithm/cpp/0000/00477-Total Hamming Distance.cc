class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int a = 0;
            int b = 0;
            for (auto num: nums) {
                int c = (num & (1 << i))? 1: 0;
                a += (c == 0);
                b += (c == 1);
            }
            ans += a * b;
        }
        return ans;
    }
};
