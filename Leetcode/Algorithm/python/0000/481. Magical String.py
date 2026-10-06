class Solution(object):
    def magicalString(self, n):
        s = '122'
        p = 2
        cur = 1
        while len(s) <= n:
            x = str(cur) * int(s[p])
            s += x
            p += 1
            cur = 1 if cur == 2 else 2
        #print s
        return s[:n].count('1')
        
assert Solution().magicalString(6) == 3

s = '1221121221221121122'
for i in xrange(len(s)):
    assert Solution().magicalString(i + 1) == s[:i + 1].count('1')
