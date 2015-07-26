class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return *nums.begin();
        }
        int a = do_rob(nums, 0, n - 2);
        int b = do_rob(nums, 1, n - 1);
        return max(a, b);
    }
private:
    int do_rob(vector<int>& nums, int st, int end) {
        int a = 0;
        int b = 0;
        
        for (int i = st; i <= end; i++) {
            int c = nums[i];
            int aa = max(a, b + c);
            int bb = max(b, a);
            
            swap(a, aa);
            swap(b, bb);
        }
        return max(a, b);
    }
};
