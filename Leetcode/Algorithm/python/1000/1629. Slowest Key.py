class Solution(object):
    def slowestKey(self, releaseTimes, keysPressed):
        res = (-1, 'a')
        n = len(keysPressed)
        pre = 0
        for i in xrange(n):
            delta = releaseTimes[i] - pre
            res = max(res, (delta, keysPressed[i]))
            pre = releaseTimes[i]
        return res[1]
