INF = 10 ** 10

class Solution(object):
    def numberOfWeakCharacters(self, properties):
        n = len(properties)
        cnt = 0
        properties.sort(key=lambda (a, b): (a, -b))
        
        maxi = -INF
        for i in xrange(n - 1, -1, -1):
            a, b = properties[i]
            if b < maxi:
                cnt += 1
            maxi = max(b, maxi)
        return cnt
