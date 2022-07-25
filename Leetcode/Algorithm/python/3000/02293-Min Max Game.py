class Solution(object):
    def minMaxGame(self, nums):
        if len(nums) == 1:
            return nums[0]
        nxt = []
        n = len(nums)
        assert (n & (n - 1)) == 0
        flag = 0
        for i in xrange(0, n, 2):
            a, b = nums[i], nums[i + 1]
            nxt.append(min(a, b) if flag == 0 else max(a, b))
            flag ^= 1
        return self.minMaxGame(nxt)
