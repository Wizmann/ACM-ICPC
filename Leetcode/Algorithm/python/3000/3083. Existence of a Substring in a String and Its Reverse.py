class Solution(object):
    def isSubstringPresent(self, s):
        for i in xrange(len(s) - 1):
            sub = s[i: i + 2]
            if sub in s and sub in s[::-1]:
                return True
        return False
