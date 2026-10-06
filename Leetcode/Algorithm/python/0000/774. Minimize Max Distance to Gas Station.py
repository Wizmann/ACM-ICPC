eps = 1e-7

class Solution(object):
    def minmaxGasDist(self, stations, K):
        l, r = 0, 1e8
        n = len(stations)
        while r - l > eps:
            m = (l + r) / 2
            kk = 0
            for i in xrange(n - 1):
                d = stations[i + 1] - stations[i]
                u = int(d / m)
                if d - u * m < eps:
                    u -= 1
                kk += u
            #print m, kk
            if kk > K:
                l = m
            else:
                r = m
        return l
            
        
