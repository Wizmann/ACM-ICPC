public class NumArray {

    public NumArray(int[] nums) {
        _nums = nums;
        int n = _nums.length;
        for (int i = 1; i < n; i++) {
            _nums[i] += _nums[i - 1];
        }
    }

    public int sumRange(int i, int j) {
        int a = i - 1 >= 0? _nums[i - 1]: 0;
        int b = _nums[j];
        return b - a;
    }
    
    private int[] _nums;
}


// Your NumArray object will be instantiated and called as such:
// NumArray numArray = new NumArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
