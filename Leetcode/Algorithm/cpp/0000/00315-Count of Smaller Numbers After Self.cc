class BiTree {
public:
    BiTree(int n) {
        _tree.resize(n + 1);
    }
    
    void add(int pos, int val) {
        while (pos < _tree.size()) {
            _tree[pos] += val;
            pos += lowbit(pos);
        }
    }
    
    int sum(int pos) {
        int res = 0;
        while (pos > 0) {
            res += _tree[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
    
    int sum(int a, int b) {
        return sum(b) - sum(a - 1);
    }
private:
    inline int lowbit(int x) {
        return x & (-x);
    }
private:
    vector<int> _tree;
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[i] = i;
        }
        sort(pos.begin(), pos.end(),
            [&](const int a, const int b) {
                if (nums[a] != nums[b]) {
                    return nums[a] < nums[b];
                } else {
                    return a < b;
                }
            }
        );
        
        BiTree bitree(n);
        vector<int> res(na
        for (auto p: pos) {
            res[p] = bitree.sum(p + 2, n);
            bitree.add(p + 1, 1);
        }
        return res;
    }
};x
