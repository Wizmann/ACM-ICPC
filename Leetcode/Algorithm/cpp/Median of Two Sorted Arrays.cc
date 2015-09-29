class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        if (n + m == 0) {
            return 0.0;
        }
        
        if ((n + m) % 2 == 0) {
            double a = do_find_kth(
                nums1.begin(), nums1.end(),
                nums2.begin(), nums2.end(),
                (n + m) / 2);
            double b = do_find_kth(
                nums1.begin(), nums1.end(),
                nums2.begin(), nums2.end(),
                (n + m) / 2 + 1);
            return (a + b) / 2;
        } else {
            return do_find_kth(
                nums1.begin(), nums1.end(),
                nums2.begin(), nums2.end(),
                (n + m) / 2 + 1);
        }
    }
private:
    int do_find_kth(
            vector<int>::iterator nums1_begin, vector<int>::iterator nums1_end,
            vector<int>::iterator nums2_begin, vector<int>::iterator nums2_end,
            int k) {
        int n = distance(nums1_begin, nums1_end);
        int m = distance(nums2_begin, nums2_end);
        if (n < m) {
            return do_find_kth(nums2_begin, nums2_end, nums1_begin, nums1_end, k);
        }
        
        if (nums2_begin == nums2_end) {
            return *(nums1_begin + k - 1);
        }
        
        if (k == 1) {
            return min(*nums1_begin, *nums2_begin);
        }
        
        int idx_2 = min(k / 2, m);
        int idx_1 = k - idx_2;
        
        int u = *(nums1_begin + idx_1 - 1);
        int v = *(nums2_begin + idx_2 - 1);
        
        if (u < v) {
            return do_find_kth(nums1_begin + idx_1, nums1_end, nums2_begin, nums2_end, k - idx_1);
        } else if (u > v) {
            return do_find_kth(nums1_begin, nums1_end, nums2_begin + idx_2, nums2_end, k - idx_2);
        } else {
            return u;
        }
    }
};
