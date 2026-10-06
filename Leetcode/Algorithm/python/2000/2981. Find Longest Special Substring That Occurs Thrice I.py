from collections import defaultdict

class Solution(object):
    def maximumLength(self, s):
        n = len(s)
        for i in xrange(n, 0, -1):
            d = defaultdict(int)
            for j in xrange(n - i + 1):
                sub = s[j: j + i]
                if len(set(sub)) != 1:
                    continue
                d[sub] += 1
                if d[sub] >= 3:
                    print sub
                    return i
        return -1
