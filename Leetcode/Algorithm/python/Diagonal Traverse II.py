from collections import defaultdict

class Solution(object):
    def findDiagonalOrder(self, nums):
        d = defaultdict(list)
        maxi = 0        
        for i, line in enumerate(nums):
            for j, num in enumerate(line):
                u = i + j
                d[u].append(num)
                maxi = max(maxi, u)
        res = []
        for i in xrange(maxi + 1):
            res += d[i][::-1]
        return res
            
