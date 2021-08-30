import random

class Solution(object):
    def kthLargestNumber(self, nums, k):
        nums = map(int, nums)
        random.shuffle(nums)
        n = len(nums)
        return str(self.do_kthLargestNumber(nums, n - k))
    
    def do_kthLargestNumber(self, nums, k): 
        ll = filter(lambda x: x < nums[0], nums[1:])
        rr = filter(lambda x: x > nums[0], nums[1:])

        pl, pr = len(ll), len(nums) - len(rr) - 1
        if pl <= k <= pr:
            return nums[0]
        elif pr < k:
            return self.do_kthLargestNumber(rr, k - pr - 1)
        else:
            return self.do_kthLargestNumber(ll, k)
        
        
