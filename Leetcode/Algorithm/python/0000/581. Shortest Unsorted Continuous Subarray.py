class Solution(object):
    def findUnsortedSubarray(self, nums):
        n = len(nums)
        sn = sorted(nums)
        
        l, r = 0, n - 1
        while l <= r:
            if nums[l] == sn[l]:
                l += 1
            else:
                break
            
        while l <= r:
            if nums[r] == sn[r]:
                r -= 1
            else:
                break
            
        return r - l + 1
        
