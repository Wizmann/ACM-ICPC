class Solution(object):
    def reachNumber(self, target):
        if target == 0:
            return 0
        p = 1 if target > 0 else -1
        
        s = 0
        for i in xrange(1, 10 ** 9):
            s += p * i
            delta = abs(target - s)
            if s == target:
                return i
            if abs(s) > abs(target) and delta % 2 == 0:
                return i
