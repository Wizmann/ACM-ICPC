class Solution(object):
    def minDeletions(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        pre = 10 ** 123
        cnt = 0
        for num in nums:
            if num == pre:
                cnt += 1
            pre = num
        return cnt
