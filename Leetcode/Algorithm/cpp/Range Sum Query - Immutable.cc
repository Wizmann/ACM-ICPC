class NumArray {
public:
    NumArray(vector<int> &nums) {
        _n = nums.size();
        _nums = nums;
        for (int i = 1; i < _n; i++) {
            _nums[i] += _nums[i - 1];
        }
    }

    int sumRange(int i, int j) {
        int a = i - 1 >= 0? _nums[i - 1]: 0;
        int b = _nums[j];
        return b - a;
    }
private:
    int _n;
    vector<int> _nums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
