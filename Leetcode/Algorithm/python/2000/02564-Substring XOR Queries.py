class Solution(object):
    def substringXorQueries(self, s, queries):
        d = {}
        n = len(s)
        s += '0'
        for i in xrange(1, min(n, 64) + 1):
            cur = 0
            for j in xrange(i):
                cur = cur * 2 + int(s[j])

            for j in xrange(i, n + 1):
                if cur not in d:
                    d[cur] = (j - i, j - 1)
                cur = ((cur * 2) & ((1 << i) - 1)) + int(s[j])
            
        res = []
        for (a, b) in queries:
            c = a ^ b
            res.append(d.get(c, (-1, -1)))
        return res
                                        
