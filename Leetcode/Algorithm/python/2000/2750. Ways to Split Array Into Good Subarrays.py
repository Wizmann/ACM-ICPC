MOD = (10 ** 9) + 7

class Solution(object):
    def numberOfGoodSubarraySplits(self, nums):
        if sum(nums) == 0:
            return 0
        s = '0' + ''.join(map(str, nums)) + '0'
        segs = s.split('1')[1:-1]
        res = 1
        for seg in segs:
            if not seg:
                continue
            res *= len(seg) + 1
            res %= MOD
        return res

