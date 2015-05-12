class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        my_next_permutation(nums.begin(), nums.end());
        return nums;
    }
private:
    template <typename iter>
    void my_next_permutation(iter st, iter end) {
        iter l = st;
        iter r = end - 1;
        
        for (auto it = r; it > l; it--) {
            auto prev = it - 1;
            
            if (*prev < *it) {
                auto it_ = find_max(it, end, *prev);
                iter_swap(prev, it_);
                reverse(it, end);
                return;
            }
        }
        reverse(st, end);
    }
    
    template <typename iter>
    iter find_max(iter st, iter end, int pivot) {
        iter res_it = end;
        int mini = INF;
        
        for (iter it = end - 1; it >= st; --it) {
            if (*it > pivot && *it < mini) {
                res_it = it;
                mini = *it;
            }
        }
        return res_it;
    }
    
    static const int INF = 0x3f3f3f3f;
};
