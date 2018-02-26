class Solution:
    # @param {int} n an integer
    # @return {tuple[]} a list of tuple(sum, probability)
    def dicesSum(self, n):
        dp = [1] + [0 for i in xrange(n * 6)]
        for i in xrange(n):
            next = [0 for i in xrange(n * 6 + 1)]
            for i in xrange(1, 6 + 1):
                for j, v in enumerate(dp):
                    k = j + i
                    u = v * 1.0 / 6
                    if u:
                        next[k] += u
            dp = next
        return filter(lambda (v, p): p, enumerate(dp))
