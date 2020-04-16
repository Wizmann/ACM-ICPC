class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int n) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }
        vector<int> res;
        for (auto q : queries) {
            auto iter = find(nums.begin(), nums.end(), q);
            assert(iter != nums.end());
            res.push_back(distance(nums.begin(), iter));
            nums.erase(iter);
            nums.insert(nums.begin(), q);
        }
        return res;
    }
};
