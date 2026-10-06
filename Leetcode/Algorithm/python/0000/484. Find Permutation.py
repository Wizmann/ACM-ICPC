class Solution(object):
    def findPermutation(self, s):
        self.p = 1
        n = len(s)
        res = []
        buf = []
        for i in xrange(n + 1):
            if i < n and (not buf or buf[-1] == 'I') and s[i] == 'I':
                buf.append('I')
            elif i < n and s[i] == 'D':
                buf.append('D')
            else:
                if res:
                    buf = buf[1:] 
                res += self.solve(buf)
                if i < n:
                    buf = [s[i]]
        return res
    
    def solve(self, buf):
        d = buf.count('D')
        i = buf.count('I')
        q = self.p + len(buf)
        res = []
        res += range(self.p, self.p + i)
        res += [q]
        res += range(q - 1, self.p + i - 1, -1)
        self.p = q + 1
        return res
    

assert Solution().findPermutation("IDID") == [1, 3, 2, 5, 4]
