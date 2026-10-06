class Solution(object):
    def makeTheIntegerZero(self, num1, num2):
        for i in xrange(1, 123):
            a = num1 - num2 * i
            if a < 0:
                continue
            cnt = '{:b}'.format(a).count('1')
            # print i, a, cnt
            if cnt <= i <= a:
                return i
        return -1
