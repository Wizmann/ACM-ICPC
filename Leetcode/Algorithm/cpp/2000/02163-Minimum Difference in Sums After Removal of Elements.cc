typedef long long llint;

class Solution {
public:
    llint minimumDifference(vector<int>& nums) {
        llint left = 0;
        llint right = 0;
        
        multiset<int> st1, st2, st3;
        
        int n = nums.size() / 3;
        assert(n * 3 == nums.size());
        for (int i = 0; i < n; i++) {
            st1.insert(nums[i]);
            left += nums[i];
        }
        
        for (int i = n; i < n * 3; i++) {
            st3.insert(nums[i]);
            right += nums[i];
        }
        
        for (int i = 0; i < n; i++) {
            st2.insert(*st3.begin());
            right -= *st3.begin();
            st3.erase(st3.begin());
        }
        
        assert(st2.size() == n && st3.size() == n);
        
        llint res = left - right;

        for (int i = n; i < n * 2; i++) {
            int u = nums[i];
            left += u;
            auto iter1 = --st1.end();
            left -= *iter1;
            if (u != *iter1) {
                st1.insert(u);
                st1.erase(iter1);
            }
            assert(st1.size() == n);
            
            if (st2.find(u) != st2.end()) {
                st2.erase(st2.find(u));
            } else {
                assert(st3.find(u) != st3.end());
                right -= u;
                auto iter2 = --st2.end();
                right += *iter2;
                if (u != *iter2) {
                    st3.erase(st3.find(u));
                    st3.insert(*iter2);
                }
                st2.erase(iter2);
                assert(st3.size() == n);
            }
            
            res = min(res, left - right);
        }
        return res;
    }
};
