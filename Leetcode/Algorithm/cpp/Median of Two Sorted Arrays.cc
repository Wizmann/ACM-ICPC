class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if ((n1 + n2) % 2 == 1) {
            return do_find_kth(nums1, 0, n1, nums2, 0, n2, (n1 + n2 + 1) / 2);
        } else {
            int a = do_find_kth(nums1, 0, n1, nums2, 0, n2, (n1 + n2) / 2);
            cout << "===" << endl;
            int b = do_find_kth(nums1, 0, n1, nums2, 0, n2, (n1 + n2) / 2 + 1);
            cout << a << ' ' << b << endl;
            return 0.5 * (a + b);
        }
    }
private:
    int do_find_kth(const vector<int>& nums1, int l1, int r1,
                     const vector<int>& nums2, int l2, int r2, int k) {
        if (r1 - l1 > r2 - l2) {
            return do_find_kth(nums2, l2, r2, nums1, l1, r1, k);
        }
        if (l1 == r1) {
            return nums2[l2 + k - 1];
        }
        if (l2 == r2) {
            return nums1[l1 + k - 1];
        }
        if (k == 1) {
            return min(nums1[l1], nums2[l2]);
        }
                         
        int m1 = min(r1 - l1, k / 2);
        int m2 = k - m1;
        
        int a = nums1[l1 + m1 - 1];
        int b = nums2[l2 + m2 - 1];
        cout << a << ' ' << b << endl;
        if (a > b) {
            return do_find_kth(nums1, l1, r1, nums2, l2 + m2, r2, k - m2);
        } else {
            return do_find_kth(nums1, l1 + m1, r1, nums2, l2, r2, k - m1);
        }
    }
};
