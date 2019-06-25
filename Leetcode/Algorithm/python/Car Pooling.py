class Solution(object):
    def carPooling(self, trips, capacity):
        N = 1111
        pre = [0 for i in xrange(N)]
        
        for (c, a, b) in trips:
            pre[a] += c
            pre[b] -= c
        
        c = 0
        for i in xrange(N):
            c += pre[i]
            if c > capacity:
                return False
        return True
