INF = 10 ** 10

class Solution(object):
    def findLongestChain(self, pairs):
        pre, cnt = -INF, 0
        for pair in sorted(pairs, key=lambda x: x[1]):
            (l, r) = pair
            if l > pre:
                pre = r
                cnt += 1
        return cnt
        
