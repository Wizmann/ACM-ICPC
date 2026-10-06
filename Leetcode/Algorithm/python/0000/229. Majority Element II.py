import random

class Solution(object):
    def majorityElement(self, nums):
        if not nums:
            return []
            
        n = len(nums)
        a = self.kth_element(nums, n / 3 + 1)
        b = self.kth_element(nums, n / 3 * 2 + 2)
        res = set()
        if a != None and nums.count(a) > n / 3:
            res.add(a)
        if b != None and nums.count(b) > n / 3:
            res.add(b)
        return list(res)
    
    def kth_element(self, nums, k):
        n = len(nums)
        if k > n:
            return None
        pivot_idx = random.randint(0, n - 1)
        nums[0], nums[pivot_idx] = nums[pivot_idx], nums[0]
        pivot = nums[0]
        
        l, r = 0, len(nums) - 1
        flag = True
        while l <= r:
            while l <= r and (nums[l] < pivot
                    or (flag and nums[l] == pivot)):
                flag ^= nums[l] == pivot
                l += 1
            while l <= r and (nums[r] > pivot
                    or (not flag and nums[r] == pivot)):
                flag ^= nums[r] == pivot
                r -= 1
            if l <= r:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                r -= 1
        nums[0], nums[r] = nums[r], nums[0]
        
        if r == k - 1:
            return pivot
        elif r > k - 1:
            return self.kth_element(nums[:r], k)
        else:
            return self.kth_element(nums[r + 1:], k - r - 1)
            
        
