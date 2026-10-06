class Solution(object):
    def secondsToRemoveOccurrences(self, s):
        s = map(int, s)
        n = len(s)
        step = 0
        while True:
            s2 = s[:]
            for i in xrange(1, n):
                if s[i - 1] == 0 and s[i] == 1:
                    s2[i - 1] = 1
                    s2[i] = 0
                else:
                    s2[i] = s[i]
            if s == s2:
                break
            s = s2
            step += 1
            # print s
        return step
