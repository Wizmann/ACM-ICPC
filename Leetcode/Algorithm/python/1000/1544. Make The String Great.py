class Solution(object):
    def makeGood(self, s):
        s = list(s)
        while True:
            (flag, s) = self.check_and_remove(s)
            if flag:
                break
        return ''.join(s)
    
    def check_and_remove(self, s):
        n = len(s)
        for i in xrange(n - 1):
            if s[i] != s[i + 1] and s[i].lower() == s[i + 1].lower():
                s = s[:i] + s[i + 2:]
                return False, s
        return True, s
