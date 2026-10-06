from collections import defaultdict

class Solution(object):
    def wonderfulSubstrings(self, word):
        n = len(word)
        d = defaultdict(int)
        d[0] += 1
        pre = 0
        res = 0
        for i in xrange(n - 1, -1, -1):
            cur = ord(word[i]) - ord('a')
            pre ^= 1 << cur
            for j in xrange(10):
                u = 1 << j
                res += d[pre ^ u]
            res += d[pre]
            d[pre] += 1
        return res
            
            
