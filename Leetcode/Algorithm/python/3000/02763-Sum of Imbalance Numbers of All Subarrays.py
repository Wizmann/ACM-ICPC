from collections import defaultdict

class Solution(object):
    def sumImbalanceNumbers(self, nums):
        n = len(nums)
        tot = 0
        for i in xrange(n):
            d = defaultdict(int)
            res = 0
            for j in xrange(i, n):
                cur = nums[j]
                d[cur] += 1
                if d[cur] == 1:
                    res += 1 if d[cur - 1] == 0 else -1
                    res += 1 if d[cur + 1] == 0 else -1
                tot += (res - 2) / 2
        return tot

'''
^^^^TEST^^^^
[2,3,1,4]
----------------
3
$$$$TEST$$$$

^^^^TEST^^^^
[1,3,3,3,5]
----------------
8
$$$$TEST$$$$

'''


