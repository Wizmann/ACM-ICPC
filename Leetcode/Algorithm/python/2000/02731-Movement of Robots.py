MOD = (10 ** 9) + 7

class Solution(object):
    def sumDistance(self, nums, s, d):
        n = len(nums)
        ps = []
        for i, num in enumerate(nums):
            if s[i] == 'R':
                delta = 1
            else:
                delta = -1
            ps.append(num + delta * d)
        ps.sort()
        res = 0
        right = sum(ps)
        for i in xrange(n):
            cur = ps[i]
            right -= cur
            res += right - (n - i - 1) * cur
            res %= MOD
        return res
        
'''
^^^^TEST^^^^
[-2,0,2]
"RLL"
3
----------------
8
$$$$TEST$$$$

^^^^TEST^^^^
[1, 0]
"RL"
2
----------------
5
$$$$TEST$$$$

'''

