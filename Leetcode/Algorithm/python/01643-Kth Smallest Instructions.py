def C(n, m):
    if n == 0:
        return 0
    res = 1
    for i in xrange(m):
        res = res * (n - i) / (i + 1)
    return res

class Solution(object):
    def kthSmallestPath(self, destination, k):
        n, m = destination 
        res = [0 for i in xrange(n + m)]
        
        p = 0
        for i in xrange(n):
            while p < n + m:
                tot = C(n + m - p - 1, n - i)
                if tot + 1 > k:
                    p += 1
                else:
                    k -= tot 
                    res[p] = 1
                    p += 1
                    break
        return ''.join(map(lambda x: 'HV'[x], res))
