class Solution(object):
    def minOrAfterOperations(self, nums, k):
        res = 0
        mask = 0
        for i in xrange(32, -1, -1):
            print i
            mask |= 1 << i
            if not self.check(nums, k, res, mask):
                res |= 1 << i
        # print res
        return res

    def check(self, nums, k, nxt, mask):
        nxt = ~nxt
        pre = nums[0] & mask
        for num in nums[1:]:
            num &= mask
            if pre & nxt:
                pre &= num
                k -= 1
            else:
                pre = num
        # print '{:016b}'.format(pre), '{:016b}'.format(nxt)
        # print pre & nxt, k
        if pre & nxt:
            k -= 1
        return k >= 0


assert Solution().minOrAfterOperations([39,62,35,11,28,32], 3) == 38
assert Solution().minOrAfterOperations([3,5,3,2,7], 2) == 3
assert Solution().minOrAfterOperations([4, 4, 0, 0, 4, 0], 3) == 0
