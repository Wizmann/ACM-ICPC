class Solution(object):
    def minOperations(self, nums1, nums2, k):
        if k == 0:
            return 0 if nums1 == nums2 else -1
        n = len(nums1)
        inc, dec = 0, 0
        for i in xrange(n):
            delta = abs(nums1[i] - nums2[i])
            if delta % k:
                return -1
            if nums1[i] > nums2[i]:
                dec += delta / k
            else:
                inc += delta / k
        if inc == dec:
            return inc
        return -1
