class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1:
            return sum(nums)
        
        return max(
            self.do_rob(nums[1:]),
            self.do_rob(nums[:-1])
        )
    def do_rob(self, nums):
        A, B = 0, 0
        for num in nums:
            _A = num + B
            _B = max(A, B)
            
            A, B = _A, _B
        return max(A, B)
