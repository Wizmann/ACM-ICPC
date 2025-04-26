class Palindrome(object):
    def __init__(self, s, parts):
        self.s = s
        self.parts = parts
    
    def length(self):
        res = 0
        for (l, r) in self.parts:
            res += max(l, r) - min(l, r)
        return res
    
    def to_string(self):
        res = ''
        for (l, r) in self.parts:
            if l <= r:
                res += self.s[l: r]
            else:
                res += self.s[r: l][::-1]
        return res

MOD = 0xdeadbeefcafe
PRIME = 13
    
class Solution(object):
    def shortestPalindrome(self, s):
        n = len(s)
        res = Palindrome(s, [[n, 0], [0, n]])
        l, r = 0, 0
        b = 1
        for i in xrange(n):
            c = ord(s[i]) - ord('a') + 1
            l = (l * PRIME + c) % MOD
            r = (r + b * c) % MOD
            b = (b * PRIME) % MOD
            
            if l == r:
                cur = Palindrome(s, [[n, i + 1], [0, i + 1], [i + 1, n]])
                if cur.length() < res.length():
                    res = cur
        return res.to_string()
        
