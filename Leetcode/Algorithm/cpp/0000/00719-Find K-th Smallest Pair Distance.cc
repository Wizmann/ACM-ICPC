const int MAXI = 1000000 * 2;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int l = 0;
        int r = MAXI + 12345;
        
        while (l <= r) {
            int m = (0LL + l + r) / 2;
            
            int count = 0;
            for (int i = 0; i < n; i++) {
                auto iter = lower_bound(
                    nums.begin() + i + 1, 
                    nums.end(),
                    m + nums[i]);
                // cout << m << ' ' << nums[i] << ' ' << distance(nums.begin() + i + 1, iter) << endl;
                count += distance(nums.begin() + i + 1, iter);
            }
            cout << m << ' ' << count << endl;
            if (count >= k) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
};
