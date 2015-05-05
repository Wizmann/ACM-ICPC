class Solution {
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    public int binarySearch(int[] nums, int target) {
        int n = nums.length;
        int l = 0;
        int r = n - 1;
        
        while (l <= r) {
            int m = (l + r) >> 1;
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return nums[l] == target? l: -1;
    }
}
