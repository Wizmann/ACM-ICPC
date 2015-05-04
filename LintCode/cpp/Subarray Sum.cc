class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        unordered_map<int, int> mp;
        int n = nums.size();
        int sum = 0;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (mp.find(sum) != mp.end()) {
                return {mp[sum] + 1, i};
            }
            mp[sum] = i;
        }
        return {};
    }
};
