class Solution:
    def __init__(self):
        self.next = []
        
    def strStr(self, source, target):
        if target is None or source is None:
            return -1
            
        if not target:
            return 0
            
        if not source:
            return -1
            
        self.get_next(target)
        return self.match(source, target)
        
    def match(self, haystack, needle):
        i, j = 0, 0
        n, m = len(haystack), len(needle)
        while i < n and j < m:
            if j == -1 or haystack[i] == needle[j]:
                i += 1
                j += 1
            else:
                j = self.next[j]
        if j == m:
            return i - m
        return -1
    
    def get_next(self, needle):
        strlen = len(needle)
        self.next = [-1 for i in xrange(strlen + 1)]
        
        pre, suf = -1, 0
        while suf < strlen:
            if pre == -1 or needle[pre] == needle[suf]:
                pre += 1
                suf += 1
                self.next[suf] = pre
            else:
                pre = self.next[pre]
