class Solution(object):
    def getCommon(self, nums1, nums2):
        common = set(nums1) & set(nums2)
        if not common:
            return -1
        return min(common)
