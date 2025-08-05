class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        
        do {
            res.push_back(nums);
        } while (my_next_permutation(nums.begin(), nums.end()));
        
        return res;
    }
private:
    bool my_next_permutation(vector<int>::iterator begin, vector<int>::iterator end) {
        auto iter = end - 2;
        while (iter >= begin) {
            int a = *iter;
            int b = *(iter + 1);
            
            if (a < b) {
                auto p = find_minimal_gt(iter + 1, end, a);
                iter_swap(iter, p);
                reverse(iter + 1, end);
                return true;
            }
            --iter;
        }
        reverse(begin, end);
        return false;
    }
    
    vector<int>::iterator find_minimal_gt(vector<int>::iterator begin, vector<int>::iterator end, int value) {
        for (auto iter = end - 1; iter != begin; --iter) {
            if (*iter > value) {
                return iter;
            }
        }
        return begin;
    }
};
