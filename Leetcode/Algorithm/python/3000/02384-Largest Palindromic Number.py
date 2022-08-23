from collections import defaultdict

class Solution(object):
    def largestPalindromic(self, num):
        d = defaultdict(int)
        for c in num:
            c = int(c)
            d[c] += 1
        nums = []
        for key, value in d.items():
            nums += [key] * (value / 2)
            d[key] -= (value / 2) * 2
        if set(nums) == set([0]):
            nums = []
        nums.sort(reverse = True)
        
        mid = -1
        for i in xrange(9, -1, -1):
            if d[i]:
                mid = i
                break
        res = ''
        if mid == -1:
            res = ''.join(map(str, nums + nums[::-1]))
        else:
            res = ''.join(map(str, nums + [mid] + nums[::-1]))
        
        if not res:
            res = '0'
        return res
