class Solution(object):
    def validPalindrome(self, s):
        n = len(s)
        return self.solve(s, 0, n - 1, True)
    
    def solve(self, s, l, r, flag):
        while l <= r and s[l] == s[r]:
            l += 1
            r -= 1
        
        if l > r:
            return True
        if not flag:
            return False
        return self.solve(s, l + 1, r, False) or self.solve(s, l, r - 1, False)
        
        
