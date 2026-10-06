class Solution(object):
    def printVertically(self, s):
        words = s.split()
        m = len(words)
        n = max(map(lambda word: len(word), words))
        res = [ [' ' for j in xrange(m)] for i in xrange(n)]
        
        for j in xrange(m):
            for i in xrange(n):
                word = words[j]
                res[i][j] = ' ' if len(word) <= i else word[i]
        for i in xrange(n):
            res[i] = ''.join(res[i]).rstrip()
        return res
            
