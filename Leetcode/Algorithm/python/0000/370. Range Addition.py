class Solution(object):
    def getModifiedArray(self, length, updates):
        u = [0 for i in xrange(length)]
        for (a, b, c) in updates:
            u[b] += c
            if a - 1 >= 0:
                u[a - 1] -= c
        cur = 0
        for i in xrange(length - 1, -1, -1):
            cur += u[i]
            u[i] = cur
        return u
        
