class Solution(object):
    def resultArray(self, nums):
        nums1 = [ nums[0] ]
        nums2 = [ nums[1] ]
        n = len(nums)
        for i in xrange(2, n):
            if nums1[-1] > nums2[-1]:
                nums1.append(nums[i])
            else:
                nums2.append(nums[i])
        return nums1 + nums2
