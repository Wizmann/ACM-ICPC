class Solution(object):
    def sumGame(self, num):
        n = len(num)
        a, b = 0, 0
        delta = 0
        for i, c in enumerate(num):
            if c == '?':
                if i < n / 2:
                    a += 1
                else:
                    b += 1
            else:
                if i < n / 2:
                    delta += int(c)
                else:
                    delta -= int(c)
                    
        if (a + b) % 2 == 1:
            return True
        
        res = False
        if a:
            res |= self.solve(a - 1, b, delta + 9)
            res |= self.solve(a - 1, b, delta)
        if b:
            res |= self.solve(a, b - 1, delta - 9)
            res |= self.solve(a, b - 1, delta)
        if not a and not b:
            res = (delta != 0)
        return res
    
    # bob move first, alice mirrors bob's move until a = 0 or b = 0
    def solve(self, a, b, delta):
        a, b = a - min(a, b), b - min(a, b)
        # print a, b, delta
        if a and delta > 0:
            return True
        if b and delta < 0:
            return True
        c = max(a, b)
        assert c % 2 == 1
        delta = abs(delta)
        # print delta, c
        for i in xrange(10):
            d = delta - i
            if d == c / 2 * 9:
                return False
        return True
