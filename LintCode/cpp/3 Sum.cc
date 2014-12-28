class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        int n = nums.size();
        _res.clear();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            int u = nums[i];
            
            two_sum(nums, i);
        }
        return _res;
    }
private:
    void two_sum(const vector<int>& vec, int st) {
        int n = vec.size();
        int val = vec[st];
        int l = st + 1, r = n - 1;
        while (l < r) {
            int u = vec[l] + vec[r] + val;
            if (u == 0) {
                _res.push_back(vector<int>({val, vec[l], vec[r]}));
            }
            if (u <= 0) {
                do {
                    l++;
                } while (l < r && vec[l] == vec[l - 1]);
            }
            if (u >= 0) {
                do {
                    r--;
                } while (l < r && vec[r] == vec[r + 1]);
            }
        }
    }
private:
    vector<vector<int> > _res;
};

