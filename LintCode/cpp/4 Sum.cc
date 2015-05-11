class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        res.clear();
        int n = nums.size();
        unordered_multimap<int, pair<int, int> > mp;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i - 4 >= 0 && nums[i - 4] == nums[i]) {
                continue;
            }
            for (int j = i + 1 ; j < n; j++) {
                if (j - 4 >= 0 && nums[j - 4] == nums[j]) {
                    continue;
                }
                int a = nums[i];
                int b = nums[j];
                
                auto p = mp.equal_range(target - (a + b));
                
                for (auto iter = p.first; iter != p.second; ++iter) {
                    detect(nums, iter->second, {i, j});
                }
                
                mp.insert({
                    a + b, {i, j}
                });
            }
        }
        vector<vector<int> > res_vec;
        copy(res.begin(), res.end(), back_inserter(res_vec));
        return res_vec;
    }
private:
    void detect(const vector<int>& nums, pair<int, int> pa, pair<int, int> pb) {
        int a = pa.first;
        int b = pa.second;
        int c = pb.first;
        int d = pb.second;
        
        if (a == c || a == d || b == c || b == d) {
            return;
        }
        vector<int> tmp({
            nums[a],
            nums[b],
            nums[c],
            nums[d]
        });
        sort(tmp.begin(), tmp.end());
        res.insert(tmp);
    }
private:
    set<vector<int> > res;
};

