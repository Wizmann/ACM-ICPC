import re

class Solution(object):
    def camelMatch(self, queries, pattern):
        res = []
        for query in queries:
            res.append(self.isMatch(pattern, query))
        return res
    
    def isMatch(self, needle, haystack):
        n = len(needle)
        m = len(haystack)
        i, j = 0, 0
        while i < n or j < m:
            a = '' if i >= n else needle[i]
            b = '' if j >= m else haystack[j]
            
            if not a:
                if b.isupper():
                    return False
                else:
                    j += 1
            elif a.isupper():
                if not b:
                    return False
                elif b.islower():
                    j += 1
                elif b.isupper() and a == b:
                    i += 1
                    j += 1
                else:
                    return False
            else:
                if not b:
                    return False
                elif a.isupper():
                    return False
                elif a == b:
                    i += 1
                    j += 1
                else:
                    j += 1
        return True
                    
