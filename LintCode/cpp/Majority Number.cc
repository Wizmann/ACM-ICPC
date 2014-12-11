/* Test Case
1) 1
2) 1 1
3) 1 1 1 2
4) 1 1 1 2 2

*/


class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // assert(nums.size() >= 1)
        int n = nums.size();
        return kth_element(nums, 0, n, (n + 1) / 2);
    }
private:
    int kth_element(vector<int>& nums, int st, int end, int k) {
        if (nums.empty()) {
            // avoid core dump
            // FATAL LOG here
            return -1;
        }

        
        int l = st, r = end - 1;
        int pivot = nums[l];
        swap(nums[l], nums[r]);
        r--;
        while (l < r) {
            while (l < r && nums[l] < pivot) {
                l++;
            }
            while (l < r && nums[r] >= pivot) {
                r--;
            }
            if (l < r) {
                swap(nums[l], nums[r]);
            }
        }
        
        int left_len  = l - st;
        int right_len = end - st - 1 - left_len;
        if (left_len == k - 1) {
            return pivot;
        }
        if (left_len >= k) {
            return kth_element(nums, st, l, k);
        } else {
            return kth_element(nums, r + 1, end, k - left_len - 1);
        }
        

    }
};

