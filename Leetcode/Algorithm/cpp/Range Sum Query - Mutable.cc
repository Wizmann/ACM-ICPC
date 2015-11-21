class NumArray {
public:
    NumArray(vector<int> &nums) {
        _n = nums.size();
        _bitree.resize(_n + 1);
        for (int i = 0; i < _n; i++) {
            do_update(i + 1, nums[i]);
        }
    }

    void update(int i, int val) {
        do_update(i + 1, val);
    }
    
    int sumRange(int i, int j) {
        return do_sumRange(i + 1, j + 1);
    }


private:
    void do_update(int i, int val) {
        int u = do_sumRange(i, i);
        int delta = val - u;
        while (i <= _n) {
            _bitree[i] += delta;
            i += lowbit(i);
        }
    }
    
    int do_sumRange(int i, int j) {
        return do_sum(j) - do_sum(i - 1);
    }
    
    int do_sum(int x) {
        int ans = 0;
        while (x > 0) {
            ans += _bitree[x];
            x -= lowbit(x);
        }
        return ans;
    }

    int lowbit(int x) {
        return x & (-x);
    }
private:
    int _n;
    vector<int> _bitree;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
