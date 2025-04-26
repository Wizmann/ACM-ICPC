from collections import defaultdict

INF = 10 ** 10

class Solution(object):
    def maxScore(self, grid):
        n = len(grid)
        nums = defaultdict(list)
        for i, line in enumerate(grid):
            for num in line:
                nums[num].append(i)
                
        maxi = [-INF for i in xrange(1 << n)]
        maxi[0] = 0

        for i in xrange(100, 0, -1):
            nxt = maxi[:]
            for pos in nums[i]:
                for pre in xrange(1 << n):
                    if pre & (1 << pos):
                        continue
                    nxt[pre | (1 << pos)] = max(nxt[pre | (1 << pos)], maxi[pre] + i)
            maxi = nxt
        return max(maxi)
