class Solution(object):
    def findNthDigit(self, n):
        di = 1
        while True:
            s = (10 ** (di - 1)) * 9 * di
            if s < n:
                n -= s
                di += 1
            else:
                break
        s0 = n / di
        s1 = n % di
        s2 = (10 ** (di - 1)) + s0 - 1
        
        if s1 == 0:
            return int(str(s2)[-1])
        else:
            return int(str(s2 + 1)[s1 - 1])
