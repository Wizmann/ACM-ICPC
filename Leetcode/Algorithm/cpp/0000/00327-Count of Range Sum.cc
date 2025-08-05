typedef long long llint;

class BiTree {
public:
    BiTree(int n): _n(n + 1), _tree(n + 1, 0) {}
    
    void add(int pos, int val) {
        while (pos < _n) {
            _tree[pos] += val;
            pos += lowbit(pos);
        }
    }
    
    int sum(int pos) {
        int res = 0;
        while (pos) {
            res += _tree[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
    
    int sum(int a, int b) {
        return sum(b) - sum(a - 1);
    }
private:
    int lowbit(int x) {
        return x & (-x);
    }
private:
    int _n;
    vector<int> _tree;
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        
        map<llint, int> mp;
        
        mp.insert({0, -1});
        llint sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            mp.insert({sum - lower, -1});
            mp.insert({sum - upper, -1});
            mp.insert({sum, -1});
        }
        
        int idx = 1;
        for (auto& p: mp) {
            p.second = idx++;
        }
        BiTree bitree(idx);
        int ans = 0;
        
        bitree.add(mp[0], 1);
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            
            llint a = sum - upper;
            llint b = sum - lower;
            
            ans += bitree.sum(mp[a], mp[b]);
            bitree.add(mp[sum], 1);
        }
        return ans;
    }
};
