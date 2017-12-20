from collections import defaultdict

class WordFilter(object):

    def __init__(self, words):
        self.words = words
        self.d = {}
        
        for nr, word in enumerate(words):
            n = len(word)
            for i in xrange(n + 1):
                for j in xrange(n + 1):
                    a, b = self.get_hash(word[:i]), self.get_hash(word[j:])
                    self.d[(a, b)] = nr
                    
    def f(self, prefix, suffix):
        a, b = self.get_hash(prefix), self.get_hash(suffix)
        if (a, b) not in self.d:
            return -1
        else:
            return self.d[(a, b)]

    def get_hash(self, substr):
        res = 0
        for c in substr:
            res = (res * 29) + (ord(c) - ord('a') + 1)
            res %= 0xdeadbeef
        return res
        
