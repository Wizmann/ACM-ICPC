from collections import defaultdict

class Solution(object):
    def findDiagonalOrder(self, nums):
        d = defaultdict(list)
        
        for i, line in enumerate(nums):
            for j, num in enumerate(line):
                u = i + j
                d[u].append((j, num))
        res = []
        for key in sorted(d.keys()):
            res += map(lambda (a, b): b, sorted(d[key]))
        return res
