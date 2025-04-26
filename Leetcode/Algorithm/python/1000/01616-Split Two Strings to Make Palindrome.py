MOD = 0xdeadbeefcafebabe

class Solution(object):
    def checkPalindromeFormation(self, a, b):
        return self.solve(a, b) \
                or self.solve(b, a) \
                or self.solve(a[::-1], b[::-1]) \
                or self.solve(b[::-1], a[::-1])
    
    def solve(self, a, b):
        n = len(a)
        if n == 1:
            return True
        assert len(a) == len(b)
        
        p, q = 0, n - 1
        jump = 0
        while p < q:
            print p, q, jump
            if jump == 0:
                if a[p] == b[q]:
                    p += 1
                    q -= 1
                else:
                    jump = 1
            else:
                if b[p] == b[q]:
                    p += 1
                    q -= 1
                else:
                    return False
        return True
