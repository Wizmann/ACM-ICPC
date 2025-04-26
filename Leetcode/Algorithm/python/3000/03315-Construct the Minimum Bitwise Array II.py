import re
class Solution(object):
    def minBitwiseArray(self, nums):
        res = []
        for num in nums:
            if num & 1:
                s = '{:b}'.format(num)
                s = re.split('(0+)', s)
                s[-1] = '0' + s[-1][1:]
                s = ''.join(s)
                print s
                res.append(int(s, 2))
            else:
                res.append(-1)
        return res
