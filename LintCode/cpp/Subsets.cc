class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
    	res.clear();
    	
    	vector<int> tmp;
    	dfs(nums, 0, tmp);
    	return res;
    }
private:
    void dfs(const vector<int>& nums, int ptr, vector<int>& tmp) {
        if (ptr == nums.size()) {
            res.push_back(tmp);
            return;
        }
        
        tmp.push_back(nums[ptr]);
        dfs(nums, ptr + 1, tmp);
        tmp.pop_back();
        
        dfs(nums, ptr + 1, tmp);
    }
private:
    vector<vector<int> > res;
};
