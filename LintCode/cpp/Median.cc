class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        int n = nums.size();
        return *my_kth_element(nums.begin(), nums.end(), (n + 1) / 2);
    }
    
private:
    vector<int>::iterator my_kth_element(
            vector<int>::iterator st,
            vector<int>::iterator end,
            int k) {
        int pivot = *st;
        
        auto l = st;
        auto r = end - 1;
        
        while (l <= r) {
            while (l <= r && *l <= pivot) {
                l++;
            }
            while (l <= r && *r > pivot) {
                r--;
            }
            if (l <= r) {
                iter_swap(l, r);
                l++;
                r--;
            }
        }
        
        auto pivot_iter = r;
        iter_swap(st, r);
        
        if (distance(st, pivot_iter) == k - 1) {
            return pivot_iter;
        } else if (distance(st, pivot_iter) > k - 1) {
            return my_kth_element(st, pivot_iter, k);
        } else {
            return my_kth_element(pivot_iter + 1, end, k - distance(st, pivot_iter) - 1);
        }
    }
};
