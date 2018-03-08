from itertools import groupby

class Solution(object):
    def wordsAbbreviation(self, dict):
        gf = lambda w: (len(w), w[0], w[-1])
        words = sorted(dict, key=gf)
        d = {}
        n = len(words)
        for (key, value) in groupby(words, gf):
            value = list(value)
            m = len(value)
            value.sort()
            for i in xrange(m):
                pre = '' if i - 1 < 0 else value[i - 1]
                next = '' if i + 1 >= m else value[i + 1]
                word = value[i]
                
                p = max(1, self.get_prefix(pre, word) + 1, self.get_prefix(next, word) + 1)
                
                if p + 2 >= len(word):
                    d[word] = word
                else:
                    d[word] = word[:p] + str(len(word) - p - 1) + word[-1]
        return map(lambda w: d[w], dict)
    
    def get_prefix(self, a, b):
        n = min(len(a), len(b))
        for i in xrange(n):
            if a[i] != b[i]:
                return i
        else:
            return n
