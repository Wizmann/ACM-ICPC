class Solution(object):
    def wiggleSort(self, nums):
        n = len(nums)
        flag = 1
        for i in xrange(1, n):
            if flag and nums[i - 1] > nums[i]:
                nums[i - 1], nums[i] = nums[i], nums[i - 1]
            if not flag and nums[i - 1] < nums[i]:
                nums[i - 1], nums[i] = nums[i], nums[i - 1]
            
            flag ^= 1
        
