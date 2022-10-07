class Solution(object):
    def xorAllNums(self, nums1, nums2):
        res = 0
        if len(nums1) % 2:
            res ^= reduce(lambda x, y: x ^ y, nums2)
        if len(nums2) % 2:
            res ^= reduce(lambda x, y: x ^ y, nums1)
        return res
            
