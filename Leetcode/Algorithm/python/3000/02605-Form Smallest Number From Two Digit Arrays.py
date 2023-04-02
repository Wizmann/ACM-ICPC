class Solution(object):
    def minNumber(self, nums1, nums2):
        if set(nums1) & set(nums2):
            return min(set(nums1) & set(nums2))
        a = min(nums1) * 10 + min(nums2)
        b = min(nums2) * 10 + min(nums1)
        return min(a, b)
