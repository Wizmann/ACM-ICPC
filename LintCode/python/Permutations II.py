class Solution:
    """
    @param nums: A list of integers.
    @return: A list of unique permutations.
    """
    def permuteUnique(self, nums):
        if not nums:
            return []
        n = len(nums)
        nums.sort()
        res = []
        
        while True:
            res.append(nums[:])
            p = -1
            for i in xrange(n - 2, -1, -1):
                if nums[i] < nums[i + 1]:
                    p = i
                    break
            if p == -1:
                break
            q = -1
            v = 0xdeadbeef
            for i in xrange(p + 1, n):
                if nums[i] > nums[p] and nums[i] <= v:
                    q = i
                    v = nums[i]
            nums[p], nums[q] = nums[q], nums[p]
            nums[p + 1:] = nums[p + 1:][::-1]
            
        return res

