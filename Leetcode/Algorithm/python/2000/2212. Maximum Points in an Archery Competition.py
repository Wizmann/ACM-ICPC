INF = 10 ** 10

class Solution(object):
    def maximumBobPoints(self, numArrows, aliceArrows):
        n = len(aliceArrows)
        res = []
        maxi = -INF
        for i in xrange(1 << n):
            bobArrows = [0 for j in xrange(n)]
            score = 0
            for j in xrange(n):
                if i & (1 << j):
                    bobArrows[j] = aliceArrows[j] + 1
                    score += j
            if sum(bobArrows) > numArrows:
                continue
            # print score, bobArrows
            if score > maxi:
                maxi = score
                res = bobArrows[:]
        if sum(res) < numArrows:
            delta = numArrows - sum(res)
            res[0] += delta
        return res
