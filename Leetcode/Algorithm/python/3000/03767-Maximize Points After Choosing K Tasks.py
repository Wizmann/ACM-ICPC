class Solution(object):
    def maxPoints(self, tech1, tech2, k):
        n = len(tech1)
        tot = sum(tech1)
        for i in xrange(n):
            tech1[i] = tech2[i] - tech1[i]
        tech1.sort(reverse=True)
        # print tech1
        for i in xrange(n - k):
            if tech1[i] < 0:
                break
            tot += tech1[i]
        return tot
