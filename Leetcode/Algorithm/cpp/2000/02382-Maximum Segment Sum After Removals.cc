typedef long long llint;

struct Segment {
    int st, end;
    llint value;
};

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums_, vector<int>& removeQueries) {
        multiset<llint> st;
        map<int, Segment> mp;
        
        vector<llint> nums;
        for (auto num : nums_) {
            nums.push_back(num);
        }
        
        const int n = nums.size();
        
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
        
        st.insert(0);
        st.insert(nums[n - 1]);
        mp[n - 1] = {0, n - 1, nums[n - 1]};
        
        auto presum = [&](int a, int b) -> llint {
            assert(b < n);
            assert(a - 1 < n);
            return nums[b] - (a - 1 < 0 ? 0 : nums[a - 1]);
        };
        
        vector<llint> res;
        for (auto q : removeQueries) {
            auto iter = mp.lower_bound(q);
            assert(iter != mp.end());
            
            const auto seg = iter->second;
            mp.erase(iter);
            
            llint tot = seg.value;
            st.erase(st.find(tot));
            
            if (seg.st <= q - 1) {
                llint a = presum(seg.st, q - 1);
                st.insert(a);
                mp[q - 1] = {seg.st, q - 1, a};
            }

            if (q + 1 <= seg.end) {
                llint b = presum(q + 1, seg.end);
                st.insert(b);
                mp[seg.end] = {q + 1, seg.end, b};
            }
            
            res.push_back(*st.rbegin());
            // cout << *st.rbegin() << endl;
        }
        return res;
    }
};
