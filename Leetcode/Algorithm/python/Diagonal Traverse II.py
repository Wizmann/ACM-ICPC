from collections import defaultdict

class Solution(object):
    def findDiagonalOrder(self, nums):
        d = defaultdict(list)
        
        for i, line in enumerate(nums):
            for j, num in enumerate(line):
                u = i + j
                d[u].append(num)
        res = []
        for key in sorted(d.keys()):
            res += d[key][::-1]
        return res
