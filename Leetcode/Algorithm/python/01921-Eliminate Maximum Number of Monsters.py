class Solution(object):
    def eliminateMaximum(self, dist, speed):
        n = len(dist)
        t = [-1 for i in xrange(n)]
        for i in xrange(n):
            t[i] = (dist[i] + speed[i] - 1) / speed[i]
        t.sort()
        cnt = 0
        for i in xrange(n):
            if i < t[i]:
                cnt += 1
            else:
                break
        return cnt
        
