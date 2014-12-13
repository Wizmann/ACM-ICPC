class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        int n = nums.size();
        return kth_element(nums, 0, n, (n + 1) / 2);
    }
private:
    int kth_element(vector<int>& nums, int st, int end, int k) {
        int pivot_idx = partition(nums, st, end);
        if (pivot_idx - st + 1 == k) {
            return nums[pivot_idx];
        }
        if (pivot_idx - st >= k) {
            return kth_element(nums, st, pivot_idx, k);
        } else {
            return kth_element(nums, pivot_idx + 1, end, k - (pivot_idx - st) - 1);
        }
    }
    
    int partition(vector<int>& nums, int st, int end) {
        int l = st, r = end - 1;
        int pivot = nums[st];
        while (l <= r) {
            while (l <= r && nums[l] <= pivot) {
                l++;
            }
            while (l <= r && nums[r] > pivot) {
                r--;
            }
            if (l <= r) {
                swap(nums[l++], nums[r--]);
            }
        }
        swap(nums[st], nums[r]);
        return r;
    }
};

