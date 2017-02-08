class Solution {
    typedef long long llint;
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (m > n) {
            return 0;
        }
        
        llint l = accumulate(nums.begin(), nums.end(), 0, [](int a, int b) {
            return max(a, b);
        });
        llint r = 1LL * n * numeric_limits<int>::max();
        
        while (l <= r) {
            llint mid = (l + r) >> 1;
            if (_split(nums, n, mid) > m) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
private:
    int _split(vector<int>& nums, int n, llint k) {
        int cnt = 1;
        llint sum = 0;
        for (int i = 0; i < n; i++) {
            int cur = nums[i];
            sum += cur;
            if (sum > k) {
                cnt++;
                sum = cur;
            }
        }
        return cnt;
    }
};
