class Solution(object):
    def findAndReplacePattern(self, words, pattern):
        return [word for word in words if self.match(pattern, word)]
    
    def match(self, pattern, word):
        assert len(pattern) == len(word)
        
        d = {}
        rd = {}
        for (a, b) in zip(pattern, word):
            if a not in d and b not in rd:
                d[a] = b
                rd[b] = a
            elif d.get(a, None) != b or rd.get(b, None) != a:
                return False
        return True
