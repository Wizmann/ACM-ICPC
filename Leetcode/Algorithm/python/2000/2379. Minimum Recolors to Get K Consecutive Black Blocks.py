class Solution(object):
    def minimumRecolors(self, blocks, k):
        blocks = map(lambda x : {'W': 0, 'B': 1}[x], blocks)
        cur = sum(blocks[:k])
        res = k - cur
        n = len(blocks)
        for i in xrange(k, n):
            cur -= blocks[i - k]
            cur += blocks[i]
            res = min(res, k - cur)
        return res
