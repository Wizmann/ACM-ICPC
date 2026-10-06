class Solution(object):
    def repeatedSubstringPattern(self, str):
        if not str:
            return False
        kmp_next = self.get_kmp_next(str)
        n = len(str)
        g = kmp_next[-1]
        return g != 0 and n % (n - g) == 0
    
    def get_kmp_next(self, str):
        n = len(str)
        next = [-1 for i in xrange(n + 1)]
        
        pre, suf = -1, 0
        while pre < n and suf < n:
            if pre == -1 or str[pre] == str[suf]:
                pre += 1
                suf += 1
                next[suf] = pre
            else:
                pre = next[pre]
        return next
        
