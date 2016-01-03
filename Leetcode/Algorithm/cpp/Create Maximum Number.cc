class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        vector<int> ans = {};
        
        for (int i = 0; i <= min(k, n1); i++) {
            int m1 = i;
            int m2 = k - m1;
            
            if (m2 > n2) {
                continue;
            }
            
            vector<int> r1 = get_k(nums1, m1);
            vector<int> r2 = get_k(nums2, m2);
            
            vector<int> r3 = merge(r1, r2);
            if (compare1(r3, ans) > 0) {
                ans = r3;
            }
        }
        return ans;
    }
private:
    vector<int> get_k(const vector<int>& nums, int k) {
        vector<int> st;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] > *st.rbegin() && st.size() + n - i > k) {
                st.pop_back();
            }
            if (st.size() < k) {
                st.push_back(nums[i]);
            }
        }
        return st;
    }
    
    vector<int> merge(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> res;
        auto iter1 = nums1.begin();
        auto iter2 = nums2.begin();
        
        while (iter1 != nums1.end() || iter2 != nums2.end()) {
            if (compare2(iter1, nums1.end(), iter2, nums2.end()) == 1) {
                res.push_back(*iter1);
                ++iter1;
            } else {
                res.push_back(*iter2);
                ++iter2;
            }
        }
        return res;
    }
    
    int compare1(const vector<int>& nums1, const vector<int>& nums2) {
        if (nums1.size() != nums2.size()) {
            return nums1.size() > nums2.size()? 1: -1;
        }
        auto iter1 = nums1.begin();
        auto iter2 = nums2.begin();
        
        while (iter1 != nums1.end() && iter2 != nums2.end()) {
            if (*iter1 > *iter2) {
                return 1;
            } else if (*iter1 < *iter2) {
                return -1;
            }
            ++iter1;
            ++iter2;
        }
        return 0;
    }
    
    int compare2(
            vector<int>::const_iterator begin1, 
            vector<int>::const_iterator end1,
            vector<int>::const_iterator begin2,
            vector<int>::const_iterator end2) {
        while (begin1 != end1 && begin2 != end2) {
            if (*begin1 == *begin2) {
                begin1++;
                begin2++;
            } else {
                break;
            }
        }
        if (begin1 == end1) {
            return -1;
        }
        if (begin2 == end2) {
            return 1;
        }
        
        return *begin1 > *begin2? 1: -1;
    }
};
