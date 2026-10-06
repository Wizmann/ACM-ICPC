from collections import Counter

class Solution(object):
    def digitCount(self, num):
        n = len(num)
        num = map(int, num)
        c = Counter(num)
        print c
        for i in xrange(n):
            # print i, c[str(i)], num[i]
            if c[i] != num[i]:
                return False
        return True
